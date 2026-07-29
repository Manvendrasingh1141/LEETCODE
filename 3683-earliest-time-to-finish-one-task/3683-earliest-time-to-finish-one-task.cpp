class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        vector<int>temp;
        for(int i=0;i<tasks.size();i++)temp.push_back(tasks[i][0]+tasks[i][1]);
        int mn=INT_MAX;
        for(int i=0;i<temp.size();i++)mn=min(mn,temp[i]);

        return mn;
    }
};