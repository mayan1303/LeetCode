class Solution {
public:
    bool checkPerfectNumber(int num) {
        int temp=num;
        int sum=0;
        int n=num/2;
        while(n>0){
            if(temp%n==0){
                sum+=n;
            }
            n-=1;
        }

        return sum==num;
    }
};