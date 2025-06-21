class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
     queue<int>policeIndex;
     queue<int>thiefIndex;
     int count = 0;
     
     for(int i = 0; i < arr.size(); i++){
         if(arr[i] == 'P'){
             policeIndex.push(i);
         }
         else{
             thiefIndex.push(i);
         }
     }
     
     
    while(!policeIndex.empty() && !thiefIndex.empty()){
        int police = policeIndex.front();
        int thief = thiefIndex.front();
        
        if(abs(police - thief) <= k){
            count++;
            policeIndex.pop();
            thiefIndex.pop();
        }
        else if(police > thief){
            thiefIndex.pop();
        }
        else{
            policeIndex.pop();
        }
    }
        return count;
    }
};