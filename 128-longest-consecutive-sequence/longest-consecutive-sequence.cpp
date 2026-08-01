class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());

        
        
       for(int n : s){
        if(!s.count(n-1)){
            int length=0;
            while(s.count(n+length)){
                length++;
            }

            ans=max(length,ans);
        }
       }
    return ans;
    
    }
};