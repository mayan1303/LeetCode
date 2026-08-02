class Solution {
public:
    bool detectCapitalUse(string word) {
        int u=0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                u++;
            }
        }

        return u==0
        || u== word.size() 
        || u==1 && isupper(word[0]);
    }
};