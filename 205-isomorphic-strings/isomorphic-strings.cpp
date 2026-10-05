class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>s1(128,-1);
        vector<int>t1(128,-1);

        for(int i=0;i<s.size();i++){
            if(s1[s[i]]!=-1 && s1[s[i]]!=t[i]){
                return false;
            }
            if(t1[t[i]]!=-1 && t1[t[i]]!=s[i]){
                return false;
            }
            s1[s[i]]=t[i];
            t1[t[i]]=s[i];

        }
        return true;
    }
};