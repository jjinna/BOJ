#include<iostream>
#define NMAX 10
#define KMAX 100000000
using namespace std;

int input[NMAX];
int main() {
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int result = 0;
	while (N > 0) {
		if (K >= input[N-1]) {
			int temp = K / input[N-1];
			result += temp;

			K = K % input[N-1];
		}
		N--;
	}

	cout << result;
}