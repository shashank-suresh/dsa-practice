#ifndef TRIE_H
#define TRIE_H

#include <cstring>
#include <string>

class Trie {
public:
	Trie();

	void clear();
	void insert(const std::string& word);
	bool search(const std::string& word);
	bool startsWith(const std::string& prefix);

private:
	static constexpr int N_ = 100; // Maximum nodes across operations
	static constexpr int M_ = 26; // M_ is 26 because we are only considering letters a-z
	int tot_;

	static int tr_[N_][M_];
	static bool is_end_[N_];

	inline void clear_node(int u);
};

#endif

