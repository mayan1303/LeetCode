class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        unordered_set<int> s;

        while(n!=1 and !s.count(n)){
            s.insert(n);
            int sum=0;
            int temp=n;
            while(temp>0){
                int digit=temp%10;
                sum+=digit * digit;
                temp/=10;
            }

            n=sum;
        }
        return n==1;
    }
};