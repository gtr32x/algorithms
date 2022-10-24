#include "lib/util.h"
#include "algos/kmp.cpp"
#include "algos/bron_kerbosch.cpp"

void test_KMP() {
	p("Algorithm Knuth–Morris–Pratt: ");
	p("-----------------------");
	auto res = KMP("AAAABAAAA", "AAAA");
	print("Result: ");
	p(res);
}

void test_BK() {
	p("Algorithm Bron-Kerbosch: ");
	p("-----------------------");
	vector<vector<int>> graph {
		{1, 2},
		{2, 3},
		{3, 4},
		{4, 5},
		{5, 2},
		{5, 1},
		{4, 6}
	};
	auto res = bron_kerbosch(graph);
	print("Result: ");
	p(res);
}

void test() {
	// test_KMP();
	test_BK();
}