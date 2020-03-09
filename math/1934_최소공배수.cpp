#include<iostream>

using namespace std;

int getGCD(int a, int b) {
	if (b == 0)	return a;
	else
	{
		return getGCD(b, a % b);
	}
}

int main() {
	int t_case;
	cin >> t_case;

	int A, B;
	while (t_case--) {
		cin >> A >> B;
		cout << A*B/getGCD(A, B) << "\n";

	}
}