class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // free tracks the next turn (turn % k = server_id) of available servers
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < k; ++i)
            free.push(i);

        // busy tracks (finish_time, server_id) for servers currently processing
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busy;
        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            int t = arrival[i];

            // Release servers that have finished by the current arrival time
            while (!busy.empty() && busy.top().first <= t) {
                int x = busy.top().second;
                busy.pop();
                // Calculate the first turn >= i that belongs to server x
                int next_turn = i + (x - i % k + k) % k;
                free.push(next_turn);
            }

            // If no server is free, drop the request
            if (free.empty())
                continue;

            // Pop the free server with the smallest turn
            int next_turn = free.top();
            free.pop();

            // Convert the turn back to the actual server index
            int server = next_turn % k;
            busy.push({t + load[i], server});
            handled[server]++;
        }

        // Find the maximum handled count
        int max_handled = *max_element(handled.begin(), handled.end());

        // Collect all servers with the maximum count
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (handled[i] == max_handled) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
