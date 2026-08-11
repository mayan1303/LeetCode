class Solution {
public:
    int SquareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
    }


    bool isHappy(int n) {
        int slow=SquareSum(n);
        int fast=SquareSum(SquareSum(n));
        while(slow!=fast){
            slow=SquareSum(slow);
            fast=SquareSum(SquareSum(fast));
        }

        return slow==1;
    
    }
};