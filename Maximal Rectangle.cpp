/*
 This single question consists of several individual question like -
 1. Maximum Area Histogram
 2. Next Small Left(NSL)
 3. Next Small Rigth(NSR)
 4. Converting 2D array into 1D array 
 4. Rectangle area of 1D array
*/
class Solution {
public:
// next small right for each index
    vector<int> NSR(vector<int>& h) {
        stack<int> st;
        int n = h.size();// monotonic stack
        vector<int> nsr(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                nsr[i] = n;
            } else {
                while(!st.empty() && h[st.top()] >= h[i])
                    st.pop();
                if(st.empty())
                    nsr[i] = n;
                else
                    nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }
    // next small left for each index 
    vector<int> NSL(vector<int>& h) {
        stack<int> st;// monotonic stack
        int n = h.size();
        vector<int> nsl(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                nsl[i] = -1;
            } else {
                while(!st.empty() && h[st.top()] >= h[i])
                    st.pop();
                if(st.empty())
                    nsl[i] = -1;
                else
                    nsl[i] = st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    
    int MAH(vector<int>& heights) {
        int n = heights.size();
        //width= nsr[i]-nsl[i]-1;
        //height=h[i];
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        //add 1st row in height 1D array
        for(int i = 0; i<m; i++) {
            height[i] = (matrix[0][i]=='1')?1:0;
        }
        int maxA = MAH(height);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = max(maxA, MAH(height));
        }
        return maxA;
    }
};
