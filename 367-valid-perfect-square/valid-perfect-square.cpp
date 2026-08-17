class Solution {
public:
    bool isPerfectSquare(int num) {
        int n=num/2;
        int l=1,r=n;
        if(num==1) return true;
        while(l<=r){
            long long mid= l+ (r-l)/2;
            if(mid*mid == num){
                return true;
            }
            else if(mid*mid > num){
                r=mid-1;
            }
            else l=mid+1;
        }
    return false;
    }
};