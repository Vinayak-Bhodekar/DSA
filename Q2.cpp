/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include<iostream>
using namespace std;
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ptr3 = head;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        int sum,temp,ele1,ele2;
        while(ptr1 != nullptr || ptr2 != nullptr || carry != 0){
            int ele1 = (ptr1 != nullptr) ? ptr1 -> val : 0;
            int ele2 = (ptr2 != nullptr) ? ptr2 -> val : 0;
            sum = ele1 + ele2 + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp1 = new ListNode(sum);
            ptr3 -> next = temp1;
            ptr3 = ptr3 -> next;
            if (ptr1 != nullptr) ptr1 = ptr1 -> next;
            if (ptr2 != nullptr) ptr2 = ptr2 -> next;
        }
        ListNode* ptr4 = head -> next;
        delete head;
        return ptr4;
    }
};
