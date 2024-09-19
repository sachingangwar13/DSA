// problemLink - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *fast=head;
        ListNode *slow = head;
        for(int i=1 ; i<= n ; i++){
            fast = fast->next;
        }

        if(fast == NULL)return head->next;

        // Move both pointers until fast reaches the end
        while( fast-> next !=NULL){

            fast=fast->next;
            
            slow=slow->next;
        }
        ListNode *temp = slow->next;
        
        slow ->next = slow ->next->next;
        
        delete temp;
        return head;
    }
};