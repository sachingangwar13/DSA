#include<bits/stdc++.h>
using namespace std;

int memoization(int idx , vector<int> &arr, int target,vector<vector<int>> &dp){
    // debug1(idx , target)
    if(idx==0){
        
        if(target==0 && arr[idx]==0)
            return 2;
            
        if(target == 0 || arr[idx]==target)
            return 1;
            
        return 0;
    }
    
    if(dp[idx][target] != -1) return dp[idx][target];
    
    int nt = memoization(idx-1 , arr , target,dp);
    
    int take = 0;
    
    if(target>= arr[idx])
    take = memoization(idx-1 , arr , target- arr[idx] , dp);
    
    return dp[idx][target] = (take+ nt);
}

int tabulation(int n , int sum ,vector<int> arr){

    sort(arr.begin() , arr.end());
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]);
            }
        }
    }

    return dp[n][sum];

}
void solve(){
    int n , sum;
    cin>>n  >> sum;
    vector<int> arr(n);
    for(int &i:arr)cin>>i;

    vector<vector<int>> dp(n , vector<int> (sum+1 , -1));
    
    cout << tabulation(n , sum , arr);
}
 
int main(){

 
  {
    solve();
  }
 
  return 0;
}