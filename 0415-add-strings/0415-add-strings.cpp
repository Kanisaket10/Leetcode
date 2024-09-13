class Solution {
public:

    string add(string num1, string num2){
        string ans;
        int sum=0, carry =0;
        int idx1 = num1.size()-1;
        int idx2 = num2.size()-1;
       
       // num1 and num2 both exsist
        while(idx2 >= 0){
            sum = num1[idx1]-'0' +num2[idx2]-'0' + carry;
            carry = sum/10;
            ans +=sum%10 + '0';
            idx1--;
            idx2--;
        }

        //nums1 
        while(idx1 >= 0){
            sum = num1[idx1]-'0' + carry;
            carry = sum/10;
            ans +=sum%10 + '0';
            idx1--;
        }
        // if carry
        if(carry) ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;

    }

    string addStrings(string num1, string num2) {
         if(num1.size()>num2.size()){
            return add(num1,num2);
         }
         else{
            return add(num2, num1);
         }
         return "";
    }
};