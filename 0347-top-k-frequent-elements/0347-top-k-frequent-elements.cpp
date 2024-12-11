class Compare{
    public:
    int operator()(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
};

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> mp;
       for(int i=0; i<nums.size(); i++){
           //mp[nums[i]] = mp[nums[i]] +1;
           mp[nums[i]]++;
       }

       typedef pair<int, int> pi;
       priority_queue<pi, vector<pi>, Compare> topKEle;

       for(auto& it: mp){
        topKEle.push(make_pair(it.first, it.second));
        if(topKEle.size()> k){
             topKEle.pop();
        }
       } 

       vector<int> topNum;
       while(topKEle.size() > 0){
        pair<int, int> p = topKEle.top();
        topKEle.pop();
        topNum.push_back(p.first);
       }

       return topNum;
    }
};