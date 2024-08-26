class Solution {
public:
double recur(double x,int n){
    double ans=1;
    if(n==0){
        return 1;
    }
    double temp=recur(x,n/2);
    if(n&1) return temp*temp*x;

    return temp*temp;
}

    double myPow(double x, int n) {
        
        if(n>=0){
            return recur(x,n);
        }
        n=abs(n);
        return recur(1/x,n);
    }
};
