#include<iostream>
#define KMAX 10000
#define NMAX 1000000
using namespace std;

int input[KMAX];
int main() {
	int K, N;
	cin >> K >> N;

	cin >> input[0];
	long long max = input[0];
	for (int i = 1; i < K; i++) {
		cin >> input[i];
		if (input[i] >max)	max = input[i];
	}

	long long low = 1, high = max;
	long long middle,result;
	int lineNum;//몇개 만들 수 있는지
	long long temp;
	while (low <= high) {
		lineNum = 0;
		middle = (low + high) / 2;

		for (int i = 0; i < K; i++) {
			temp = input[i] / middle;
			lineNum += temp;
		}

		if (lineNum >= N) {
			result = middle;
			low = middle + 1;
		}
		else {
			high = middle - 1;

		}	
	}

	cout << result;
}