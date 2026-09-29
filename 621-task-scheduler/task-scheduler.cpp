class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t=tasks.size();
        unordered_map<char,int>mp;
        int m=0;
        for(int i=0;i<t;i++){
            mp[tasks[i]]++;
            m=max(mp[tasks[i]],m);
        }
        int cn=0;
        for(auto it : mp){
            if(it.second==m){
                cn++;
            }
        }
        return max(t,(m-1)*(n+1)+cn);
    }
};