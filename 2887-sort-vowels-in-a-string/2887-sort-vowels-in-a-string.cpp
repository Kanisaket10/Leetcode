class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0), upper(26,0);
        string vol; 
        int n= s.size();
        // for lowercase vowels
        for(int i=0; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                lower[s[i]-'a']++;
                s[i] ='#';
            }
        }
        
        // for uppercase volwels
        for(int i=0; i<n; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                upper[s[i]-'A']++;
                s[i]='#';
            }

        }
        //sorted string
        // Upper
        for(int i=0; i<26; i++){
            char c='A'+i;
            while(upper[i]){
            vol += c;
            upper[i]--;
            }
        }
        //Lower
        for(int i=0; i<26; i++){
            char c = 'a'+i;
            while(lower[i]){
              vol += c;
              lower[i]--;
            }
        }
        
        // Inserting vowels in their right position
        int first =0, second=0;     // first points vowels and second point given string;
        while(first < vol.size()){
            if(s[second] == '#'){
                s[second] = vol[first];
                first++;
            }
            second++;
        }
        return s;
    }
};