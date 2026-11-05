class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int i=0,j=0;
        int ans=0;

        while(i<n){
            if(abs(arr1[i]-arr2[j])<=d){
                i++;
                j=0;
            }
            else j++;
            if(j==m){
                ans++;
                i++;
                j=0;
            }  
        }

        return ans;


    }
};