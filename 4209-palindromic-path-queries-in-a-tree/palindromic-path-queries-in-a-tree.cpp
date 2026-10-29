class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;
    int timer = 0;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSubtree = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int subtree = dfs(v, u);
            sz[u] += subtree;

            if (subtree > maxSubtree) {
                maxSubtree = subtree;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h, string& s) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1) {
            decompose(heavy[u], h, s);
        }

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, s);
        }
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            seg[node] = 1 << (s[getNodeAtPosition(l)] - 'a');
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    vector<int> nodeAtPos;

    int getNodeAtPosition(int p) {
        return nodeAtPos[p];
    }

    void buildTree(int n, string& s) {
        nodeAtPos.resize(n);

        for (int u = 0; u < n; u++) {
            nodeAtPos[pos[u]] = u;
        }

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, s);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int rangeQuery(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;

        return rangeQuery(node * 2, l, mid, ql, qr) ^
               rangeQuery(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) {
                swap(u, v);
            }

            mask ^= rangeQuery(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= rangeQuery(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});
        parent.resize(n);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        sz.resize(n);
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        decompose(0, 0, s);
        buildTree(n, s);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;

                int mask = pathQuery(u, v, n);

                // A palindrome permutation can have at most
                // one character with an odd frequency.
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
