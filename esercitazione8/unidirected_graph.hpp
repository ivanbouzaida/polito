#ifndef UNIDIRECTED_GRAPH_HPP
#define UNIDIRECTED_GRAPH_HPP

#include "unidirected_edge.hpp"

#include <map>
#include <set>
#include <vector>
#include <iostream>

class unidirected_graph {
private:
    // Per ogni nodo salvo l'insieme dei suoi vicini.
    std::map<int, std::set<int>> adjacency_;

    // Insieme di tutti gli archi del grafo.
    std::set<unidirected_edge> edges_;

    // Mappa arco -> numero dell'arco.
    std::map<unidirected_edge, int> edge_to_number_;

    // Vettore numero -> arco.
    std::vector<unidirected_edge> number_to_edge_;

public:
    // Costruttore di default.
    unidirected_graph();

    // Costruttore di copia.
    unidirected_graph(const unidirected_graph& other);

    // Restituisce i vicini di un nodo.
    std::set<int> neighbours(int node) const;

    // Aggiunge un arco al grafo.
    void add_edge(const unidirected_edge& edge);

    // Aggiunge un arco al grafo dati direttamente i due nodi.
    void add_edge(int a, int b);

    // Restituisce tutti gli archi.
    std::set<unidirected_edge> all_edges() const;

    // Restituisce tutti i nodi.
    std::set<int> all_nodes() const;

    // Restituisce il numero associato a un arco.
    int edge_number(const unidirected_edge& edge) const;

    // Restituisce l'arco dato il suo numero.
    unidirected_edge edge_at(int number) const;

    // Restituisce il numero di archi del grafo.
    int size() const;

    // Differenza tra grafi: G - G'
    unidirected_graph operator-(const unidirected_graph& other) const;
};

std::ostream& operator<<(std::ostream& os, const unidirected_graph& g);

#endif