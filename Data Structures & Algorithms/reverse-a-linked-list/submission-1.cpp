/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int count = 0;
        ListNode* curr = head;
        while(temp != nullptr){
            count++;    
            curr = temp;  
            temp = temp->next;   
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
};
