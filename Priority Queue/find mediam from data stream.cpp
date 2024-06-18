class MedianFinder {
public:
priority_queue<int>leftheap;
priority_queue<int,vector<int>,greater<int>>rightheap;


    MedianFinder() {
    }
    
    void addNum(int num) {
        if(leftheap.empty()|| num<leftheap.top()){
            leftheap.push(num);
        }
        else{
            rightheap.push(num);
        }
        if(abs((int)leftheap.size()-(int)rightheap.size())>1){
            rightheap.push(leftheap.top());
            leftheap.pop();
        }
        else if(rightheap.size()>leftheap.size()){
            leftheap.push(rightheap.top());
            rightheap.pop();
        }
    }
    
    double findMedian() {
        if(leftheap.size()==rightheap.size()){
          double mid=(leftheap.top()+rightheap.top())/2.0;
          return mid;
        }
         return leftheap.top();    
    }
};
