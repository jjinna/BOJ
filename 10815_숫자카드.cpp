#include<iostream>
#include<algorithm>
#define NMAX 500000
#define MMAX 500000
using namespace std;

int inputN[NMAX];
int inputM[MMAX];
int result[MMAX];
int main() {
	int N,M;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputN[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> inputM[i];
	}

	sort(inputN, inputN + N);
	fill(result, result + M + 1, 0);

	int low, high,mid;
	bool flag = false;
	for (int i = 0; i < M; i++) {
		int target = inputM[i];
		flag = false;
		low = 0; high = N - 1;
		while (flag==false&&low <= high) {
			mid = (low + high) / 2;

			if (inputN[mid] == target) {
				flag = true;
				result[i] = 1;
			}
			else {
				if (inputN[mid] > target)	high=mid-1;
				else
				{
					low=mid+1;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cout << result[i] << " ";
	}
}