class Solution {
public:

    int myAtoi(string s) {
        int n=s.size();
        long long ans=0;
        int sign=1;
        int i=0;
        //blank spaces
        while(i<n && s[i]==' '){
            i++;
        }
        //sign
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+') i++;
        
        //convert digits
        while(i<n){

            if(s[i]<'0' || s[i]>'9') break;

            int d=s[i]-'0';

            

            ans= ans*10 + d;

            if(sign*ans >INT_MAX){
                return INT_MAX;
            }
            if(sign*ans <INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return sign * ans;
        
    }
};