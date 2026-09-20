class Solution {
public:
    int reverseDegree(string s) {
       int ans=0;
       
       for(int i=0;i<s.size();i++){
        int in=i+1;
        char alp=s[i];
        int re='z'- alp + 1;

        ans+= in * re;
       }



       return ans; 
    }
};