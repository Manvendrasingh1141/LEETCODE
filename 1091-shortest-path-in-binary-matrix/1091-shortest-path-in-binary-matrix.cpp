class Solution {
public:
    int row[8] = {-1,-1,-1,0,0,1,1,1};
    int col[8] = {-1,0,1,-1,1,-1,0,1};
    
    bool is_valid(int i,int j,int N){
        return i>=0&&j>=0&&i<N&&j<N;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& nums) {
        int N = nums.size();
        if(nums[0][0] || nums[N-1][N-1])return -1;
        
        queue<pair<int,int>>q; //i,j
        q.push({0,0});
        nums[0][0]=1;
        int cnt=1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
    
            if(i==N-1 && j==N-1)return cnt;

            for(int k=0;k<8;k++){
                int r = i + row[k];
                int c = j + col[k];

                if(is_valid(r,c,N) && !nums[r][c]){
                    nums[r][c]=1;
                    q.push({r,c});
                    }
                }
            }
            cnt++;

        }

        return -1;
    }
};