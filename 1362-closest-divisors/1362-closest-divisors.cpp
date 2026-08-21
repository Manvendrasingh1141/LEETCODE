class Solution {
public:
    vector<int> getDivisors(int n) {
        int x = sqrt(n);
        for (int i=x;i>=1;i--) {
            if (n%i==0)return {i,n/i};
        }
        return {};
    }

    vector<int> closestDivisors(int num) {
        vector<int>a = getDivisors(num+1);
        vector<int>b = getDivisors(num+2);
        if(abs(a[0]-a[1]) <= abs(b[0]-b[1]))return a;
        return b;
    }
};