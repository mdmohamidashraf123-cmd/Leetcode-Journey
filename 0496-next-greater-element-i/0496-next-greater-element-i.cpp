class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        // Traverse nums2 left-to-right to find next greater element for all values
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build result directly for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(next_greater.count(num) ? next_greater[num] : -1);
        }

        return ans;
    }
};