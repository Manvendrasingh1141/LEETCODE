class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>sv(256,0);
        vector<int>tv(256,0);

        for(int i=0;i<s.size();i++){
            if(sv[s[i]]!=tv[t[i]])return 0;

            sv[s[i]] = i+1;
            tv[t[i]] = i+1;
        }
        return 1;
    }
};