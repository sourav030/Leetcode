class Solution {
public:
    int area(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

       
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1; 
            ans = max(ans, width * arr[i]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int cols = matrix[0].size();
        vector<int> arr(cols, 0); 
        int ans = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < cols; j++){ 
                if(matrix[i][j] == '0'){
                    arr[j] = 0;
                } else {
                    arr[j] += 1;
                }
            }

            ans = max(ans, area(arr));
        }

        return ans;
    }
};