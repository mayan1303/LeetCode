
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;
        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int cnt = 1;

            // Merge smaller groups into the current number
            while (!dq.empty() && dq.back().first < num) {
                int nextNum = dq.back().first;
                int nextCnt = dq.back().second;
                dq.pop_back();

                cnt += nextCnt;

                cost += 1LL * (num - nextNum) * nextCnt;
            }

            dq.push_back({num, cnt});

            // Shrink window while cost exceeds k
            while (cost > k) {
                int rightNum = dq.front().first;
                int rightCnt = dq.front().second;
                dq.pop_front();

                cost -= (rightNum - nums[j]);
                j--;

                if (rightCnt > 1) {
                    dq.push_front({rightNum, rightCnt - 1});
                }
            }

            // Count valid subarrays ending at j
            ans += (j - i + 1);
        }

        return ans;
    }
};
