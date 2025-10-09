class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int circle_index = -1;
        int n = arr.size();
        
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] > arr[i - 1]){
                circle_index = i - 1;
                break;
            }
        }
        
        if(circle_index == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        for(int i = n - 1; i > circle_index; i--){
            if(arr[i] > arr[circle_index]){
                swap(arr[i], arr[circle_index]);
                break;
            }
        }
        
        reverse(arr.begin() + circle_index + 1, arr.end());
    }
};