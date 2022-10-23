#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_container(const T&);

template <typename T>
void print(const vector<T> &vec) { print_container(vec); }

template <typename T>
void print(const T &var) { cout << var; }

void printnl() { cout << endl; }

template <typename T>
void printl(const T &var) { print(var); printnl(); }

template <typename T>
void p(const T &var) { printl(var); }

template <typename T>
void print_container(const T &vec) {
	cout << "[";
	bool isFirst = true;
	for (const auto& v: vec) {
		if (isFirst) isFirst = false;
		else cout << ",";
		print(v);
	}
	cout << "]";
};

#endif