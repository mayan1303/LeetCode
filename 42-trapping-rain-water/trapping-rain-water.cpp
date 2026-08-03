class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int ans=0;

        for(int i=1;i<n;i++){
            if(left[i-1]>height[i-1]){
                left[i]=left[i-1];
            }
            else{
                left[i]=height[i-1];
            }
        }

        for(int i=n-2;i>=0;i--){
            if(right[i+1]>height[i+1]){
                right[i]=right[i+1];
            }
            else{
                right[i]=height[i+1];
            }
        }

        for(int i=0;i<n;i++){
            if(min(left[i],right[i])- height[i]>=0){
                ans+= min(left[i],right[i])- height[i];
            }
        }
        return ans;
    }
};