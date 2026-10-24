class Solution {
public:

    int check(char c){
        int f=0;
        int i=0;
        string a="0123456789";
        while(f==0 && i!=a.size()){
            if(c==a[i]){
                f=1;
                return i;
            }
            i++;
        }
        return -1;
    }
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
            int d=check(s[i]);

            if(d==-1) break;

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