#include<iostream>
#include<algorithm>

#define MAX 1000001
using namespace std;

int N,B,C,input[MAX];
long long result=0;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cin >> B >> C;
}

void ps() {
	for (int i = 0; i < N; i++) {
		//감독관 1명
		input[i] -= B; result++;

		//부감독
		if (input[i] >0) {
			if (input[i] % C == 0)	result += input[i] / C;
			else result+= (input[i] / C) + 1;
		}

	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	init();
	ps();
	cout << result;
}