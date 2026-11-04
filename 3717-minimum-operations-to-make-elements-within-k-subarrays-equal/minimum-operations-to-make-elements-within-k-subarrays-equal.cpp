
class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int i, long long val) {
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        long long query(int i) {
            long long ans = 0;

            while (i > 0) {
                ans += bit[i];
                i -= i & -i;
            }

            return ans;
        }

        // Find the index of the kth element
        int kth(int k) {
            int idx = 0;

            int pw = 1;
            while (pw * 2 <= n)
                pw *= 2;

            for (; pw > 0; pw /= 2) {
                int next = idx + pw;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());

        vals.erase(
            unique(vals.begin(), vals.end()),
            vals.end()
        );

        int m = vals.size();

        Fenwick cnt(m), sum(m);

        auto getIndex = [&](int v) {
            return lower_bound(
                vals.begin(), vals.end(), v
            ) - vals.begin() + 1;
        };

        // Sliding window median costs
        vector<long long> cost(n - x + 1);

        long long windowSum = 0;

        for (int i = 0; i < n; i++) {
            int id = getIndex(nums[i]);

            cnt.update(id, 1);
            sum.update(id, nums[i]);

            windowSum += nums[i];

            if (i >= x) {
                int old = getIndex(nums[i - x]);

                cnt.update(old, -1);
                sum.update(old, -1LL * nums[i - x]);

                windowSum -= nums[i - x];
            }

            if (i >= x - 1) {
                // Lower median
                int rank = (x + 1) / 2;

                int mid = cnt.kth(rank);

                long long median = vals[mid - 1];

                long long leftCount = cnt.query(mid);
                long long leftSum = sum.query(mid);

                long long rightCount = x - leftCount;
                long long rightSum = windowSum - leftSum;

                cost[i - x + 1] =
                    median * leftCount - leftSum +
                    rightSum - median * rightCount;
            }
        }

        // DP with rolling arrays
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current position
                curr[i] = curr[i - 1];

                // Take the window ending at i-1
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
