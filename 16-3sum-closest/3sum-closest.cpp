class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        int n=nums.size();

        int ans=nums[0]+nums[1]+nums[2];
        int sum=0;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(abs(ans-target) > abs(sum-target)){
                        ans=sum;
                    }
                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }

            
        }

    return ans;
    }
};