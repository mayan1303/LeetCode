class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int ans=0;
        int n=s.size();
        for(int i=1;i<=26;i++){
            int unique=0;
            int atk=0;
            vector<int>freq(26,0);
            int l=0,r=0;

            while(r<n){
                int index=s[r]-'a';
                if(freq[index]==0){
                    unique++;
                }

                freq[index]++;
                if(freq[index]==k){
                    atk++;
                }
                r++;
                while(unique>i){
                    int removeIdx=s[l]-'a';
                    if(freq[removeIdx]==1) unique--;
                    if(freq[removeIdx]==k) atk--;
                    freq[removeIdx]--;
                    l++;
                }
                if(unique==i && unique==atk){
                ans=max(ans,r-l);
            }
            
            }
        }
        return ans;
    }
};