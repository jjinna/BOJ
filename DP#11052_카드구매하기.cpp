#include<iostream>
#include<algorithm>

#define NMAX 1001
using namespace std;

int cardPrice[NMAX];

int main() {
	int N;
	cin >> N;
	
	//�� ī���� ���� ����
	cardPrice[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cardPrice[i];
	}

	//dp�� ���� �ִ� ���
	int dp[NMAX] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + cardPrice[j]);
		}
	}
	cout << dp[N];
}