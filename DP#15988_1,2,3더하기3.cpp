#include<iostream>

using namespace std;

long long dp[1000001];
int main() {
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 1000001; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}

	int t_case;
	cin >> t_case;
	while (t_case--) {
		int n;
		cin >> n;

		cout << dp[n] << endl;
	}
}