#include<iostream>

#define NMAX 101
#define MOD 1000000000

using namespace std;

int main() {
	int N, dp[NMAX][10];
	cin >> N;

	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1]; 
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}

	//print answer
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum =(sum+dp[N][i])%MOD;
	}
	cout << sum;
}