// PCC104_DeacreaseAndConquer_Maplotpp.cpp : Defines the entry point for the application.
//

#include "PCC104_DeacreaseAndConquer_Maplotpp.h"


std::vector<std::vector<int>> lexic_permute(int n) {

	std::vector<std::vector<int>> permutations;
	std::vector<int> permutation;

	for (int i = 0; i < n; i++) {
		permutation.push_back(i);
	}

	permutations.push_back(permutation);

	bool decreasing_order = false;

	do {
		int i = -1;

		for (int k = 0; k < n - 1; k++)
		{
			if (permutation[k] < permutation[k + 1]) {
				i = k;
			}
		}

		decreasing_order = (i == -1);

		if (!decreasing_order) {
			int j = i;

			for (int k = i; k < n; k++)
			{
				if (permutation[i] < permutation[k]) {
					j = k;
				}
			}

			std::swap(permutation[i], permutation[j]);

			std::reverse(permutation.begin() + (i + 1), permutation.end());

			permutations.push_back(permutation);
		}

	} while (! decreasing_order);

	return permutations;

}

void print_permutations(std::vector<std::vector<int>>& permutations){

	for (std::vector<int> p : permutations) {
		for (int el : p) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}

}

int main()
{

	std::vector<int> ns({ 2,4,5,6,7,9,10});
	std::vector<double> time({});


	for (int n : ns) {
		auto start = std::chrono::system_clock::now();
		lexic_permute(n);
		auto finish= std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "N = " << n << " : " << elapsed.count() << std::endl;

		time.push_back(elapsed.count());
	}
	

	matplot::plot(ns,time, "-s")
		->line_width(5)
		.marker_size(10)
		.marker_color("g")
		.marker_face_color({.5,.5,.5});

	matplot::show();

	return 0;
}
