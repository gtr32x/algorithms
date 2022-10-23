#include "util.h"
#include "kmp.cpp"

void test_kmp() {
	p("Algorithm KMP: ");
	p("-----------------------");
	int res = KMP("I am a stringg", "AAABAAA");
	print("Result: ");
	p(res);
}

void test() {
	test_kmp();
}