class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int,bool>mp;
        int sum = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            for(int j = i + 1; j < arr.size(); j++){
                sum = arr[i] + arr[j];
               
               if(mp.find(sum) != mp.end()){
                   return true;
               }
               else{
                  mp[sum] = true;
               }
            }
        }
        
        return false;
    }
};