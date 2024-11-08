class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        // MinHeap
        priority_queue<int, vector<int>, greater<int>> p;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                p.push(nums[i]);
            }
        }
        
        int cnt = 0;
        int num =0;

        while(!p.empty()){
            int temp = p.top()-num;
            if(temp != 0){
                num += temp;
                cnt++;
            }
            p.pop();
        }
      return cnt; 
    }
};