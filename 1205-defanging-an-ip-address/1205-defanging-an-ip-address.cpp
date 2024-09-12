class Solution {
public:
    string defangIPaddr(string address) {
       
        string ans;
        string str ="[.]";
        for(int i=0; i<address.size(); i++){
            if(address[i] == '.') ans += str;
            else ans += address[i];
        }
        return ans;
    }
};