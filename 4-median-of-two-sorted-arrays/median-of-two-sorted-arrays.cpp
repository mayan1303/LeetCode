class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int prev=0,curr=0;
        int o=(m+n);
        int mid=o/2;
        int i=0,j=0;

    for (int c=0;c<=mid;c++){
        prev=curr;

        if(i<m && (j>=n || nums1[i]<nums2[j])){
            curr=nums1[i];
            i++;
        }
        else{
            curr=nums2[j];
            j++;
        }
    }
     
       if(o%2!=0){
        return curr;
       }
       
        return (prev+curr)/2.0;
       
    }
};