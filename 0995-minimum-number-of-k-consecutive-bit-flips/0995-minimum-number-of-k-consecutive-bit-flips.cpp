class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cnt=0;
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front()<i)q.pop();//if index is moved remove also from queue

            if(q.size()%2==nums[i]){ //2 cases to handle
                if(i+k-1>=nums.size())return -1;//edge case

                q.push(i+k-1);//add upto index+k
                cnt++;
            }
        }
        return cnt;
    }
};


// nums[i] = 1 -> odd = 0
//                even = 1 

// nums[i] = 0 -> even = 0
//                odd = 1