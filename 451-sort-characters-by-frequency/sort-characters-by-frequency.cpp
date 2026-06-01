class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        vector<pair<char, int>> v;

        for (auto it : freq)
            v.push_back({it.first, it.second});

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto [ch, count] : v) {
            ans += string(count, ch);
        }

        return ans;
    }
};