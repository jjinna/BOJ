#include<iostream>

using namespace std;


int main() {
	int t_case;
	cin >> t_case;

	int input;
	int result[12];
	while (t_case--) {
		cin >> input;

		fill(result, result + input + 1, -1);
		result[1] = 1;
		result[2] = 2;
		result[3] = 4;
		for (int i = 4; i <= input; i++) {
			result[i] = result[i - 1] + result[i - 2] + result[i - 3];
		}

		cout << result[input]<<"\n";
	}
}