class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> apl(26,0);

        for(int i=0; i<sentence.size(); i++){
            apl[sentence[i] -'a']++;
        }
        
       for(int i=0; i<26; i++){
           if(apl[i] == 0) return 0;
        }
      return 1;
    }
};