class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char>set;
        char ans;
        for(int i=0;i<s.size();i++){
            if(set.count(s[i])) {
                ans= s[i];
                break;
            }
            else{
                set.insert(s[i]);
            }
        }
        return ans;
    }
};