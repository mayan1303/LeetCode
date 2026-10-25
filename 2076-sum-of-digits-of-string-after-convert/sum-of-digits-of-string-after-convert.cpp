class Solution {
public:

    int getLucky(string s, int k) {
        int n=s.size();
        vector<int> t(n);
        string a="";
        int r=0;
        for(int i=0;i<s.size();i++){
            a+= to_string(s[i]-'a'+1);
        }
        for(int i=0;i<a.size();i++){
            r+=a[i]-'0';
        }
        k--;
        
        if(k==0) return r;
        while(k>0){
            int sum=0;
            while(r>0){
                sum+=r%10;
                r/=10;
            }
            r=sum;
            k--;
        }
        return r;
        
    }
};