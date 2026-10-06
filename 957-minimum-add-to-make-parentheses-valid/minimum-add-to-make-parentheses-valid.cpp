class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        int ans=0;
        int r=0;
        while(r<n){
            if(s[r]=='('){
                st.push(s[r]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    ans+=1;
                }
            }
            r++;
        }
        ans+=st.size();
        return ans;
    }
};