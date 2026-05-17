class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int totalIncome = accumulate(gas.begin(), gas.end(), 0);
           int totalExpenditure = accumulate(cost.begin(), cost.end(), 0);
        
        if(totalIncome < totalExpenditure) return -1;
        
        int totalSum = 0, resultIndex = 0;
        for(int i = 0; i < gas.size(); i++){
            totalSum += gas[i] - cost[i];
            
            if(totalSum < 0){
                 resultIndex = i + 1;
                totalSum  = 0;
               
            }
        }
        return resultIndex;
    }
};