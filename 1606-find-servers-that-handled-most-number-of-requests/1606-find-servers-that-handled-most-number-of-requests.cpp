
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        // Initially all servers are available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {

            // Step 1: Free completed servers
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // Step 2: Find the preferred server
            int target = i % k;

            auto it = available.lower_bound(target);

            // Step 3: Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            // Step 4: If no server is available, drop request
            if (available.empty()) {
                continue;
            }

            // Step 5: Assign request
            int server = *it;

            available.erase(it);

            count[server]++;

            int finishTime = arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Step 6: Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
