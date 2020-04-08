#include<iostream>
#define EMAX 15
#define SMAX 28
#define MMAX 19
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;

	bool flag = true;
	if ((E == S) && (S == M))	cout << E;
	else {
		int e = 0, s = 0, m = 0;
		int year = 0;
		while (1) {
			if ((e == E) && (s == S) && (m == M))	break;

			if ((e += 1) > EMAX)	e = 1;
			if ((s += 1) > SMAX)	s = 1;
			if ((m += 1) > MMAX)	m = 1;

			year++;
		}
		cout << year;
	}


}