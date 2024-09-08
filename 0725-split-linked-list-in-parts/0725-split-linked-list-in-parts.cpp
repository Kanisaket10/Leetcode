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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        ListNode* temp = head;
        int cnt = 0;
        while(temp){
          cnt++;
          temp = temp->next;
        }

        int equal=cnt/k,extra=cnt%k;
        ListNode* prevHead=head;
        while(k--){
            int t=equal;
            if(extra>0) t++;
            t--;
            ListNode* newHead=prevHead;
            ListNode* temp=newHead;
            while(newHead && t--){
                newHead=newHead->next;
            }
            if(newHead){
                prevHead=newHead->next;
                newHead->next=NULL;
            }
            ans.push_back(temp);
            extra--;
        }
        return ans;


    }
};