class MedianFinder {
public:
    
    priority_queue<int> LeftMax; // max heap
    priority_queue<int, vector<int>, greater<int>> RightMin; // min heap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(LeftMax.empty()){
            LeftMax.push(num);
            return;
        }
        if(num < LeftMax.top()){
            LeftMax.push(num);
        }
        else{
            RightMin.push(num);
        }
        
        if(RightMin.size() > LeftMax.size()){
            LeftMax.push(RightMin.top());
            RightMin.pop();
        }
        else{
            if(LeftMax.size()-1 > RightMin.size()){
                RightMin.push(LeftMax.top());
                LeftMax.pop();
            }
        }
    }
    
    double findMedian() {
        if(LeftMax.size()> RightMin.size()){
            return LeftMax.top();
        }
        else{
            double ans;
            ans = LeftMax.top() + RightMin.top();
            return ans/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */