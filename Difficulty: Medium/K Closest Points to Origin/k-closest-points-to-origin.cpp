class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int, vector<int>>> p;
        for(auto &i:points)
        {
            int x=i[0],y=i[1];
            int dis=x*x+y*y;
            p.push({dis,i});
            if(p.size()>k)
            p.pop();
        }
        vector<vector<int>> v;
        for(int i=0;i<k;i++)
        {
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};
