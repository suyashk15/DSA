#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Top-down approach :

    int LCS(string text1, string text2, int n, int m){

        int dp[n+1][m+1];

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }


    int main(){
        string text1 = "abcdw";
        string text2 = "ebcdr";
        //memset(dp,-1,sizeof(dp)); 
        int n = text1.length();
        int m = text2.length();
        //cout << longestCommonSubsequence(text1, text2, n, m);
        cout << LCS(text1, text2, n, m);
    }
