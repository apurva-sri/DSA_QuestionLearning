#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1; i<=n;i++){
        for(int k=n; k>i; k--){
            cout<<" ";
        }
        for(int l=1; l<=i; l++){
            cout<<l;
        }
        for(int m=i-1; m>0; m--){
            cout<<m;
        }
        cout<<"\n";
    }
    return 0;
}