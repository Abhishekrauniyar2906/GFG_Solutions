class Solution {
  public:
    int minCandy(vector<int> &arr) {
      vector<int>candies(arr.size(), 1);
      
      
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i - 1]){
            candies[i] = candies[i - 1] + 1;
          }
        }
        
        for(int i = candies.size() - 2; i >= 0; i--){
            if(arr[i] > arr[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);   
    }
};
