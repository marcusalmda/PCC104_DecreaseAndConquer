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

void print_permutations(const std::vector<std::vector<int>>& permutations){

	for (std::vector<int> p : permutations) {
		for (int el : p) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}

}

template <typename T> void print_vector(std::vector<T>& v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i << ' ';
	}

	std::cout << std::endl;
}

void test_lexic_permute() {
	std::vector<int> ns({ 2,4,5,6,7,9,10 });
	std::vector<double> time({});


	for (int n : ns) {
		auto start = std::chrono::system_clock::now();
		lexic_permute(n);
		auto finish = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "N = " << n << " : " << elapsed.count() << std::endl;

		time.push_back(elapsed.count());
	}


	matplot::plot(ns, time, "-s")
		->line_width(5)
		.marker_size(10)
		.marker_color("g")
		.marker_face_color({ .5,.5,.5 });

	matplot::show();


}

void print_subsets(const std::vector<std::vector<int>>& power_set) {
	for (size_t i = 0; i < power_set.size(); i++)
	{
		for (size_t j = 0; j < power_set[0].size(); j++)
		{
			if (power_set[i][j] == 1) {
				std::cout << "e" << power_set[0].size()-j << ", ";
			}
		}
		std::cout << std::endl;
	}
	
}

void print_bit_strings(std::vector<std::vector<int>>& power_set) {
	for (size_t i = 0; i < power_set.size(); i++)
	{
		for (size_t j = 0; j < power_set[0].size(); j++)
		{
			std::cout << power_set[i][j] << ", ";
		}
		std::cout << std::endl;
	}

}

std::vector<std::vector<int>> generate_power_set(int n) {
	std::vector<std::vector<int>> power_set;

	if (n == 1) {
		power_set.push_back({ 0 });
		power_set.push_back({ 1 });
	}
	else {
		std::vector<std::vector<int>> L1 = generate_power_set(n - 1);
		std::vector<std::vector<int>> L2 = L1;
		std::reverse(L2.begin(), L2.end());

		for (std::vector<int>& str : L1) {
			str.emplace(str.begin(), 0);
		}

		for (std::vector<int>& str : L2) {
			str.emplace(str.begin(), 1);
		}

		L2.insert(L2.begin(), L1.begin(), L1.end());
		power_set = L2;
	}

	return power_set;

}

void time_experiment() {

	int n_experiments = 100;

	std::vector<int> positions({});
	std::vector<double> time_v({});
	std::vector<double> time_s({});

	int size_ = 100000;

	for (int i = 0; i < n_experiments; i++)
	{

		std::vector<int> v(size_, 0);
		std::set<int> s({ 1,size_ });

		int pos = rand() % (size_);
		positions.push_back(pos);

		auto start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10000; i++)
		{
			v.erase(v.begin() + pos);
		}
		auto finish = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed = finish - start;

		time_v.push_back(elapsed.count());

		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10000; i++)
		{
			s.erase(pos);
		}
		finish = std::chrono::system_clock::now();

		elapsed = finish - start;

		time_s.push_back(elapsed.count());

	}


	matplot::plot(positions, time_v, "o");
	matplot::hold(matplot::on);
	matplot::plot(positions, time_s, "s");
	matplot::show();

}

int main()
{
	//test_lexic_permute();
	
	//std::vector<std::vector<int>> power_set = generate_power_set(4);

	//print_bit_strings(power_set);

	//print_subsets(power_set);

	srand((unsigned int)time(0));

	time_experiment();

	return 0;
}
