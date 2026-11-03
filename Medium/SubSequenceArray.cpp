#include<bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n){
    if( ind == n){
        for(auto it : ds){
            cout<< it << " ";
        }
        if(ds.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    // take condition
    printF(ind+1, ds, arr, n);
    // backtrack
    ds.pop_back();
    // not take condition
    printF(ind+1, ds, arr, n);

    // {}
    // 1 
    // 2
    // 2 1
    // 3 
    // 3 1
    // 3 2
    // 3 2 1
    // printF(ind + 1, ds, arr, n);
    // ds.push_back(arr[ind]);
    // // take condition
    // printF(ind + 1, ds, arr, n);
    // // backtrack
    // ds.pop_back();
}


int main(){
    int arr[] = {3, 2, 1};
    int n = 3;
    cout << "Subsequences of the array are: " << endl;
    vector<int> ds;
    printF(0, ds, arr,n);
    return 0;
}