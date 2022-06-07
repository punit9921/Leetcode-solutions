class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    void addNum(int num) {
       if(maxh.empty() or (maxh.top()>num))
           maxh.push(num);
        else
            minh.push(num);
        if(maxh.size()>(minh.size()+1))
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        if(minh.size()>(maxh.size()+1))
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size())
        {
            return maxh.empty()==true?0:(maxh.top()+minh.top())/2.0;
        }
        else
            return maxh.size()>minh.size()?maxh.top():minh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */