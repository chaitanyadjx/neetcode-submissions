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

int NodeCount(ListNode* node){
    int count = 0;
    while(node != nullptr){
        node = node->next;
        count++;
    }
    return count;
}

pair<ListNode*, ListNode*> reverseList(ListNode* t,int k){
    // if(NodeCount(t) < k) return {t, nullptr};
    ListNode* temp = t;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    while(k--){
        curr = temp; // 3->4
        temp = temp->next; // 4->5
        curr->next = prev; // 3->2->1->nullptr
        prev = curr; // 3->2->1->nullptr
    }
    t->next = temp; 
    return {curr, temp};
}

ListNode* getHead(ListNode* t, int k){
    // cout << NodeCount(t) << '\n';
    if(NodeCount(t) < k) return t;
    ListNode* temp = t;
    ListNode* curr = nullptr;
    while(k--){
        curr = temp; // 3->4
        temp = temp->next; // 4
    }
    return curr;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* actualHead = getHead(head, k);
        ListNode* temp = head;
        ListNode* previousTail = nullptr;
        int totalNodes = NodeCount(head);
        int groups = totalNodes / k;
        for(int i = 0; i < groups; i++){
            auto [newHead, nextHead] = reverseList(temp, k);
            if (previousTail != nullptr)
                previousTail->next = newHead;
            previousTail = temp;
            temp = nextHead;
        }
        previousTail->next = temp;
        return actualHead;
    }
};
