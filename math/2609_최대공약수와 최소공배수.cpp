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
	int input1, input2;
	cin >> input1 >> input2;

	cout << getGCD(input1, input2) << "\n";
	cout << input1 * input2 / getGCD(input1, input2) << "\n";

}