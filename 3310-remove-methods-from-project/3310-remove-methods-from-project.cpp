class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        // Check if any outside node calls a suspicious node
        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                ans.push_back(i);

        return ans;
    }
};