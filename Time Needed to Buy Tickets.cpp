// Jaise question me diya hi bus ohi kr do.
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {
        int n = tic.size();
        tic[k] = -1 * tic[k];
        int temp = tic[k];
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(tic[i]);
        }
        int cnt = 0;
        while (temp < 0) {
            if (q.front() > 0) {
                q.front() -= 1;
                if (q.front() > 0) {
                    int x = q.front();
                    q.pop();
                    q.push(x);
                } else {
                    q.pop();
                }
                cnt++;
            }
            if (q.front() < 0) {
                q.front() += 1;
                temp++;
                if (q.front() < 0) {
                    int x = q.front();
                    q.pop();
                    q.push(x);
                } else {
                    q.pop();
                }
                cnt++;
            }
        }
        return cnt;
    }
};
