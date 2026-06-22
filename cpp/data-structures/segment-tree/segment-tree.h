#include <vector>

class SegmentTree {
public:
	SegmentTree(const std::vector<int>& arr);

	int query(int l, int r);

	void update(int idx, int val);
private:
	int n;
	std::vector<int> tree;

	/// @brief Builds the segment tree from the array of values
	/// @note The aggregator of this segment tree is the sum operation
	/// @note Time complexity: O(N) as every node is visited once
	/// @note Space complexity: O(N) for the tree itself we allocate 4*n slots (inside the constructor)
	void build(const std::vector<int>& arr, int node, int start, int end);

	/// @brief Retrieves the sum of elements in range [l, r]
	/// @note Time complexity: O(log N) because worst case we keep going down partial nodes down the height of the tree which is ceil(log N)
	/// @note Space complexity: O(log N) because of the call stack going to a depth of the height of the tree which is ceil(log N)
	int query(int node, int start, int end, int l, int r);

	/// @brief Updates the segment tree based on a change (to val) in the array of values (at index)
	/// @note Time complexity: O(log N) because we go down either the left/right subtree (root-to-leaf path)
	/// @note Space complexity: O(log N) because of call stack
	void update(int node, int start, int end, int idx, int val);
};
