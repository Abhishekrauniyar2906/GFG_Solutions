class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
      for(int i = 1; i < n; i++){
          int j = i - 1;
          int key = arr[i];
          
         while(j >= 0 &&  arr[j] > key){
             arr[j + 1] = arr[j];
             j--;
         }
         
         arr[j + 1] = key;
      }
        
    }
};