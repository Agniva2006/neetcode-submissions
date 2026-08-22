class Solution {
   public:
    vector<int> nextleftSmaller;
    vector<int> nextrightSmaller;
    int n;
    void small(vector<int>& heights) {
        stack<int> st;
        stack<int> stNew;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextleftSmaller.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stNew.empty() && heights[stNew.top()] >= heights[i]) {
                stNew.pop();
            }
            nextrightSmaller.push_back(stNew.empty() ? n : stNew.top());
            stNew.push(i);
        }
        reverse(nextrightSmaller.begin(),nextrightSmaller.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        n = heights.size();
        small(heights);
        // for(int i = 0;i < n;i++){
        //     cout<<nextleftSmaller[i]<<" "<<nextrightSmaller[i] <<endl;
        // }
        for (int i = 0; i < n; i++) {
            int leftIndx = nextleftSmaller[i];
            int rightIndx = nextrightSmaller[i];
            
            ans = max(ans, (rightIndx - leftIndx - 1) * heights[i]);
        }
        return ans;
    }
};
