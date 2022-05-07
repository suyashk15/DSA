#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) { // Kuch error hai code mein :(
    
    int n = A.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + A[i];
    }
    
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
        
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
        
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=sum;k++){
            if(A[j-1]<=k){
                dp[j][k] = (dp[j-1][k-A[j-1]] || dp[j-1][k]) ;
            }
            else{
                dp[j][k] = dp[j-1][k] ;
            }
        }
    }
    vector<int> ans;
    for(int l=0;l<=sum;l++){
        if(dp[n][l] == true){
            ans.push_back(l);  
        }
    }
    int m = ans.size()/2;
    int fin = INT_MAX;
    for(int p=0;p<=m;p++){
        fin = min(fin, abs(sum - 2*ans[p]));
    }
    return fin;
}

int main(){
    vector<int> A = { 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45 };
    cout << solve(A);
}