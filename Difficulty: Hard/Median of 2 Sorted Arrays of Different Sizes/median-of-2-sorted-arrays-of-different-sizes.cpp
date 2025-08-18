class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
      int i = 0, j = 0, k = 0;
      
      int n = a.size();
      int m = b.size();
      
      int size = n + m;
      
      int idx1 = (size / 2) - 1;
      int idx2 = size / 2;
      
      int e1 = -1, e2 = -1;
      
      while(i < n && j < m){
          if(a[i] <= b[j]){
              if(idx1 == k){
                  e1 = a[i];
              }
              
              if(idx2 == k){
                  e2 = a[i];
              }
              i++;
          }
         
         else{
             if(idx1 == k){
                 e1 = b[j];
             }
             
             if(idx2 == k){
                 e2 = b[j];
             }
             j++;
         } 
         k++;
      }
      
      while(i < n){
          if(idx1 == k){
                  e1 = a[i];
              }
              
              if(idx2 == k){
                  e2 = a[i];
              }
              i++;
              k++;
          }
      
      
      while(j < m){
            if(idx1 == k){
                 e1 = b[j];
             }
             
             if(idx2 == k){
                 e2 = b[j];
             }
             j++;
             k++;
         } 
      
      
      if(size % 2 == 1) return e2;
      
      return (e1 + e2) / 2.0;
    } 
};