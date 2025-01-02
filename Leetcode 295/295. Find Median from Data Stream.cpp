// Leetcode : https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150


class MedianFinder {
public:
    priority_queue<int>leftMax;
    priority_queue<int , vector<int> ,greater<int>>rightMin;
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        if(leftMax.empty() || num < leftMax.top()){
            leftMax.push(num);
        }else{
            rightMin.push(num);
        }

        // main stram
        if(abs((int)leftMax.size() - (int)rightMin.size()) > 1){
            rightMin.push(leftMax.top());
            leftMax.pop();
        }else if(leftMax.size() < rightMin.size()){
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
        
    }
    
    double findMedian() {
        if(leftMax.size() == rightMin.size()) return (double)(leftMax.top() + rightMin.top())/2;
        return leftMax.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */