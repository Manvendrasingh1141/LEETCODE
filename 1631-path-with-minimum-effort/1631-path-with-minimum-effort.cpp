/*
    Given +ve  weights -> use the dijkrita's algo :
*/

class Solution {
public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};

    bool is_valid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }

    int minimumEffortPath(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        // diff,{r,c}
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(i==n-1&&j==m-1)return diff;
            for(int k=0;k<4;k++){
                int r = i+row[k];
                int c = j+col[k];

                if(is_valid(r,c,n,m)){
                    int newEffort = max(abs(nums[i][j]-nums[r][c]),diff);
                    if(newEffort < dist[r][c]){
                        dist[r][c]=newEffort;
                        pq.push({dist[r][c],{r,c}});
                    }
                }
            }
        }
        return 0;
        

    }
};