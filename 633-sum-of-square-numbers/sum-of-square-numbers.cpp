class Solution {
public:
    bool judgeSquareSum(int c) {

        int p=sqrt(c);
        int i=0,j=p;
        while(i<=j){
            long long sum=1LL * i * i + 1LL * j * j;
            if(sum==c){
                return true;
            }
            else if(sum>c){
                j--;
            }
            else{
                i++;
            }
        }
    return false;
    }
};