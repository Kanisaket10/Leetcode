class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt = 0;

        for(int i=0; i<s.size() ;i++){
           
         if(s[i] == ')'){
                if(st.empty()){
                    cnt++;
                }
                else{
                st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        return (cnt + st.size());
    }
};