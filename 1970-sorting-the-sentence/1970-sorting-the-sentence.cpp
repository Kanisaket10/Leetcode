class Solution {
public:
    string sortSentence(string s) {
        string str, temp;
        vector<string> ans(10);
        int cnt=0;
        for(int i=0; i<s.size(); i++){

            if(s[i] == ' '){
              int idx = temp[temp.size()-1]-'0';
              temp.pop_back();
              ans[idx] = temp;
              temp.clear();
              cnt++;
            }
            else{
                temp +=s[i];  //is2
            }
        }
        
        int idx = temp[temp.size()-1]-'0';
              temp.pop_back();
              ans[idx] = temp;
              temp.clear();
              cnt++;

        for(int i=1; i<=cnt; i++){
            str +=ans[i];
            str += ' ';
        }
        str.pop_back();
        return str;
    }
};