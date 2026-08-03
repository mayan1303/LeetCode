class Solution {
public:
    int maxArea(vector<int>& height) {
        int a=0,b=height.size()-1,maxArea=0,curr;

        while(a!=b){
            curr=(b-a) * min(height[a], height[b]);
            maxArea=max(maxArea,curr);
            if(height[a]<=height[b]){
                a++;
            }
            else{
                b--;
            }
        }

    return maxArea;    
    }
};