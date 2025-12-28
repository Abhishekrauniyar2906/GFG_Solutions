class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 1, j = 0;
        int platform = 1;
        int maxPlatform = 1;
        
        while(i < arr.size() && j < dep.size()){
            if(arr[i] <= dep[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            maxPlatform = max(maxPlatform, platform);
        }
        return maxPlatform;
    }
};
