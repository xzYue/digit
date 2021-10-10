#include <bits/stdc++.h>

using namespace std;

#define int long long

//const int maxn=1e7;
const int mod=1e9+7;
int t;
int l,r;
int a[20],num;
int dp[20][200];
int dfs(int pos, int sum, bool top){//此题state为sum
	if(!pos) return sum;//如果已经到了最后一位就可以直接返回sum 
	if(!top && dp[pos][sum] >= 0) return dp[pos][sum];//最高位是0也直接返回 
	int bound = top?a[pos]:9;//根据top判断枚举的上界boundXianzhu
	int ret=0;
	for(int i=0; i<=bound; i++)
        ret = (ret + dfs(pos-1, sum+i, top && i==bound)) % mod;
	/*
		这里大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论
        去计算不同情况下的个数，这里一定要保存枚举的这个数是合法
	*/ 
	if(!top) dp[pos][sum]=ret;//这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑top，这里就是top就完全不用考虑了*
	return ret;
}

int solve(int x){
	int pos = 0;
	while(x){
		a[++pos] = x % 10;
		x /= 10;
	}
	return dfs(pos, 0, 1) % mod;//从最高位开始枚举,初始state（数位和sum）为0
}

signed main(){
	memset(dp, -1, sizeof(dp));

	cin>>t;
	while(t--){
		cin>>l>>r;
//        cout<<endl;
		cout<<(solve(r) - solve(l-1) + mod) % mod<<endl;
	}
	return 0;
}


