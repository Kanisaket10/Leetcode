class Solution {
public:

     // optimize one
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
    // Brute force
    // int maxProfit(vector<int>& prices){
    //    int n = prices.size();
    //    int ans = INT_MIN;

    //    for(int i=0; i<n-1; i++){
    //       for(int j=i+1; j<n; j++){
    //         ans = max(ans, prices[j] - prices[i]);
    //       }
    //    }
    //    if(ans <0)return 0;
    //    else return ans;
    // }

   
  
};