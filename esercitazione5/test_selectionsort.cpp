#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "sorts.h"
#include "randfiller.h"

int main()
{
    randfiller rf;

    for (int test = 0; test < 100; ++test) {
        int n = test;
        std::vector<int> v(n);

        rf.fill(v, -1000, 1000);

        selection_sort(v);

        if (!is_sorted(v)) {
            std::cerr << "Errore: selection_sort ha fallito su int\n";
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> words = {
        "pera", "mela", "banana", "kiwi", "zebra",
        "anatra", "cane", "gatto", "sole", "luna"
    };

    selection_sort(words);

    if (!is_sorted(words)) {
        std::cerr << "Errore: selection_sort ha fallito su stringhe\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}