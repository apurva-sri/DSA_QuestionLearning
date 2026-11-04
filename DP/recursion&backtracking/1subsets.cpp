#include<iostream>
#include<vector>
using namespace std;

void numSubsets(vector<int> &arr, vector<int>&ans, int idx){
    if(idx==arr.size()) {
        for(int val:ans) cout<<val<< " ";
        cout<<endl;
        return;
    }
    //include
    ans.push_back(arr[idx]);
    numSubsets(arr,ans,idx+1);
    ans.pop_back();//backtrack
    //exclude
    numSubsets(arr,ans,idx+1);
    return;
}

//using loop
void subsets(vector<int>& arr, vector<int>& ans, int start) {

    // Print current subset
    for(int x : ans) cout << x << " ";
    cout << endl;

    for(int i = start; i < arr.size(); i++) {

        ans.push_back(arr[i]);

        subsets(arr, ans, i+1);

        ans.pop_back();
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> ans;

    numSubsets(arr, ans, 0);
    return 0;
}