#include "../lib/util.h"
#include "../lib/graph.h"

void bron_kerbosch_inner(vector<string> r, vector<string> p, vector<string> x, vector<vector<string>> &ans, unordered_map<string, Node *> &nodes);

vector<vector<string>> bron_kerbosch(vector<vector<int>> graph) {
	unordered_map<string, Node *> nodes;

	// Constructing a map of nodes each containing their own neighbors
	for (auto &edge: graph) {
		string v1 = to_string(edge[0]);
		string v2 = to_string(edge[1]);

		if (!nodes.count(v1)) {
			nodes[v1] = new Node(v1);
		}

		if (!nodes.count(v2)) {
			nodes[v2] = new Node(v2);
		}

		nodes[v1]->addNeighbor(nodes[v2]);
		nodes[v2]->addNeighbor(nodes[v1]);
	}

	// Initialize the vector of vertices to search through as all vertices in the graph
	vector<string> P = algo::vec::keys(nodes);
	vector<vector<string>> ans;

	// This is the recursive function to continuous look for complete neighborhoods within the graph
	bron_kerbosch_inner({}, P, {}, ans, nodes);

	return ans;
}

void bron_kerbosch_inner(vector<string> R, vector<string> P, vector<string> X, vector<vector<string>> &ans, unordered_map<string, Node *> &nodes) {
	if (!P.size() && !X.size()) {
		ans.push_back(R);
		return;
	}

	if (!P.size()) {
		return;
	}

	// Selecting a pivot can help reduce the number of vertices to loop through, the heuristic for pivot here is such that
	// only the pivot and its non-neighbors needed to be tested each time
	auto list = algo::vec::vec_substract(P, nodes[P[0]]->getNeighborTags());

	for (const auto& v: list) {
		// Consider R to be the temporary clique that's currently being constructed
		auto RUV = algo::vec::vec_union(R, {v});

		// Consider P to the the remaining set of vertices that's still possible to be within our current maximal clique
		auto PIN = algo::vec::vec_intersect(P, nodes[v]->getNeighborTags());

		// Consider X to be the vertices that have been visited, thus any clique built using it would have already been found, this acts as an exclusion list
		auto XIN = algo::vec::vec_intersect(X, nodes[v]->getNeighborTags());

		bron_kerbosch_inner(RUV, PIN, XIN, ans, nodes);

		// We want P to ignore v in future searches because any maximal cliques containing v have already been found
		remove(P.begin(), P.end(), v);

		// Add v to X because v has already been searched, it should be excluded from future search
		X = algo::vec::vec_union(X, {v});
	}
}