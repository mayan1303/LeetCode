class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int sum=0;
        double avg=INT_MIN;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            
            while(r-l+1>k){
                sum-=nums[l];
                l++;
            }

            double avg1=(double)sum/k;
            
            if(r-l+1==k){
                avg=max(avg,avg1);
            }
            
        }
        return avg;
    }
};