#include "trie.h"

#include <vector>
#include <print>

int Trie::tr_[N_][M_];
bool Trie::is_end_[N_];

Trie::Trie() {
	clear();
}

void Trie::clear() {
	tot_ = 0;
	clear_node(0);
}

void Trie::insert(const std::string& word) {
	int pos = 0;

	for (char ch : word) {
		int c = ch - 'a';

		if (tr_[pos][c] == 0) {
			tr_[pos][c] = ++tot_;
			clear_node(tot_);
		}

		pos = tr_[pos][c];
	}

	is_end_[pos] = true;
}

bool Trie::search(const std::string& word) {
	int pos = 0;

	for (char ch : word) {
		int c = ch - 'a';

		if (tr_[pos][c] == 0) return false;
		
		pos = tr_[pos][c];
	}

	return is_end_[pos]; // We might have a superset of the characters (cart was inserted but we're searching for car)
}

bool Trie::startsWith(const std::string& prefix) {
	int pos = 0;

	for (char ch : prefix) {
		int c = ch - 'a';

		if (tr_[pos][c] == 0) return false;

		pos = tr_[pos][c];
	}

	return true;
}

//
// Private Methods
// 

inline void Trie::clear_node(int u) {
	for (int i = 0; i < M_; i++) tr_[u][i] = 0;
	is_end_[u] = false;
}

int main() {
	Trie trie;

	std::vector<std::string> words = {"apple", "app", "apricot", "banana", "bat"};
	for (const std::string& word : words) trie.insert(word);

	std::vector<std::string> searches = {"apple", "app", "appl", "banana", "batman"};
	for (const std::string& search : searches) {
		std::println("Search \"{}\": {}", search, (trie.search(search) ? "Found" : "Not found"));
	}
	std::println("");

	std::vector<std::string> prefixes = {"ap", "app", "ban", "cat"};
	for (const std::string& prefix : prefixes) {
		std::println("Prefix \"{}\": {}", prefix, (trie.startsWith(prefix) ? "Exists" : "Doesn't exist"));
	}
	std::println("");

	return 0;
}
