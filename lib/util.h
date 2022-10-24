#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <type_traits>

using namespace std;

// Print functionalities

class IPrintable {
public:
	virtual void print() = 0;
};

template <typename T>
concept Printable = requires(const T& var) {
	var->print();
};

template <typename T>
inline void print_container(const T&, string type);

template <typename T>
inline void print(const unordered_map<string, T> &map) { print_map(map); }

template <typename T>
inline void print(const vector<T> &vec) { print_container(vec, "arr"); }

template <typename T>
inline void print(const set<T> &set) { print_container(set, "set"); }

template <Printable T>
inline void print(const T &var) {
	cout << *var;
}

template <typename T>
inline void print(const T &var) {
	cout << var;
}

inline void printnl() { cout << endl; }

template <typename T>
inline void p(const T &var) { print(var); printnl(); }

template <typename T>
inline void print_container(const T &vec, string type) {
	if (type == "arr"){
		cout << "[";	
	}else{
		cout << "<";
	}
	bool isFirst = true;
	for (const auto v: vec) {
		if (isFirst) isFirst = false;
		else cout << ",";
		print(v);
	}
	if (type == "arr"){
		cout << "]";
	}else{
		cout << ">";
	}
};

template <typename T>
inline void print_map(const T &map) {
	cout << "[";
	bool isFirst = true;
	for (auto const& [key, val]: map) {
		if (isFirst) isFirst = false;
		else cout << ",";
		print(key);
		print(":");
		print(val);
	}
	cout << "]";
};

// Vector operations

namespace algo {
	namespace vec {
		template <typename T>
		vector<string> keys(unordered_map<string, T> map) {
			vector<string> vec;

			for (const auto& [key, val]: map) {
				vec.push_back(key);
			}

			return vec;
		}

		template <typename T>
		vector<T> vec_union(vector<T> v1, vector<T> v2) {
			if (v1.size() == 0) return v2;
			if (v2.size() == 0) return v1;

			vector<T> res;

			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());

			set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));

			return res;
		}

		template <typename T>
		vector<T> vec_intersect(vector<T> v1, vector<T> v2) {
			if (v1.size() == 0 || v2.size() == 0) return {};

			vector<T> res;

			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());

			set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));

			return res;
		}

		template <typename T>
		vector<T> vec_substract(vector<T> v1, vector<T> v2) {
			if (v2.size() == 0) return v1;
			if (v1.size() == 0) return {};

			vector<T> res;

			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());

			set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));

			return res;
		}
	}
}

#endif