class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=0;i<s.size()-1;i++){
            int x = abs((s[i]-'0')-(s[i+1]-'0'));
            if(x>2)return 0;
        }
        return 1;
    }
};
