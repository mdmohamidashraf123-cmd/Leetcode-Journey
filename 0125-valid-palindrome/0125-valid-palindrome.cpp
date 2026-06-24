class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            // Compare case-insensitively
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};