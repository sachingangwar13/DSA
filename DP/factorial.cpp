#include<bits/stdc++.h>
using namespace std;

int fact(int n , vector<int> &dp){
    if(n<=1){
        return 1;
    }

    
    if(dp[n] != -1)return dp[n];
    dp[n] = n * fact(n-1, dp);
    
    return dp[n];
}

 
int main(){
  
    int n;
    cin>>n;

    vector<int> dp(n+1 , -1);

    cout << fact(n,dp);
 
  return 0;
}