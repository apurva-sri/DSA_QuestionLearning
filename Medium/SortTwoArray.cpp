#include<iostrem>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<int> arr1, arr2;

    for(int i=0; i<n;i++) cin>>arr1[i];
    for(int i=0; i<m;i++) cin>>arr2[i];

    int ptr1=0, ptr2=0;

    while(ptr1<=n){
        if(arr1[ptr1]<arr2[ptr2]) ptr1++;
        else{
            int temp = arr1[ptr1];
            arr2[ptr2] = arr1[ptr1];
            arr1[ptr1] = temp;
        }
    }
    return 0;
}