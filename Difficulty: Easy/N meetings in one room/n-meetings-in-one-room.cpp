
struct Compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
};


class Solution {
  public:
   
    int maxMeetings(vector<int>& start, vector<int>& end) {
      vector<pair<int,int>>time;
      
      for(int i = 0; i < start.size(); i++){
          time.push_back({start[i], end[i]});
      }
      
      sort(time.begin(), time.end(), Compare());
    
      int count = 1;
      int prevStart = time[0].first;
      int prevEnd = time[0].second;
      
      for(int i = 1; i < start.size(); i++){
          int currStart = time[i].first;
          int currEnd = time[i].second;
          
          if(currStart > prevEnd){
              count++;
              prevEnd = currEnd;
              prevStart = currStart;
          }
      }
      return count;
    }
};