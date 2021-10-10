#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int MaxN=20000009;
bool a[MaxN];
int s[100001];

signed main(){
    int i, j;
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    i = 1;
    a[i] = 1;
    while(i <= 5000000){
        if(a[i] == 1){
            a[2*i+1] = 1;
            a[4*i+5] = 1;
        }
        i++;
    }
    i=1;
    for(j=1; j<MaxN; j++){
        if(a[j]==1){
            s[i++]=j;
            cout<<j<<' ';
        }
    }
    cout<<endl<<i<<endl;
    return 0;
}

