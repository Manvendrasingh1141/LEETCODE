class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>Left(h.size(),0);
        vector<int>Right(h.size(),0);
        int maxx=0;

        for (int i = 0;i<h.size();i++) {
            Right[i] = maxx;
            maxx = max(maxx, h[i]);
        }

        maxx=0;
        int sum=0;
        for (int i = h.size()-1;i>0;i--) {
            Left[i] = maxx;
            maxx = max(maxx, h[i]);
        }

        for(int i=0;i<h.size();i++){
            int w=min(Right[i],Left[i])-h[i];
            if(w>0)sum+=w;
        }
        return sum;
    }
};

                      