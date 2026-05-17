class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int carry = 0, sum = 0;
        int i = nums1.size() - 1, j = nums2.size() - 1;
        string ans = "";

        while(i >= 0 && j >= 0){
            int x = (nums1[i] - '0') + (nums2[j] - '0');
            sum = x + carry;
            ans += (sum % 10) + '0';
            carry = sum / 10;
            i--;
            j--;
        }

        while(i >= 0){
            int x = nums1[i] - '0';
            sum = x + carry;
            ans += (sum % 10) + '0';
            carry = sum / 10;
            i--;
        }

        while(j >= 0){
            int x = nums2[j] - '0';
            sum = x + carry;
            ans += (sum % 10) + '0';
            carry = sum / 10;
            j--;
        }

        if(carry)
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};