// User function Template for C++

class Solution {
  public:
    
    int isPossible(int arr[], int n, int d){
        int sum = 0;
        int D = 1;
        
        for(int i = 0; i < n; i++){
            if(sum + arr[i] <= d){
                sum += arr[i];
                
            }
            else{
                D++;
                sum = arr[i];
            }
        }
        return D;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int s = *max_element(arr, arr + n);
        int e = accumulate(arr, arr + n, 0);
        
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(isPossible(arr, n, mid) <= d){
                ans = mid;
                e = mid - 1;
                
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
    
};