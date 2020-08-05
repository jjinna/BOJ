#include<iostream>
#include<algorithm>

#define NMAX 9
using namespace std;

int main() {
	int N;
	cin >> N;

	int permu[NMAX];
	for (int i = 0; i < N; i++)	permu[i] = i + 1;
	
	do{
		for (int i = 0; i < N; i++) {
			printf("%d ", permu[i]);
		}printf("\n");
	} while (next_permutation(permu, permu + N));
}