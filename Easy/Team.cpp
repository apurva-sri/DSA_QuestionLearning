#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sol[3], sureCount=0, problems=0;
    while (n--)
    {
      for(int i=0;i<3;i++){
        cin>>sol[i];
        if(sol[i]==1) sureCount++;
      }
      if (sureCount >= 2)problems++;
      sureCount=0;
    }

    cout<<problems<<endl;
    return 0;
}
