class Solution {
public:
    void dfs(int distance, int curr, const vector<int>& edges,
             vector<int>& dist) {
        while (curr != -1 && dist[curr] == -1) {
            dist[curr] = distance++;
            curr = edges[curr];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1;
        int n = edges.size();
        int minOfMax = INT_MAX;
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(0, node1, edges, dist1);
        dfs(0, node2, edges, dist2);

        for (int i = 0; i < n; i++) {
            if (dist1[i] >= 0 && dist2[i] >= 0) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minOfMax) {
                    minOfMax = maxDist;
                    res = i;
                }
            }
        }
        return res;
    }
};