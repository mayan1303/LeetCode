class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        //last seen(map)
        unordered_map<int,int>mp={
            {0,-1},
            {1,-1},
            {2,-1}
        };
       
       for(int i=0;i<n;i++){
        mp[s[i]-'a']=i;

        if(mp[0]>-1 && mp[1]>-1 && mp[2]>-1){
            int k=min({mp[0],mp[1],mp[2]});
            cnt+=k+1;
            }
       }

        
    return cnt;
    }
};