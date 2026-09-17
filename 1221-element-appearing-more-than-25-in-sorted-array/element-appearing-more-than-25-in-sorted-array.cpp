class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int a=n/4;
        int ans;
        int l=0,r=0;
        while(r<n){
            if(arr[l]==arr[r]){
                r++;
                if(r-l+1>a){
                    ans=arr[l];
                }
            }
            else{
                l=r;
                r++;
            }
            
        }

        return ans;
    }
};