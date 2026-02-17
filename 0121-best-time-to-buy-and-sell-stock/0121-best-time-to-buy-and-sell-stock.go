func maxProfit(prices []int) int {
    
// Brute force
    // n := len(prices)
    // var result int
    // for i:=0 ; i<n-1; i++{
    //     for j:= i+1; j<n; j++{
    //         if prices[i] < prices[j]{
    //             profit := prices[j]-prices[i]
    //             if profit > result{
    //                 result = profit
    //             }
    //         }
    //     }      
    // }
    // return result

 // Optimizes Solution 
   minPrice := prices[0]
   maxProfit := 0

   for i:=1; i<len(prices); i++{
    if prices[i] < minPrice {
        minPrice = prices[i]
    }else if prices[i]- minPrice > maxProfit{
        maxProfit = prices[i] - minPrice
    }   
   }  
   return maxProfit
}