#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int max = 0;
	while (N >= 2 && M >= 1) {
		N -= 2;
		M -= 1;
		max++;
	}

	while (N + M < K) {
		N += 2;
		M++;
		max--;
	}

	cout << max;
}