#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    map<int,int> mp;
    for(int i=0; i<n; i++){
     mp[arr[i]]++;
    }

    for(auto it: mp){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int number;
    cin>>number;
    if(mp.find(number) != mp.end()){
        cout<<number<<" is present in the array and its frequency is "<<mp[number]<<endl;
    }
    else{
        cout<<number<<" is not present in the array"<<endl;
    }
    return 0;
}