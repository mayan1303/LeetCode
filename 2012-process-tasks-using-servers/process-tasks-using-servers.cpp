class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Available servers: {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // Busy servers: {free_time, weight, index}
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > busy;

        // Initially, all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            // Release all servers that have become free
            while(!busy.empty() && busy.top()[0] <= time) {
                auto curr = busy.top();
                busy.pop();

                available.push({
                    (int)curr[1],
                    (int)curr[2]
                });
            }

            // If no server is available, jump to the earliest free time
            if(available.empty()) {
                time = busy.top()[0];

                // Release every server that becomes free at this time
                while(!busy.empty() && busy.top()[0] <= time) {
                    auto curr = busy.top();
                    busy.pop();

                    available.push({
                        (int)curr[1],
                        (int)curr[2]
                    });
                }
            }

            // Select the server with smallest weight, then smallest index
            auto curr = available.top();
            available.pop();

            int weight = curr.first;
            int index = curr.second;

            ans[j] = index;

            // Calculate when this server will become free
            busy.push({
                time + tasks[j],
                weight,
                index
            });
        }

        return ans;
    }
};