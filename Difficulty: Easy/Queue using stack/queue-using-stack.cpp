class myQueue {
   
   stack<int>s1;
   stack<int>s2;
  public:
    myQueue() {
        // Initialize your data members
        
        
    }

    void enqueue(int x) {
        s1.push(x);
        
        
    }

    void dequeue() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(!s2.empty()){
            s2.pop();
        }
    }

    int front() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            } 
        }
        
        if(!s2.empty()){
            return s2.top();
        }
        return -1;
    }

    int size() {
        return s1.size() + s2.size();
    }
};
