class SegmentTree {
public:
    SegmentTree(int _n) : n(_n) {
        tree.resize(n * 4, 0);
    }

    void update(int index, int val) {
        update(index, val, 0, n - 1, 0);
    }

    int query(int x, int y) {
        return query(x, y, 0, n - 1, 0);
    }

    void printTree() {
        for (int i : tree) {
            cout << i << " ";
        }
        cout << endl;
    }
private:
    int n;
    vector<int> tree;

    void update(int index, int val, int left, int right, int pos) {
        if (left == right) {
            tree[pos] = val;
            return;
        }
        int middle = (left + right) / 2;
        if (middle >= index) {
            update(index, val, left, middle, pos * 2 + 1);
        } else {
            update(index, val, middle + 1, right, pos * 2 + 2);
        }
        tree[pos] = max(tree[pos * 2 + 1], tree[pos * 2 + 2]);
    }

    int query(int x, int y, int left, int right, int pos) {
        if (right < x || left > y) return 0;
        if (left >= x && right <= y) return tree[pos];
        int middle = (left + right) / 2;
        return max(query(x, y, left, middle, pos * 2 + 1), query(x, y, middle + 1, right, pos * 2 + 2));
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int left, int right) {
            return nums[left] != nums[right] ? nums[left] < nums[right] : right < left;
        });
        SegmentTree segTree(n);
        for (int i = 0; i < n; ++i) {
            int idx = idxs[i], k = segTree.query(0, idx);
            segTree.update(idx, k + 1);
        }
        return segTree.query(0, n - 1);
    }
};
