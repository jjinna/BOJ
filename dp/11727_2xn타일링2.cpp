#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int input;
	int result[1001];

	cin >> input;
	fill(result, result + input + 1, -1);

	result[1] = 1;
	result[2] = 3;

	for (int i = 3; i <= input; i++) {
		result[i] = (2 * result[i - 2] + result[i - 1]) % 10007;
	}

	cout << result[input] << "\n";
}