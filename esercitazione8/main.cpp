#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

#include <cassert>
#include <iostream>
#include <set>


void test_edge_ordering() {
    unidirected_edge e1(5, 2);

    assert(e1.from() == 2);
    assert(e1.to() == 5);

    unidirected_edge e2(2, 5);
    assert(e1 == e2);

    std::cout << "test_edge_ordering passato" << std::endl;
}

void test_add_edge_and_neighbours() {
    unidirected_graph g;

    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    std::set<int> n1 = g.neighbours(1);
    assert(n1.count(2) == 1);
    assert(n1.count(3) == 1);
    assert(n1.size() == 2);

    std::set<int> n2 = g.neighbours(2);
    assert(n2.count(1) == 1);
    assert(n2.count(4) == 1);
    assert(n2.size() == 2);

    std::cout << "test_add_edge_and_neighbours passato" << std::endl;
}

void test_all_edges_and_all_nodes() {
    unidirected_graph g;

    g.add_edge(1, 2);
    g.add_edge(3, 4);
    g.add_edge(2, 3);

    std::set<unidirected_edge> edges = g.all_edges();
    assert(edges.size() == 3);
    assert(edges.count(unidirected_edge(1, 2)) == 1);
    assert(edges.count(unidirected_edge(3, 4)) == 1);
    assert(edges.count(unidirected_edge(2, 3)) == 1);

    std::set<int> nodes = g.all_nodes();
    assert(nodes.size() == 4);
    assert(nodes.count(1) == 1);
    assert(nodes.count(2) == 1);
    assert(nodes.count(3) == 1);
    assert(nodes.count(4) == 1);

    std::cout << "test_all_edges_and_all_nodes passato" << std::endl;
}

void test_duplicate_edges() {
    unidirected_graph g;

    g.add_edge(1, 2);
    g.add_edge(2, 1);
    g.add_edge(1, 2);

    assert(g.size() == 1);

    std::cout << "test_duplicate_edges passato" << std::endl;
}

void test_edge_number_and_edge_at() {
    unidirected_graph g;

    g.add_edge(10, 20);
    g.add_edge(20, 30);
    g.add_edge(30, 40);

    int n = g.edge_number(unidirected_edge(20, 30));
    unidirected_edge e = g.edge_at(n);

    assert(e == unidirected_edge(20, 30));

    std::cout << "test_edge_number_and_edge_at passato" << std::endl;
}

void test_graph_difference() {
    unidirected_graph g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 4);

    unidirected_graph g2;
    g2.add_edge(2, 3);

    unidirected_graph diff = g1 - g2;

    std::set<unidirected_edge> edges = diff.all_edges();

    assert(edges.size() == 2);
    assert(edges.count(unidirected_edge(1, 2)) == 1);
    assert(edges.count(unidirected_edge(3, 4)) == 1);
    assert(edges.count(unidirected_edge(2, 3)) == 0);

    std::cout << "test_graph_difference passato" << std::endl;
}

void test_copy_constructor() {
    unidirected_graph g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);

    unidirected_graph g2(g1);

    assert(g2.size() == 2);
    assert(g2.all_edges().count(unidirected_edge(1, 2)) == 1);
    assert(g2.all_edges().count(unidirected_edge(2, 3)) == 1);

    std::cout << "test_copy_constructor passato" << std::endl;
}

int main() {
    test_edge_ordering();
    test_add_edge_and_neighbours();
    test_all_edges_and_all_nodes();
    test_duplicate_edges();
    test_edge_number_and_edge_at();
    test_graph_difference();
    test_copy_constructor();

    std::cout << std::endl;
    std::cout << "Tutti i test sono passati correttamente." << std::endl;

    unidirected_graph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(3, 4);

    std::cout << g << std::endl;

    return 0;
}