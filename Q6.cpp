/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, oddCount = 0, result = 0;
        vector<int> prefixCount(nums.size() + 1, 0);
        prefixCount[0] = 1;
        for (int num : nums) {
            if (num % 2 != 0) {
                ++oddCount;
            }
            if (oddCount >= k) {
                result += prefixCount[oddCount - k];
            }
            ++prefixCount[oddCount];
        }
        return result;
    }
};