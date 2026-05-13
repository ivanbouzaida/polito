#include "unidirected_edge.hpp"

#include <algorithm>

unidirected_edge::unidirected_edge(int a, int b) {
    from_ = std::min(a, b);
    to_ = std::max(a, b);
}

int unidirected_edge::from() const {
    return from_;
}

int unidirected_edge::to() const {
    return to_;
}

bool unidirected_edge::operator<(const unidirected_edge& other) const {
    if (from_ != other.from_) {
        return from_ < other.from_;
    }

    return to_ < other.to_;
}

bool unidirected_edge::operator==(const unidirected_edge& other) const {
    return from_ == other.from_ && to_ == other.to_;
}

std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}