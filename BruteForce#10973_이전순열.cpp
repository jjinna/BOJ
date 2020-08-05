#include<iostream>
#include<algorithm>
#define NMAX 10001

using namespace std;

int input[NMAX]; int N;
void using_library() {
	if (next_permutation(input, input + N)) {
		for (int i = 0; i < N; i++) {
			cout << input[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
}

void not_using_library() {
	int i = N - 1;
	while (i > 0 && input[i - 1] < input[i])	i -= 1;
	if (i <= 0) { cout << "-1"; return; }
	int j = N - 1;
	while (input[j] > input[i - 1])	j -= 1;
	swap(input[i - 1], input[j]);
	j = N - 1;
	while (i < j) {
		swap(input[i], input[j]);
		i += 1; j -= 1;
	}

	for (int i = 0; i < N; i++) {
		cout << input[i] << " ";
	}
}


int main() {
	//init
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	not_using_library();
}