class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            char el = s[0];
            s.erase(0,1);
            s.push_back(el);

            if(s==goal){
                return 1;
                break;
            }
        }

        return 0;
    }
};