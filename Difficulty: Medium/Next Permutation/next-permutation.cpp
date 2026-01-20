class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
       int n = arr.size();
    
    int centreIndex = -1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < arr[i + 1]){
            centreIndex = i;
            break;
        }
    }
        if(centreIndex == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
    
    
    for(int i = n - 1; i > centreIndex; i--){
        if(arr[i] > arr[centreIndex]){
            swap(arr[centreIndex], arr[i]);
            break;
        }
    }
    reverse(arr.begin() + centreIndex + 1, arr.end());
        
    }
};