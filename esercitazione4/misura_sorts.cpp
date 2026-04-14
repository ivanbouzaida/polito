#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "sorts.h"
#include "timecounter.h"
#include "randfiller.h"

int main()
{
    randfiller rf;

    std::cout << "n bubble_sort insertion_sort selection_sort std_sort\n";

    for (int n = 4; n <= 8192; n *= 2) {
        std::vector<int> base(n);
        rf.fill(base, -100000, 100000);

        std::vector<int> v_bubble = base;
        std::vector<int> v_insertion = base;
        std::vector<int> v_selection = base;
        std::vector<int> v_std = base;

        timecounter tc;

        tc.tic();
        bubble_sort(v_bubble);
        double t_bubble = tc.toc();

        tc.tic();
        insertion_sort(v_insertion);
        double t_insertion = tc.toc();

        tc.tic();
        selection_sort(v_selection);
        double t_selection = tc.toc();

        tc.tic();
        std::sort(v_std.begin(), v_std.end());
        double t_std = tc.toc();

        std::cout << n << " "
                  << t_bubble << " "
                  << t_insertion << " "
                  << t_selection << " "
                  << t_std << "\n";
    }

    return EXIT_SUCCESS;
}