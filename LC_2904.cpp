#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;

    int n = s.size();
    int left=0, ones=0;
    string ans="";
    int minLen = 10000;

    for(int right=0;right<n;right++){
        if(s[right]=='1') ones++;

        while(ones==k){
            int len = right-left+1;
            string candidate = s.substr(left, len);

            if(len<minLen){
                minLen=len;
                ans=candidate;
            }
            else if(len == minLen && candidate<ans){
                ans=candidate;
            }

            if(s[left]=='1') ones--;
            left++;
        }
    }

    cout<<ans;
    return 0;
}