class Solution {
public:
        int numDecodings(string s){
            if(s.empty() || s[0]=='0')
       { return 0;}
    int n = s.length();
    
    vector<int>dp(n+1,0);
    //initialize the dp :
    dp[0]=1;                                                   
    dp[1]=1;
    
                                        //123
    for(int i=2;i<=n;i++){
        //single 
        int oneDigit=s[i-1]-'0';
        if(oneDigit>=1 && oneDigit<=9){
            dp[i] = dp[i]+dp[i-1];
        }
        
        //double
        int secondDigit=stoi(s.substr(i-2,2));
        if(secondDigit>=10 && secondDigit<=26){
            dp[i] = dp[i]+dp[i-2];
        }
    }
    return dp[n];
}};