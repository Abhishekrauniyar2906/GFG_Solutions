class myStack {
    queue<int> q1;
    
    

  public:

    void push(int x) {
        q1.push(x);
        int n = q1.size();
        n = n - 1;
        while(n--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    void pop() {
      if(!q1.empty()){
          q1.pop();
      }
    }

    int top() {
        if(q1.empty()) return -1;
       return q1.front();
    }

    int size() {
       return q1.size();
    }
};
