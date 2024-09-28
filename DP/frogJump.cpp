#include <bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &arr , vector<int> &dp){
    
    if(n==0)return 0;
    
    if(dp[n] != -1 )return dp[n];
    
    int left = solve(n-1 , arr, dp) + abs(arr[n] - arr[n-1]);
    
    int right = INT_MAX;
    
    if(n>1)
    right = solve(n-2 , arr, dp) + abs( arr[n] - arr[n-2]);
    
    dp[n]=min(left , right);
    return dp[n];
}

int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n+1 , -1);
    return solve(n-1 ,height , dp);
}


int main() {
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    

    
    cout << minimumEnergy(arr, N) << "\n";
    
    return 0;
}
