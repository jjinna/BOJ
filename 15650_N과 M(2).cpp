#include<iostream>
#include<vector>
#define MAX 9

using namespace std;

int N, M;
vector<int> picked;
int visited[MAX];

void comb() {
	//base case(M개 고름)
	if (picked.size() == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", picked[i]+1);
		}printf("\n");
	}

	//조합 구하기
	int smallest = picked.empty() ? 0 : picked.back()+1;
	for (int i = smallest; i < N; i++) {
		if (visited[i])	continue;
		visited[i] = 1;
		picked.push_back(i);

		comb();

		visited[i] = 0;
		picked.pop_back();
	}

}

int main() {
	scanf_s("%d %d", &N, &M);

	comb();
}