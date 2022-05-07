#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v1;
        int r = 0;
        for(int i=0; i<n; i++){
            int p;
            cin >> p;
            if(p==0){
                r = 1;
                }
            v1.push_back(p);
        }
        v1.resize(n);
        if(r==0){
            for(int j=0; j<n; j++){
                cout << v1[j] << " ";
            }
            cout << endl;
        }
        else{
            sort(v1.begin(), v1.end());
            int a = n/2;
            int b = a+2;
            sort(v1.begin()+b, v1.end(), greater<int>());
            for(int j=0; j<n; j++){
                cout << v1[j] << " ";
            }
            cout << endl;
        }

    }

}