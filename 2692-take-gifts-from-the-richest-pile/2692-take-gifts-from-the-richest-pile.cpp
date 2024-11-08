class Solution {
public:
    
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p;

        for(int i=0; i<gifts.size(); i++){
            p.push(gifts[i]);
        }

        long long Total_piles =0;

        while(k && !p.empty()){
            int temp = p.top();
            p.pop();
            int x =sqrt(temp);
            p.push(x);
            k--;
        }
    
        while(!p.empty()){
            Total_piles += p.top();
            p.pop();
        }
        return Total_piles;
    }
};