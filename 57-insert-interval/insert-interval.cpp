class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int s1=intervals[0][0];
        int e1=intervals[0][1];
        vector<vector<int>>ans;

        for(int i=1;i<intervals.size();i++){
            int s2=intervals[i][0];
            int e2=intervals[i][1];

            if(e1>=s2){
                s1=s1;
                e1=max(e1,e2);
                continue;
            }
            else{
                ans.push_back({s1,e1});
                s1=s2;
                e1=e2;
            }
        }
        ans.push_back({s1,e1});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool insert=false;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=newInterval[0] && insert==false){
                res.push_back({newInterval[0],newInterval[1]});
            }
            res.push_back({intervals[i][0],intervals[i][1]});
        }
        if(insert==false){
            res.push_back(newInterval);
        }
        return merge(res);
        
    }
};