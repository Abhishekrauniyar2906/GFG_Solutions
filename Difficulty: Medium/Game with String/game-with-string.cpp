class Solution {
  public:
    int minValue(string &s, int k) {
        int freq[26] = {0};
        
        for(auto ch : s){
            freq[ch - 'a']++;
        }
        
        priority_queue<int>maxHeap;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                maxHeap.push(freq[i]);
            }
        }
        
        while(k-- && !maxHeap.empty()){
            int top = maxHeap.top();
            maxHeap.pop();
            top--;
            
            if(top > 0){
                maxHeap.push(top);
            }
            
        }
        
        int result = 0;
        while(!maxHeap.empty()){
            int val = maxHeap.top();
            maxHeap.pop();
            
            result += val * val;
            
        }
        return result;   
    }
};