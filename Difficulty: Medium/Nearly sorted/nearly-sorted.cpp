
struct Compare{
    
    bool operator()(int a, int b){
        return a > b;
    }
};
class Solution {
  public:
  
    void nearlySorted(vector<int>& arr, int k) {
       priority_queue<int, vector<int>, Compare>pq;
       int index = 0;
       
       for(int i = 0; i < arr.size(); i++){
           pq.push(arr[i]);
        if(pq.size() > k){
           arr[index++] = pq.top();
           pq.pop();
       }
       }
       
      while(!pq.empty()){
          arr[index++] = pq.top();
          pq.pop();
      }
       
       
    }
};