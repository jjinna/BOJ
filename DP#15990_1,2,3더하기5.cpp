#include<iostream>

#define NMAX 100001
#define MOD 1000000009
using namespace std;

long long dp[NMAX][4]; int n;

int main() {
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= NMAX; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	int t_case;
	cin >> t_case;

	while (t_case--) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << endl;
	}

}