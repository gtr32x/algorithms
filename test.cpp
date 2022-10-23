#include "util.h"
#include "kmp.cpp"

void test_kmp() {
	p("Algorithm KMP: ");
	p("-----------------------");
	vector<int> res = KMP("AAAABAAAA", "AAAA");
	print("Result: ");
	p(res);
}

void test() {
	test_kmp();
}