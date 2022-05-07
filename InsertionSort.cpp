#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void insertionSort(int A[], int n){
    int key,j;
    for(int i=0; i<=n-1; i++){
        key = A[i];
        j = i-1;

        while(j>=0 && key < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void printArray(int A[],int n){
    for(int j=0; j<=n-1; j++){
        cout<< A[j] << " ";
    }
    cout<<"\n";
}

int main(){
    int A[] = {2,12,34,3,87};
    int n;
    n = 5;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);

}