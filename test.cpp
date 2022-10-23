#include "util.h"
#include "kmp.cpp"

void test() {
	int res = kmp("I am a string");
	p(res);
	p("ala");
}