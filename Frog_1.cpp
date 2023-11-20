#include <bits/stdc++.h>
#define int long long
using namespace std;
int N;
vector<int> C;
vector<int> DP;
int f(int x){
	if(x == N-1) return 0;
	if(DP[x] != -1) return DP[x];
	int resposta = f(x +1) + abs(C[x] - C[x+1]);
	if(x + 2 < N){
		int p2 = f(x +2) + abs(C[x] - C[x+2]);
		resposta = min(resposta, p2);
	}
	return DP[x] = resposta;
}
signed main(){
	cin >> N;
	C = vector<int>(N);
	DP = vector<int>(N +5, -1);
	for(int i =0; i < N; i++) cin >> C[i];
	
	cout << f(0) << '\n';
}
