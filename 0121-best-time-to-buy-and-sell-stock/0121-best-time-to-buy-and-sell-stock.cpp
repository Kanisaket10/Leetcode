class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ptr = INT_MAX; 
        int a=0;
        int b=0;

        for(int i=0; i<n;i++){
           if(prices[i] < ptr){
               ptr = prices[i];
           }
            a = prices[i] - ptr;
            if(b < a){
                b = a;
            }
        }
      
 
    return b;
        
    }
};