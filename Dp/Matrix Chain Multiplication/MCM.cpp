// format

int solve(int arr[],int i,int j){
if(i>j)return 0;// may be diff
int ans=0;
  for(int k=i;k<j;k++){
  int temp=solve(arr,i,k)+-solve(arr,k+1,j);
    ans=min or max(temp,ans);
  }
  return ans;

}
