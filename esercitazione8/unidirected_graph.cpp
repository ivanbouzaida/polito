#include "unidirected_graph.hpp"

#include <stdexcept>

unidirected_graph::unidirected_graph() {}

unidirected_graph::unidirected_graph(const unidirected_graph& other)
    : adjacency_(other.adjacency_),
      edges_(other.edges_),
      edge_to_number_(other.edge_to_number_),
      number_to_edge_(other.number_to_edge_)
{}

std::set<int> unidirected_graph::neighbours(int node) const {
    auto it = adjacency_.find(node);

    if (it == adjacency_.end()) {
        return {};
    }

    return it->second;
}

void unidirected_graph::add_edge(const unidirected_edge& edge) {
    // Se l'arco esiste già, non faccio nulla.
    if (edges_.find(edge) != edges_.end()) {
        return;
    }

    int a = edge.from();
    int b = edge.to();

    // Inserisco l'arco nell'insieme degli archi.
    edges_.insert(edge);

    // Aggiorno la lista dei vicini.
    adjacency_[a].insert(b);
    adjacency_[b].insert(a);

    // Assegno un numero all'arco.
    int number = static_cast<int>(number_to_edge_.size());
    edge_to_number_[edge] = number;
    number_to_edge_.push_back(edge);
}

void unidirected_graph::add_edge(int a, int b) {
    unidirected_edge edge(a, b);
    add_edge(edge);
}

std::set<unidirected_edge> unidirected_graph::all_edges() const {
    return edges_;
}

std::set<int> unidirected_graph::all_nodes() const {
    std::set<int> nodes;

    for (const auto& pair : adjacency_) {
        nodes.insert(pair.first);
    }

    return nodes;
}

int unidirected_graph::edge_number(const unidirected_edge& edge) const {
    auto it = edge_to_number_.find(edge);

    if (it == edge_to_number_.end()) {
        throw std::out_of_range("L'arco richiesto non appartiene al grafo.");
    }

    return it->second;
}

unidirected_edge unidirected_graph::edge_at(int number) const {
    if (number < 0 || number >= static_cast<int>(number_to_edge_.size())) {
        throw std::out_of_range("Numero d'arco non valido.");
    }

    return number_to_edge_[number];
}

int unidirected_graph::size() const {
    return static_cast<int>(edges_.size());
}

unidirected_graph unidirected_graph::operator-(const unidirected_graph& other) const {
    unidirected_graph result;

    for (const auto& edge : edges_) {
        if (other.edges_.find(edge) == other.edges_.end()) {
            result.add_edge(edge);
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const unidirected_graph& g) {
    os << "Archi del grafo: ";

    for (const auto& edge : g.all_edges()) {
        os << edge << " ";
    }

    return os;
}