#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int input[2][100001],result[2][100001];

int main() {
	int t_case,n;
	cin >> t_case;
	while (t_case--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> input[0][i];
		
		for (int i = 1; i <= n; i++)
			cin >> input[1][i];

		memset(result, -1,sizeof(result));

		result[0][0] = result[1][0] = 0;
		result[0][1] = input[0][1];
		result[1][1] = input[1][1];

		for (int i = 2; i <= n; i++) {
			result[0][i] = max(result[1][i - 1], result[1][i - 2]) + input[0][i];
			result[1][i] = max(result[0][i - 1], result[0][i - 2]) + input[1][i];
		}
		cout << max(result[0][n],result[1][n]);
	}
}