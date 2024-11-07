class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;

        for(int i=0; i<stones.size(); i++){
            p.push(stones[i]);
        }

        while(p.size() > 1){
            int y =p.top();
            p.pop();
            int x =p.top();
            p.pop();

            if(y-x != 0){
                p.push(y-x);
            }
        }
        if(p.empty()) return 0;
        return p.top();
    }
};