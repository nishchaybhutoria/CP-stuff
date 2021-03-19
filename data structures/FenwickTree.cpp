template <typename T>
struct fenwick_tree {
    vector <T> bit;
    int n;

    fenwick_tree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    fenwick_tree(vector <T>& a) : fenwick_tree((int)a.size()) {
        int sz = a.size();
        for (int i = 1; i <= sz; ++i) {
            update(i, a[i]);
        }
    }

    void update(int idx, T val) {
        for (int i = idx; i <= n; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    T query(int idx) {
        T ans = 0;
        for (int i = idx; i; i -= (i & (-i))) {
            ans += bit[i];
        }
        return ans;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
