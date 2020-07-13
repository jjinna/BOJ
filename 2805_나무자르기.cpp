#include<iostream>
#include<algorithm>
using namespace std;

#define NMAX 1000001
int input[NMAX];
int N, M;

int main() {
	scanf_s("%d %d", &N, &M);

	int max=-1;
	fill(input, input + N + 1, 0);
	for (int i = 0; i < N; i++) {
		scanf_s("%d",&input[i]);
		if (max < input[i])	max = input[i];
	}

	int left = 0;
	int right = max;
	int mid,result;
	while (left <= right) {
		mid = (left + right) / 2;
		
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (mid < input[i])	sum += input[i] - mid;
		}

		if (sum < M) {
			right = mid - 1;
		}
		else {
			result = mid;
			left = mid + 1;
		}
	}
	cout << result;
}