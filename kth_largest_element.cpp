#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int A[6] =  {7,10,4,3,20,15};
    int n = 6;
    int k = 3; // Third Largest element

    // Brute Force : O(nlogn)
    //     vector<int> v;
    //     for(int i=0;i<n;i++){
    //         v.push_back(A[i]);
    //     }
    //     sort(v.begin(),v.end());
    //     cout << v[n-k];
                    
    // Optimised : O(nlogk)                                                   
    priority_queue <int, vector<int> , greater<int>> minh;

    for(int i=0;i<n;i++){
        minh.push(A[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout << minh.top();
}