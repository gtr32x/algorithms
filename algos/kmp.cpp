#include "../lib/util.h"

vector<int> constructLPS(string pat) {
	// Initialize lps as an array of size str, this array will hold the search skip information
	vector<int> lps(pat.size());

	// lps[0] is always initialized to 0
	lps[0] = (0);

	// i is used to step forward in the pat array, since lps[0] is always defined, initialize i to 1
	// len is used to step backward in the pat array
	int i = 1, len = 0;

	while (i < pat.size()) {

		// If pattern at len and i are the same, append to lps array
		if (pat[len] == pat[i]) {
			lps[i++] = ++len;
		} else {
			if (len > 0) {
				// If len is above 0, push back one index in the pattern to search for next
				len = lps[--len];
			} else {
				// If len is at 0, we will set lps to 0 and continue our search from here
				lps[i++] = 0;
			}
		}
	}

	return lps;
}

vector<int> KMP(string str, string pat) {
	vector<int> lps = constructLPS(pat);
	vector<int> found;

	// i is used to step forward in the str array
	// j is used to step forward in the pat array
	int i = 0, j = 0;
	bool currentCharMatch = false;

	while (i < str.size()) {
		currentCharMatch = str[i] == pat[j];

		if (currentCharMatch) {
			i++;
			j++;
		}

		// If j reaches the size of pat, then we have found a match
		if (j == pat.size()) {
			found.push_back(i - j);
			// push j back according to our lps array at the last position
			j = lps[j - 1];
		}

		// If we do not have a match on the current character or if we have found a pattern match, then reset j
		if (!currentCharMatch) {
			if (j > 0) {
				// push j back according to our lps array at the last position
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
	
	return found;
}