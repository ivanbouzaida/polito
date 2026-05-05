#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "sorts.h"
#include "timecounter.h"
#include "randfiller.h"

int main()
{
    randfiller rf;
    timecounter tc;

    const int numero_vettori = 100;
	
    std::cout << std::left
			  << std::setw(8)  << "n"
			  << std::setw(16) << "bubble"
			  << std::setw(16) << "insertion"
			  << std::setw(16) << "selection"
			  << std::setw(16) << "merge"
			  << std::setw(16) << "quick"
			  << std::setw(16) << "std::sort"
			  << std::setw(18) << "migliore prima"
			  << std::setw(20) << "quicksort mod"
			  << std::setw(18) << "migliore dopo"
			  << "\n";

	std::cout << std::string(158, '-') << "\n";
	
    for (int n = 4; n <= 512; n *= 2) {
        std::vector<std::vector<int>> basi;

        for (int i = 0; i < numero_vettori; ++i) {
            std::vector<int> base(n);
            rf.fill(base, -100000, 100000);
            basi.push_back(base);
        }
		
		//bubble
        std::vector<std::vector<int>> v_bubble = basi;

        tc.tic();

        for (auto& v : v_bubble) {
            bubble_sort(v);
        }

        double t_bubble = tc.toc() / numero_vettori;
		
		//insertion
        std::vector<std::vector<int>> v_insertion = basi;
        tc.tic();
        for (auto& v : v_insertion) {
            insertion_sort(v);
        }
        double t_insertion = tc.toc() / numero_vettori;

		//selection
        std::vector<std::vector<int>> v_selection = basi;
        tc.tic();
        for (auto& v : v_selection) {
            selection_sort(v);
        }
        double t_selection = tc.toc() / numero_vettori;
		
		//merge
        std::vector<std::vector<int>> v_merge = basi;
        tc.tic();
        for (auto& v : v_merge) {
            merge_sort(v);
        }
        double t_merge = tc.toc() / numero_vettori;
		
		//quick
        std::vector<std::vector<int>> v_quick = basi;
        tc.tic();
        for (auto& v : v_quick) {
            quick_sort(v);
        }
        double t_quick = tc.toc() / numero_vettori;
		
		//c-sort
        std::vector<std::vector<int>> v_std = basi;
        tc.tic();
        for (auto& v : v_std) {
            std::sort(v.begin(), v.end());
        }
		double t_std = tc.toc() / numero_vettori;
		
		//quick modificato
		std::vector<std::vector<int>> v_quick_mod = basi;
        tc.tic();
        for (auto& v : v_quick_mod) {
            quick_sort_modified(v);
        }
		double t_quick_mod = tc.toc() / numero_vettori;
        
			
		//qual è il migliore sort (prima di quick_mod)
		std::string best_sort = "bubble_sort";
		double best_time = t_bubble;

		if (t_insertion < best_time) {
			best_time = t_insertion;
			best_sort = "insertion_sort";
		}

		if (t_selection < best_time) {
			best_time = t_selection;
			best_sort = "selection_sort";
		}

		if (t_merge < best_time) {
			best_time = t_merge;
			best_sort = "merge_sort";
		}

		if (t_quick < best_time) {
			best_time = t_quick;
			best_sort = "quick_sort";
		}

		if (t_std < best_time) {
			best_time = t_std;
			best_sort = "std_sort";
		}
		
		//confronto con il mio nuovo sort
		std::string best_sort_after = best_sort;
		if (t_quick_mod <= best_time) {
			best_sort_after = "quick_modified";
		}
        std::cout << std::left
				  << std::setw(8)  << n
				  << std::setw(16) << t_bubble
				  << std::setw(16) << t_insertion
				  << std::setw(16) << t_selection
				  << std::setw(16) << t_merge
				  << std::setw(16) << t_quick
				  << std::setw(16) << t_std
				  << std::setw(18) << best_sort
				  << std::setw(20) << t_quick_mod
				  << std::setw(18) << best_sort_after
				  << "\n";
			  
	}

    return EXIT_SUCCESS;
}