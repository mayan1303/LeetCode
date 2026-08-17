class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int l=0,ans=0;

        for(int h=0;h<fruits.size();h++){
            mp[fruits[h]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,h-l+1);
        }

        return ans;
    }
};