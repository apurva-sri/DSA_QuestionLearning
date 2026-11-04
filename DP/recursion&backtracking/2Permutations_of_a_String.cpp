#include<iostream>
#include<string>
using namespace std;

void permutations(string &s, int idx) {

    // Base case
    if(idx==s.size()){
        cout<<s<<endl;
        return;
    }

    // Try all possible choices
    for(int i=idx; i<s.size();i++){

    // Swap
    swap(s[i],s[idx]);

    // Recursive call
    permutations(s,idx+1);

    // Backtrack (swap again)
    swap(s[i],s[idx]);

    }
}


int main() {
    string s = "abc";

    permutations(s, 0);

    return 0;
}