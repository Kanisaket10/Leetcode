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

    int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);    
    }



    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head, *curr = head->next;

        while(curr){
            int value = (gcd(prev->val, curr->val));  //6, 2, 1
            ListNode* inst = new ListNode(value);    //6 , 2, 1
            inst->next = prev->next;               //6->6, 2->10, 1->3
            prev->next = inst;                     //18->6->6->2->10->1->3
            prev =curr;                        //prev =6, 10, 3
            curr = curr->next;                 //curr =10, 3, null
        }
        return head;
    }
};