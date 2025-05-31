class Solution {
  public:
    int findOnce(vector<int>& arr) {
       int s = 0;
       int e = arr.size() - 1;
       
       while(s < e){
           int mid = s + (e - s) / 2;
           
           bool isEven;
           
           if((e - mid) % 2 == 0){
               isEven = true;
           }
           else{
             isEven = false;
           }
           
           if(arr[mid] == arr[mid + 1]){
               if(isEven){
                   s = mid + 2;
               }
               else{
                   e = mid - 1;
               }
           }
           
           // nums[mid] != nums[mid + 1]
           else{
               if(isEven){
                   e = mid;
               }
               else{
                   s = mid + 1;
               }
           }
       }
       return arr[s];
    }
};