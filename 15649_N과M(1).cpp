#include<iostream>
#include<vector>

#define MAX 9

using namespace std;

int N, M;
int visited[9];
vector<int> picked;
void permu() {
	//base case(M�� �̾����� ���)
	if (picked.size() == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", picked[i] + 1);
		}printf("\n");
		return;
	}

	//���� ���ϱ�
	for (int i = 0; i < N; i++) {
		if (visited[i])	continue;
		visited[i] = 1;
		picked.push_back(i);

		permu();

		visited[i] = 0;
		picked.pop_back();
	}
}

int main() {
	scanf_s("%d %d", &N, &M);
	permu();
}