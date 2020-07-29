#include<iostream>
#include<algorithm>
#define MAX 1000000

using namespace std;

int result[MAX];

int main() {
	int input;
	cin >> input;

	fill(result+1, result + input, -1);

	result[1] = 0;
	for (int i = 2; i <= input; i++) {
		if (i % 2 == 0)	result[i] = min(result[i - 1] + 1, result[i / 2] + 1);
		if (i % 3 == 0)	result[i] = min(result[i - 1] + 1, result[i / 3] + 1);
		if (i % 2 != 0 && i % 3 != 0)	result[i] = result[i - 1] + 1;
	}

	cout << result[input];
}