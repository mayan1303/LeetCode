class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        char c;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(int i=0;i<t.size();i++){

            if(!mp.count(t[i])){
                c=t[i];
                break;
            }
            else{
                if(mp[t[i]]>0){
                    mp[t[i]]--;
                }
                else{
                c=t[i];
                break;
                }
            }
            
        }
    return c;
    }
};