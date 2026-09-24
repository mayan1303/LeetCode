class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int a=n;
        int p=1;
        while(a>0){
            int temp=a%10;
            s+=temp;
            p*=temp;
            a/=10;
        }
        int sum=s+p;
        if(n%sum==0 ){
            return true;
        }
        return false;
    }
};