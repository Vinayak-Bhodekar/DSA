#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int right,left;
        string ans;
        int maxlength=0;
        int center=0;
        int size = s.length();
        
        for(int i =0; i<size; i++){
            left = center;
            right = center;
            while(left >= 0 && right < size && s[left] == s[right]){
                if(right - left + 1 > maxlength){
                    maxlength = right - left + 1;
                    ans = s.substr(left,maxlength);
                }
                --left;
                ++right;
            }
            left = center;
            right = center+1;
            while(left >= 0 && right < size && s[left] == s[right]){
                if(right - left + 1 > maxlength){
                    maxlength = right - left + 1;
                    ans = s.substr(left,maxlength);
                }
                --left;
                ++right;
            }
            ++center;
        }
        return ans;
    }
};