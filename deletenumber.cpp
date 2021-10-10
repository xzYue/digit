#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int,vector<int>,greater<int> > s;
inline void print(int n) {
    if(n>9) print(n/10);
    putchar(n%10+48);}
signed main()
{
    s.push(1);
    for(int i=2;i<=1<<21;i++)
    {
        int p=1,l=i;
        while(l!=1)
        {
            if(l&1)
            {
                p=(p<<2)+5;
                l=l>>1;
            }
            else
            {
                p=(p<<1)+1;
                l=l>>1;
            }
        }
        if(p>0) s.push(p);
    }
    while(!s.empty())
    {
        print(s.top());
        putchar(' ');
        s.pop();
    }
    return 0;
}