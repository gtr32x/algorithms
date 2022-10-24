# Algorithms

## Dijkstra

Greedy search for shortest path from source to destination

## Bron-Kerbosch

Recursive backtracking for finding maximal cliques in an undirected graph

### Approach

Construct three disjoint sets:

R - the temporary resulting set of vertices in a maximal clique

P - the set of all vertices to search

X - the set of all vertices to not search

During the search, iteratively walk through each vertex and its neighbors until a common set of vertices are found where they are all neighbors of each other, thus a clique.

## Knuth–Morris–Pratt (KMP)

Search algorithm to find matches of a pattern in a string

### Approach

Construct a longest-prefix-suffix (lps) array via the input pattern to perform skips during the linear scan of the text.

The idea is that if there are matching prefix and suffix in the pattern, during the linear scan we should be able to skip known matches of the common parts of the prefix and suffix of the pattern.