class Solution {
public:
    void reverse(vector<int>& ans,int s,int e){
        while(s<=e){
            swap(ans[s],ans[e]);
            s++;
            e--;
        }
    }

    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans;
        int maxi = -1;
        ans.push_back(maxi);

        if(arr.size()==1)return ans;

        for(int i=arr.size()-1;i>0;i--){
            maxi = max(maxi , arr[i]);
            ans.push_back(maxi);
        }
        reverse(ans,0,ans.size()-1);
        return ans; 
        
    }
};