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
    ListNode* sortList(ListNode* head) {

    // Brute Force 

        if(!head || !head->next){
            return head;
        }
        vector<int> nums;
        ListNode* h1 = head;

        while(h1){
           nums.push_back(h1->val);
           h1= h1->next;
        }

        sort(nums.begin(), nums.end());
        h1 = head;

        for(int i=0; i<nums.size(); i++){
            h1->val = nums[i];
            h1 = h1->next;
        }
    return head;
        // ListNode * temp = head , *curr;

        // while(temp->next)
        // {
        //    curr = head;
        //    while(curr->next  )
        //    {
        //     if(curr->val > curr->next->val){
        //       int x = curr->val;
        //       curr->val = curr->next->val;
        //       curr->next->val = x;
        //       curr = curr->next;
        //     }
        //     else{
        //         curr = curr->next;
        //     }
        //    }
        //    temp = temp->next;
           
        // }
        // return head;
    }
};