#include<iostream>
using namespace std;
const int N = 1e5 + 5;
int a[N]{0}, Opr[N]{0}, Diff[N]{0};
int l[N]{0}, r[N]{0}, d[N]{0};

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <=m; i++)
        cin >> l[i] >> r[i] >> d[i];


        for(int i=1; i<=k; i++){
            int x,y;
            cin >> x >> y;

                Opr[x]++;
                Opr[y+1]--;
        }

        for(int i=1; i<=m; i++){//priffix sum
            Opr[i] += Opr[i-1];
        }

        for(int i=1; i<=m; i++){// operation count
            cout << Opr[i] << " ";
        }


        for(int i=1; i<=m; i++){// diiference array
            Diff[l[i]] += Opr[i] * d[i];
            Diff[r[i]+1] -= Opr[i] * d[i];
        }

        for(int i=1;i<=n; i++){// intermediate difference array
            Diff[i] += Diff[i-1];
        }

        for(int i=1; i<=n; i++){ //final difference array
            cout << Diff[i] << " ";
        }

        for(int i=1; i<=n; i++){
            cout << a[i] + Diff[i] << " ";
        }
}
