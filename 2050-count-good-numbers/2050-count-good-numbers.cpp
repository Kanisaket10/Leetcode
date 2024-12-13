
#define ll long long

class Solution {
public:
    int M = 1000000007;
    // ll power(ll b, ll p){
    //     long long res =1;
    //     while(p--){
    //         res = (res*b)%M;
    //     }
    //     return res%M;
    // }
    long long power(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= M;
        if(n%2==1){
            ans *= x;
            ans %= M;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
      ll count_of_4s = n/2;
      ll count_of_5s = n - count_of_4s;
      ll ans = ((power(4, count_of_4s) % M  * power(5, count_of_5s) % M) % M);
      return (int)ans;
    }
};