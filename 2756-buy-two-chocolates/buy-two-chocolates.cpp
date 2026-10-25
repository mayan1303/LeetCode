class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m1=INT_MAX,m2=INT_MAX;
        for(int i : prices){
            if(i<m1){
                m2=m1;
                m1=i;
            }
            else if(i<m2){
                m2=i;
            }
        }


        int cost=m1+m2;
        int a=money-cost;
        if(a>=0) return a;
        else return money;
        
    }
};