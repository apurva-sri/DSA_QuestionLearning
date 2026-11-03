#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>> s;
    
    //When we are not specifically given the small letters then we take 256 size of hash array because we have 256 characters in total in ASCII table.
    int hash[256] ={0};

    for(int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    //When we are specifically given the small letters then we can take 26 size of hash array because we have 26 small letters in total.
    int hash2[26]={0};

    for(int j=0; j<26; j++){
        hash2[s[j] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(hash[i] > 0)
        {
            cout<< (char)(i + 'a') << " " << hash[i] << endl;
        }
    }
    return 0;
}