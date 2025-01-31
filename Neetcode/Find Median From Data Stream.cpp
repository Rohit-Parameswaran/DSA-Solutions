class MedianFinder {
    priority_queue<int> lq, rq;
    int n;
public:
    MedianFinder() {}

    void swaplr() {
        rq.push(-lq.top());
        lq.pop();
    }
    
    void swaprl() {
        lq.push(-rq.top());
        rq.pop();
    }
    
    void addNum(int num) {
        if(rq.size() && -num <= rq.top()) rq.push(-num);
        else lq.push(num);

        if(lq.size() - rq.size() == 2) swaplr();
        else if(rq.size() - lq.size() == 2) swaprl();
    }
    
    double findMedian() {
        if(lq.size() > rq.size()) return lq.top();
        else if(rq.size() > lq.size()) return -rq.top();
        return (lq.top() + -rq.top())/2.0;
    }
};
