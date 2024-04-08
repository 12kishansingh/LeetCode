class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>st;
        for(int i=0;i<students.size();i++){
            st.push(students[i]);
        }
        stack<int>sand;
        for(int j=sandwiches.size()-1;j>=0;j--){
            sand.push(sandwiches[j]);
        }int cnt=0;
        while(!st.empty() && cnt<st.size()){
            if(sand.top()==st.front()){
                sand.pop();
                st.pop();cnt=0;
            }
            else {
                st.push(st.front());
                st.pop();
                cnt++;
            }
        }
       return st.size();


        
    }
};
