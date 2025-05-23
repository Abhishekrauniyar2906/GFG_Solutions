class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(auto val : arr)
        {
            pq.push(val);
        }
        
        int sum = 0;
        int ans = 0;
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            sum = first + second;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};