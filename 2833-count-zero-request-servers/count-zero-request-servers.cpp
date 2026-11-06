class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m= logs.size();
        int k=queries.size();
        vector<int> ans(k,0);

        sort(logs.begin(),logs.end(),[](auto &a, auto &b){
            return a[1]< b[1];
        });

        vector<pair<int, int>> q;

        for(int i=0;i<k;i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(),q.end());

        unordered_map<int, int> freq;

        int l=0,r=0;

        for(int i=0;i<k;i++){
            int time=q[i].first;
            int ind=q[i].second;

            int mn=time-x;
            int mx=time;

            while(r<m && logs[r][1]<=mx){
                freq[logs[r][0]]++;
                r++;
            }

            while(l<r && logs[l][1]<mn){
                freq[logs[l][0]]--;

                if(freq[logs[l][0]]==0){
                freq.erase(logs[l][0]);
            }
            l++;

            }
            
            ans[ind]= n - freq.size();

        }
        return ans;
    }
};