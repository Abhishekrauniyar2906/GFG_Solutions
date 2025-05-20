class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       sort(arr.begin(), arr.end());
       sort(dep.begin(), dep.end());
       int i = 1;
       int j = 0;
       int platforms = 1;
      int minimum_platforms  = 1;
   
       while(i < arr.size() && j < dep.size()){
         
         if(arr[i] <= dep[j]){
             platforms++;
             i++;
         }   
         
         else{
             platforms--;
             j++;
         }
         
         minimum_platforms = max(minimum_platforms , platforms);
       }
        
        return minimum_platforms;
    }
};


  
