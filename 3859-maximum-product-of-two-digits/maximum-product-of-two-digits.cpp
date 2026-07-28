class Solution {
public:
    vector<int> ans;
    int maxProduct(int n) {
        while(n!=0){
            int m=n%10;
            ans.push_back(m);
            n=n/10;
        }
        sort(ans.begin(),ans.end());
        int k=ans.size();
        int a=ans[k-1];
        int b=ans[k-2];
        return a*b;
    }
};