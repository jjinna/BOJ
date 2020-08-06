#include<iostream>
#include<vector>
#define MAX 9

using namespace std;

int N, M;
vector<int> picked;
int visited[MAX];

void comb() {
	//base case(M�� ��)
	if (picked.size() == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", picked[i] + 1);
		}printf("\n");
		return;
	}

	//���� ���ϱ�
	int smallest = picked.empty() ? 0 : picked.back();
	for (int i = smallest; i < N; i++) {
		picked.push_back(i);
		comb();
		picked.pop_back();
	}

}

int main() {
	scanf_s("%d %d", &N, &M);

	comb();
}