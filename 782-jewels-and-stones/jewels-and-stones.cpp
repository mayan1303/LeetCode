class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        
        unordered_set<char>s;

        int m=jewels.size();
        int n=stones.size();

        for(int i=0;i<m;i++){
            s.insert(jewels[i]);
        }

        for(int i=0;i<n;i++){
            
                if(s.count(stones[i])){
                    ans++;
                }
            
        }
        return ans;
    }
};