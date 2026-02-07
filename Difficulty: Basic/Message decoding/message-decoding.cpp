bool decode(string S) {
   int j = 0;
   string p = "hello";
   for(int i = 0; i < S.size(); i++){
       if(S[i] == p[j]){
           j++;
       }
   }
   return j == p.size() ?  1 : 0;
}