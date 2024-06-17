// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> new_arr;
        int i=0,j=0,k=0;
        while(i<size1 && j<size2){
            if(nums1[i] < nums2[j]){
                new_arr.push_back(nums1[i++]);
            }
            else{
                new_arr.push_back(nums2[j++]);
            }
        }
        while(i<size1){
            new_arr.push_back(nums1[i++]);
        }
        while(j<size2){
            new_arr.push_back(nums2[j++]);
        }
        int size3 = new_arr.size();
        double median;
        if((size3 % 2) == 0){
            median = (new_arr[size3/2] + new_arr[(size3/2)-1])/2.0;
        }
        else{
            median = new_arr[size3/2]/1.0;
        }
        return median;
    }
};
int main(){
    Solution obj;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    double ans = obj.findMedianSortedArrays(nums1,nums2);
    cout<<ans;
}