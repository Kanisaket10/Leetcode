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
    // ListNode* mergeTwo(ListNode* head1, ListNode* head2) {
    //     ListNode* h1 = head1, *h2= head2;
    //     ListNode* tail = new ListNode(0); 
    //     ListNode *head = tail;
        
    //     while(h1 && h2){
    //         if(h1->val <= h2->val){
    //             tail->next = h1;
    //             h1 = h1->next;
    //             tail = tail->next;
    //         }
    //         else{
    //             tail->next = h2;
    //             h2 = h2->next;
    //             tail = tail->next;
    //         }
    //     }

    //     if(h1){
    //         tail->next = h1;
    //     }
    //     if(h2){
    //         tail->next = h2;
    //     }
    
    //   return head->next;
    // }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {       
    //     int n = lists.size();

    //     if(lists.empty() ) return NULL;

    //     if(n == 1) return lists[0];        

    //     for(int i=0; i<n-1; i++){
    //        lists[i+1] = mergeTwo(lists[i], lists[i+1]);
    //     }
    //     return lists[n-1];
    // }


// By using MIN_HEAP
    
    class Compare
    {
      public:

      bool operator()(ListNode* a, ListNode* b){
          return (a->val > b->val);
      }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists){
       
      int k = lists.size();
      if(k==0) return NULL;

      priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
      //(lists.begin(), lists.end());

      for(int i=0; i<k; i++){
       if(lists[i]) pq.push(lists[i]);
      }

      ListNode* head = new ListNode(0);
      ListNode *tail = head;
    //   ListNode *temp;
    
    
     while (!pq.empty()) {
        ListNode* temp = pq.top();
        pq.pop();
        tail->next = temp;
        tail = temp;

        if (temp->next) {
            pq.push(temp->next);
        }
    }

   return head->next;
    }

};