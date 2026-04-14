#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <utility>   // std::swap

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size() == 0) {
        return true;
    }

    for (std::size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }

    return true;
}

template<typename T>
void bubble_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (std::size_t i = 0; i < vec.size() - 1; ++i) {
        for (std::size_t j = vec.size() - 1; j > i; --j) {
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    for (std::size_t j = 1; j < vec.size(); ++j) {
        T key = vec[j];
        std::size_t i = j;

        while (i > 0 && key < vec[i - 1]) {
            vec[i] = vec[i - 1];
            --i;
        }

        vec[i] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (std::size_t i = 0; i < vec.size() - 1; ++i) {
        std::size_t min_index = i;

        for (std::size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        std::swap(vec[i], vec[min_index]);
    }
}

#endif