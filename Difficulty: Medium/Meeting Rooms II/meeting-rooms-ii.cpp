class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
    //   using two pointer
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    
    int j = 0;
    int rooms = 0;
    // why i = 0 because pehle vaue ke liye 1room chaiye isliye
    for(int i = 0; i < start.size(); i++){
        if(start[i] >= end[j]){
            j++; // no extra rooms needed
        }
        else{
            rooms++;
        }
    }
    
        return rooms;
        
    }
};
