class Solution {
  public:
    // Function to merge k sorted arrays.
    
    class Info{
        public:
        int data;
        int rowIndex;
        int ColIndex;
        Info(int data, int rowIndex, int ColIndex){
            this -> data = data;
            this -> rowIndex = rowIndex;
            this -> ColIndex = ColIndex;
        }
    };
    
    class Compare{
        public:
        bool operator()(Info* a, Info* b){
            return a -> data > b -> data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
       priority_queue<Info*, vector<Info*>, Compare>pq;
       vector<int>ans;
       for(int i = 0; i < K; i++){
           int element = arr[i][0];
           Info* temp = new Info(element, i, 0);
           pq.push(temp);
       }
        while(!pq.empty()){
            Info* temp = pq.top();
            pq.pop();
            
            ans.push_back(temp -> data);
            int topData = temp -> data;
            int topRow = temp -> rowIndex;
            int topCol = temp -> ColIndex;
            
            if(topCol + 1 < arr[topRow].size()){
                Info* next = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
                pq.push(next);
            }
        }
        return ans;
    }
};