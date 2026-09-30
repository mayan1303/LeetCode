class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int l=0,r=0;
        priority_queue<pair<int,int>>pq;

        while(r<n){

            pq.push({nums[r],r});

            while(r-l+1>k){
                l++;
            }
            while(!pq.empty() && pq.top().second<l){
                    pq.pop();
                }

            
            if(r-l+1==k){
                ans.push_back(pq.top().first);
            }
            r++;
        }
        return ans;
    }
};