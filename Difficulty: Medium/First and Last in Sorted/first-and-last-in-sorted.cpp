class Solution {
  public:
  
    int firstOcc(vector<int>& arr, int x){
          int s = 0;
        int e = arr.size() - 1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(arr[mid] == x){
              ans = mid;
              e = mid - 1;
            }
            else if(arr[mid] < x){
              s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
    
    int lastOcc(vector<int>& arr, int x){
          int s = 0;
        int e = arr.size() - 1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(arr[mid] == x){
                ans = mid;
               s = mid + 1;
            }
            else if(arr[mid] < x){
              s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int first = firstOcc(arr, x);
        // cout << "the first is : " << first << endl;
        int last = lastOcc(arr, x);
        // cout <<"the last occ is : " << last << endl;
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};