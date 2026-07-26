class Solution {
public:
    void findEven(vector<int>& nums,vector<int> &res,vector<int>&visited,int idx,int d){
        if(idx==3){
            if(d%2==0)res.push_back(d);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
            if(d == 0 && nums[i] == 0)continue;
                d = d * 10 + nums[i];
                visited[i]=1;
                findEven(nums,res,visited,idx+1,d);
                d/=10;
                visited[i]=0;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& nums) {
        vector<int>res;
        vector<int>visited(nums.size(),0);
        findEven(nums,res,visited,0,0);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};


