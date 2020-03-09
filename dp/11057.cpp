#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[10][1001];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; i++) dp[i][1] = 1;

	int sum = 0;
	for (int i = 2; i <= n; i++) {
		sum = 0;
		for (int k = 0; k < 10; k++) {
			sum += dp[k][i - 1];
		}

		for (int j = 0; j < 10; j++) {
			if (j == 0)	dp[j][i] = sum%10007;
			else
			{
				sum -= dp[j - 1][i - 1];
				dp[j][i] = sum%10007;
			}
		}
	}

	sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[i][n];
	}
	cout << sum;
}