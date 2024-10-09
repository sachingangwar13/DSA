int memoization(int n , int m,vector<vector<int>> &dp){

        if(n==0 && m==0){
            return 1;
        }
        if(n<0 || m<0) return 0;

        if(dp[n][m] != -1)return dp[n][m];

        int up = memoization(n-1 , m,dp);
        int down = memoization(n,m-1,dp);

        return dp[n][m]=up+down;
    }

int Tabulation(int m, int n ) {
        
    vector<vector<int>> dp(m , vector<int>(n,-1));

    dp[0][0]=1;

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){

            if(i==0 && j==0) dp[i][j]=1;

            else{
                
                int up=0,left=0;

                if(i>0)
                    up = dp[i-1][j];
                

                if(j>0)
                    left = dp[i][j-1];
                

                dp[i][j]= up+left;
            }
        }
    }

    return dp[m-1][n-1];
}

int spaceOptimization(int m, int n) {
        
    vector<int> prev(n,0);

    for(int i=0 ; i<m ; i++){

        vector<int> cur(n,0);
        for(int j=0 ; j<n ; j++){

            if(i==0 && j==0) cur[i]=1;

            else{

                int up=0,left=0;

                if(i>0)
                    up = prev[j];
                

                if(j>0)
                    left = cur[j-1];
                

                cur[j]= up+left;
            }
        }

        prev = cur;
    }

    return prev[n-1];
}

int uniquePaths(int m, int n) {
    
    vector<vector<int>> dp(m , vector<int>(n,-1));
    return f(m-1 , n-1,dp);
}