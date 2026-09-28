class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int a=st.size();
                ans= max(ans,a);
                st.pop();
            }
            i++;
        }
        return ans;
    }
};