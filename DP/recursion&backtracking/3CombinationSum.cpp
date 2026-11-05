#include<bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>& candidates, int target,
                    vector<int>& ans, int idx) {

    // Base case 1: target becomes 0
    if(target==0){
        for(int ele:ans)cout<<ele<<" ";
        cout<<endl;
        return;
    }

    // Base case 2: target becomes negative
    if(target<0) return;

    // Try all possible choices using loop
    for(int i=idx;i<candidates.size();i++){

    // Include current element
        ans.push_back(candidates[i]);

    // Recursive call
        combinationSum(candidates, target-candidates[i], ans, i);

    // Backtrack
        ans.pop_back();
    }
}

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<int> ans;
    combinationSum(candidates, target, ans, 0);

    return 0;
}