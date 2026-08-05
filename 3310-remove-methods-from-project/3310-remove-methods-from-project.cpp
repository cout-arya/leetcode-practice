class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> sus(n, false);
        vector<int> indegree(n, 0);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        q.push(k);
        sus[k] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                indegree[it]--;
                if (!sus[it]) {
                    q.push(it);
                    sus[it] = true;
                }
            }
        }
        vector<int> res;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (sus[i] && indegree[i] > 0) {
                flag = true;
                break;
            }
            if (!sus[i]) {
                res.push_back(i);
            }
        }
        if (flag) {
            vector<int> vec(n);
            for (int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        return res;
    }
};