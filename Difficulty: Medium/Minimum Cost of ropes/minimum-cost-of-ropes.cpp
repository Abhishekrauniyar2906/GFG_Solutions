class Solution {
  public:
    int minCost(vector<int>& arr) {
        
    
      priority_queue<int, vector<int>, greater<int>>pq;
      int n = arr.size();
      if(n == 1) return 0;
      for(int i = 0; i < n; i++){
          pq.push(arr[i]);
      }
      
      int ans = 0;
       int sum = 0;
      while(pq.size() > 1){
          int topA = pq.top();
          pq.pop();
          int topB = pq.top();
          pq.pop();
          
          sum = topA + topB;
          pq.push(sum);
          ans += sum;
    }
    
   
    return ans;
    }
};