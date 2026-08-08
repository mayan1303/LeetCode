class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        string st;

        for(int i=0;i<n;i++){
            if(st.empty() || st.back()!=s[i]){
                st.push_back(s[i]);
            }
            else{
                st.pop_back();
            }
        }
    return st;
    }
};