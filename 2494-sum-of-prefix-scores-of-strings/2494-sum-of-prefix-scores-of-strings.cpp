// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
        
//     }
// };
class TrieNode {
public:
    TrieNode* children[26];
    int nodeFreq;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        nodeFreq = 0;
    }

    void insert(const string& key) {
        TrieNode* curr = this;
        for (char chr : key) {
            int indx = chr - 'a';
            if (curr->children[indx] == nullptr) {
                curr->children[indx] = new TrieNode();
            }
            curr->children[indx]->nodeFreq++;
            curr = curr->children[indx];
        }
    }

    int findScore(const string& key) {
        TrieNode* curr = this;
        int score = 0;
        for (char chr : key) {
            int indx = chr - 'a';
            score += curr->children[indx]->nodeFreq;
            curr = curr->children[indx];
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& word : words) {
            root->insert(word);
        }

        int size = words.size();
        vector<int> answer(size);
        for (int i = 0; i < size; i++) {
            answer[i] = root->findScore(words[i]);
        }

        return answer;
    }
};