#include<iostream>
#include<vector>

#define MAX 9

using namespace std;

int N, M;
vector<int> picked;
void permu() {
	//base case(M개 뽑았으면 출력)
	if (picked.size() == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", picked[i] + 1);
		}printf("\n");
		return;
	}

	//순열 구하기
	for (int i = 0; i < N; i++) {
		picked.push_back(i);
		permu();
		picked.pop_back();
	}
}

int main() {
	scanf_s("%d %d", &N, &M);
	permu();
}