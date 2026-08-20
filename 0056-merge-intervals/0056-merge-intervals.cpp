class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){          
           if(ans.empty() || nums[i][0]>ans.back()[1]){
            ans.push_back(nums[i]);
           }else{
            ans.back()[1] = max(ans.back()[1],nums[i][1]);
           }
        }
        return ans;
    }
};


// [1,3] , [2,6] = [1,6]        a1<a2 && b1>a2 pick => [a1,b2]

// [8,10] , [15,18] => a1<a2 , b1<a2 => [a1,a2][b1,b2] do nothing

// [4,7] , [1,4] = [1,7] a1>a2 && a1==b2 => [a2,b1]
// [4,7] , [1,5] = [1,4] + [5,7] a1>a2 && a1<b2 => [a2,a1],[b2,b1]
// [4,7] , [1,2] = [1,2] + [4,7]  a1>a2,a1>b2  => [a2,b2],[a1,b1]  do nothing