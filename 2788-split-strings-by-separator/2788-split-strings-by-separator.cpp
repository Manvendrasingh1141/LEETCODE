class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char c) {
        vector<string>res;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            string temp="";
            int j=0;
            while(j<word.size()){
                if(c==word[j]){
                    if(temp!="")res.push_back(temp);
                    temp="";
                }else{
                    temp+=word[j];
                }
                j++;
            }
            if(temp!="")
            res.push_back(temp);
        }
        return res;
    }
};