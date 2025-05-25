class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
  
         if (hand.size() % groupSize != 0) return false;
        map<int,int>freq;

        for(auto num : hand){
            freq[num]++;
        }
        
        for(auto it : freq){
            int card = it.first;
            int count = it.second;

            if(count > 0){
                for(int i = 0; i < groupSize; i++){
                    if(freq[card + i] < count){
                        return false;
                    }
                    
                        freq[card + i] -= count;
                    
                }
            }
        }
        return true;
        
    
    }
};