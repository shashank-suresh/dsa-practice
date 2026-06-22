#include "segment-tree.h"

//
// Private Methods
//
SegmentTree::SegmentTree(const std::vector<int>& arr) {
	n = arr.size();
	tree.assign(4*n, 0); // 4*n because node i would have left child at 2*i and right child at 2*i+1
	build(arr, 1, 0, n - 1);
}

int SegmentTree::query(int l, int r) {
	return query(1, 0, n - 1, l, r);
}

void SegmentTree::update(int index, int val) {
	update(1, 0, n - 1, index, val);
}

//
// Public Methods
//
void SegmentTree::build(const std::vector<int>& arr, int node, int start, int end) {
	if (start == end) tree[node] = arr[start];
	else {
		int mid = start + (end - start) / 2;

		build(arr, 2 * node, start, mid);
		build(arr, 2 * node + 1, mid + 1, end);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

int SegmentTree::query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) return 0; // Outside range
	if (l <= start && end <= r) return tree[node]; // Completely inside range

	int mid = start + (end - start) / 2;

	int leftSum = query(2 * node, start, mid, l, r);
	int rightSum = query(2 * node + 1, mid + 1, end, l, r);

	return leftSum + rightSum;
}

void SegmentTree::update(int node, int start, int end, int idx, int val) {
	if (start == end) tree[node] = val;
	else {
		int mid = start + (end - start) / 2;
		
		if (idx <= mid) update(2 * node, start, mid, idx, val);
		else update(2 * node + 1, mid + 1, end, idx, val);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
