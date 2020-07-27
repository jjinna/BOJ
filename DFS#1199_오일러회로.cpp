#include<iostream>
#include<vector>
#define NMAX 1002

using namespace std;

int N;//������ ��
int graph[NMAX][NMAX]; int degree[NMAX];

void dfs(int here) {
	for (int i = 1; i <= N; i++) {
		while(graph[here][i]>0) {
			graph[here][i]--;
			graph[i][here]--;

			dfs(i);
		}
	}
	cout << here << " ";
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			degree[i] += graph[i][j];
		}
	}

	//������ Ȧ���� ���� Ȯ��
	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	dfs(1);
}
