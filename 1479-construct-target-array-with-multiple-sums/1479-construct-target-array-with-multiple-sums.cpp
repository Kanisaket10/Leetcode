class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum =0;

        priority_queue<long long> p;

        for(int i=0; i<target.size(); i++){
            p.push(target[i]);
            sum+= target[i];
        }
        
        long long maxEle, RemSum, Element;

        while(p.top() != 1){
           maxEle = p.top();
           p.pop();
           RemSum = sum - maxEle;

           if(RemSum <= 0 || RemSum >= maxEle) {
            return 0;
           }
           Element  = maxEle % RemSum;
           if(Element ==0){
            return (RemSum != 1)? 0: 1;
           }
           sum = RemSum + Element;

           p.push(Element);

        }

        return 1;

    }
};