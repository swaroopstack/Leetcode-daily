class MedianFinder {
public:
    priority_queue<int> lefthalf;
    priority_queue<int, vector<int>, greater<int>> righthalf;
    MedianFinder() {}

    void addNum(int num) {
        if (righthalf.empty() || num >= righthalf.top()) {
            righthalf.push(num);
        } else {
            lefthalf.push(num);
        }
        if (righthalf.size() > lefthalf.size() + 1) {
            int val = righthalf.top();
            righthalf.pop();
            lefthalf.push(val);
        }
        if (lefthalf.size() > righthalf.size()) {
            int val = lefthalf.top();
            lefthalf.pop();
            righthalf.push(val);
        }
    }

    double findMedian() {
        double ans;
        if ((lefthalf.size() + righthalf.size()) % 2 == 0) {
            ans = (lefthalf.top() + righthalf.top()) / 2.0;
        } else {
            return (double)righthalf.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */