class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int m;
        for(int i=1;i<x;i++){
            if(i > x/i){
                m=i-1;
                break;
            }
        }
        return m;
    }
};