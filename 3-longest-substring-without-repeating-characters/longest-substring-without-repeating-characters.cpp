class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,m=0;
        int n=s.size();
        unordered_map<char,int>mp;

        while(r<n){
            if(!mp.count(s[r])){
                mp[s[r]]=r;
                
            }
            else{
                l = max(l, mp[s[r]] + 1);
                mp[s[r]]=r;
            }
            m=max(m,r-l+1);
            r++;
            
        }

    return m;
    }
};