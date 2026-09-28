class Solution {
public:
    int findComplement(int num) {
        int og=num;
        int ans=0;
        while(og>0){
            ans<<=1;
            ans=ans | 1;
            og>>=1;
        }
        return ans^num;
    }
};