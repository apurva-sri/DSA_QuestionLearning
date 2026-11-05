#include<iostream>
#include<vector>
#include<algorithm>
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
        if(candidates[i]>target) break;

        // if(i>idx && candidates[i]==candidates[i-1]) continue;

    // Include current element
        ans.push_back(candidates[i]);

    // Recursive call
        combinationSum(candidates, target-candidates[i], ans, i+1);

    // Backtrack
        ans.pop_back();
    }
}

int main(){
    vector<int> candidates = {1,2,1,3,5};
    int target = 4;
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, ans, 0);

    return 0;
}