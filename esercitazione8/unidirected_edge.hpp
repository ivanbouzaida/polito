#ifndef UNIDIRECTED_EDGE_HPP
#define UNIDIRECTED_EDGE_HPP

#include <iostream>

class unidirected_edge {
private:
    int from_;
    int to_;

public:
    // Costruttore: prende due nodi e costruisce l'arco non orientato.
    // Garantisce sempre from_ <= to_.
    unidirected_edge(int a, int b);

    // Restituisce il primo nodo dell'arco.
    int from() const;

    // Restituisce il secondo nodo dell'arco.
    int to() const;

    // Serve per poter ordinare gli archi, ad esempio dentro std::set.
    bool operator<(const unidirected_edge& other) const;

    // Serve per confrontare due archi.
    bool operator==(const unidirected_edge& other) const;
};

std::ostream& operator<<(std::ostream& os, const unidirected_edge& e);

#endif