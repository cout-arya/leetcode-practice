class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        priority_queue<pair<int, int>> pq;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        pair<int, int> temp = pq.top();
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            if (abs(temp.first - curr.first) <= maxDiff) {
                ds.unionBySize(temp.second, curr.second);
            }
            temp = curr;
        }
        vector<bool> ans;
        for (auto it : queries) {
            ans.push_back(ds.findUPar(it[0]) == ds.findUPar(it[1]));
        }
        return ans;
    }
};