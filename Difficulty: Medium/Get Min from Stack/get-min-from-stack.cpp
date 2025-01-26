//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stac<pair<int,int>> st;
    
    public:
    
       
       int getMin(){
           
            if(st.empty()){
                return -1;
            }
            else{
                return st.top().second;
            }
       }
       
       /*returns poped element from stack*/
       int pop(){
           
          if(st.empty()){
              return -1;
          }
          else{
          int top = st.top().first;
          st.pop();
          return top;
       }
       }
       /*push element x into the stack*/
       void push(int x){
           
           if(st.empty()){
               pair<int,int>p = make_pair(x,x);
               st.push(p);
               
           }
           else{
               pair<int,int>p;
               p.first = x;
               int oldmin = st.top().second;
               int newmin = min(oldmin, x);
               p.second = newmin;
               st.push(p);
               
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends