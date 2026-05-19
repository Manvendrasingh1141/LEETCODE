class Solution {
  public:
    vector<int> factorial(int n) {
       vector<int>ans(1,1);
       while(n>1){
       int carry=0,res,s=ans.size();
           for(int i=0;i<s;i++){
               res = ans[i]*n+carry;
               carry = res/10;
               ans[i] = res%10;
           }
           while(carry){
               ans.push_back(carry%10);
               carry/=10;
           }
           n--;
       }
       
       reverse(ans.begin(),ans.end());
       return ans;
        
    }
};
