class Solution {
public:

    int convert(string date, vector<int>& days){
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        int total=day;

        for(int i=0;i<month-1;i++){
            total+=days[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        int A1=convert(arriveAlice, days);
        int A2=convert(leaveAlice, days);
        int B1=convert(arriveBob, days);
        int B2=convert(leaveBob, days);

        if(A2<B1 || B2<A1) return 0;

        int ans=min(A2,B2) - max(A1,B1) + 1;

        return ans;

    }
};