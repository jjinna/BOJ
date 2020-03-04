#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int result[10001], coin_val[101];
	int n, k;

	cin >> n >> k;
	
	fill(result, result + k+1, 10001);
	result[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> coin_val[i];
		for (int j = coin_val[i]; j <= k; j++)
			result[j] = min(result[j], result[j - coin_val[i]] + 1);
	}

	if (result[k] == 10001)	cout << "-1" << endl;
	else cout << result[k] << endl;

}