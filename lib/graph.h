#ifndef GRAPH_H
#define GRAPH_H

#include "util.h"

class Node : IPrintable {
public:
	vector<Node *> neighbors;
	string tag;

	Node(string inputTag) {
		tag = inputTag;
	}

	void addNeighbor(Node* node) {
		neighbors.push_back(node);
	}

	vector<string> getNeighborTags() {
		vector<string> res;

		for (const auto& node: neighbors) {
			res.push_back(node->tag);
		}

		return res;
	}

	void printNeighbors() {
		cout << "[";
		bool isFirst = true;
		for (const auto& n: neighbors) {
			if (isFirst) isFirst = false;
			else cout << ",";
			cout << n->tag;
		}
		cout << "]";
	}

	void print() {
		cout << tag << ": ";
		printNeighbors();
		cout << endl;
	}
};

ostream& operator<<(ostream& os, const Node& node) {
	// os << "Node{";
	os << node.tag << "-";
	cout << "[";
		bool isFirst = true;
		for (const auto& n: node.neighbors) {
			if (isFirst) isFirst = false;
			else cout << ",";
			cout << n->tag;
		}
		cout << "]";
	// os << "}";
	return os;
}

#endif