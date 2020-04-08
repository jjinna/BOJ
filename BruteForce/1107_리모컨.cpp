#include<iostream>
#include<cmath>
using namespace std;

bool broken[10] = { false, };
int possible(int x) {
	if (x == 0) {
		if (broken[0])	return 0;
		else return 1;
	}

	int len = 0;
	while (x > 0) {
		if (broken[x % 10])	return 0;
		len += 1;
		x /= 10;
	}

	return len;
}


int main() {
	int N;
	cin >> N;

	int input,temp;
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> temp;
		broken[temp] =true;
	}

	//1. +나 -만 누르는 경우
	int result;
	result = abs(N - 100);

	//2. 완전탐색
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);

		if (len > 0) {
			int press = abs(c - N);
			if (result > len + press)	result = len + press;
		}
	}
	
	cout << result;
}