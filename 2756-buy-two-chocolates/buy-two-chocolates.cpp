class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int cost=prices[0]+prices[1];
        int a=money-cost;
        if(a>=0) return a;
        else return money;
        
    }
};