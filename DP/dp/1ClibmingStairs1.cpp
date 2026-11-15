#include<bits/stdc++.h>
using namespace std;

int climb1(int n){
    if(n==0 || n==1) return 1;
    return climb1(n-1) + climb1(n-2);
}

int climb2(int n, vector<int> &dp){
    if(n==0 || n==1) return 1;

    if(dp[n]!=-1) return dp[n];

    dp[n] = climb2(n-1,dp) + climb2(n-2, dp);

    return dp[n];
}

int climb3(int n) {

    if(n <= 1)
        return 1;

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {

        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int climb4(int n) {

    if(n <= 1)
        return 1;

    int prev2 = 1;
    int prev1 = 1;

    for(int i = 2; i <= n; i++) {

        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n;
    cin>>n;

    cout<<"RECURSION: "<<climb1(n)<<endl;

    vector<int> dp(n+1, -1);
    cout<<"Recursion + Memoization (Top Down DP): "<<climb2(n, dp)<<endl;

    cout<<"Tabulation (Bottom Up DP): "<<climb3(n)<<endl;

    cout<<"Space Optimization: "<<climb4(n);
    return 0;
}
