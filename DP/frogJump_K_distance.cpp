#include <bits/stdc++.h>
using namespace std;

int minimizeCost(int k, vector<int>& arr) {
    
    vector<int> dp(arr.size() , -1);
    
    dp[0]=0;
    
    for(int i = 1 ; i < arr.size() ; i++){
        
        int ans = INT_MAX;
        
        for(int j = 1 ; j<=k ; j++){
            
            if(i-j>=0){
                
                int cost = dp[i-j] + abs(arr[i] - arr[i-j]);
            
                ans = min(ans , cost);
            }
            
            dp[i] = ans;
        }
    }
    
    return dp.back();
}




int main() {
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int k;
    cin>>k;

    cout << minimizeCost(k,arr) << "\n";
}

// } Driver Code Ends