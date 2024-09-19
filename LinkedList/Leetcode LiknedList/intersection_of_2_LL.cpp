// LINK - https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode * a = headA , *b = headB;

        if(a == NULL || b == NULL)return NULL;

        while(a!=b && a!=NULL && b!=NULL){
            a=a->next;
            b= b->next;

            /*
                Any time they collide or reach end together without colliding 
                then return any one of the pointers.
            */

            if(a==b)return a;

            /*
                If one of them reaches the end earlier then reuse it 
                by moving it to the beginning of other list.
                Once both of them go through reassigning, 
                they will be equidistant from the collision point.
            */
           
            if(a == NULL) a = headB;
            if(b == NULL) b = headA;

        }
        return a;
    }
};