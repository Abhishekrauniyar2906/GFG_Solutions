class Solution {
  public:
    int kthMissing(vector<int> &nums, int k) {
      int num = 1;
      int i = 0;
      
     while(k > 0){
         if(i < nums.size() && nums[i] == num){
             i++;
         }
         else{
             k--;
             
         }
         num++;
     }
        return num - 1;
    }
};