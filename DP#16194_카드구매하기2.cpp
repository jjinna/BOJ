#include<iostream>
#include<algorithm>
#define NMAX 1001

using namespace std;

int input[NMAX], cache[NMAX];
int main() {
	//init
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}

	//dp
	cache[0] = 0;
	for (int i = 1; i <= N; i++) {
		int temp = 99999;
		for (int j = 0; j < i; j++) {
			temp = min(temp, cache[j] + input[i - j]);
		}
		cache[i] = temp;
	}

	cout << cache[N];
}