/* There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> presum;
        auto temp = 0;
        auto size = customers.size();
        int max1 = 0,max_no=0;
        int str=0,end=0,start_inx;

        int satisfaction = 0;
        for (auto i=0; i<size; i++){
            if(grumpy[i] == 0){
                satisfaction += customers[i];
            }
        }
        while(end <= size-1){
            end = str;
            for(auto i=0; i<minutes; i++){
                if(grumpy[str+i] != 0)
                max1 += customers[end];
                end++; 
            }
            if(max_no < max1){
                max_no = max1;
                start_inx = str;
            }
            str++;
            max1 = 0;
        }
        satisfaction += max_no;
        return satisfaction;
    }
};