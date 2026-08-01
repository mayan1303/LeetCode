class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,c=0,j=numbers.size()-1;

        while(c==0){
            if(numbers[i]+numbers[j]==target){
                c++;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {i+1, j+1};
    }
};