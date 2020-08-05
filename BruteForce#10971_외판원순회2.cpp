#include<iostream>
#include<limits.h>
#define NMAX 11
using namespace std;

int N, visited[NMAX],permutation[NMAX],cost[NMAX][NMAX],minCost=INT_MAX;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
}

void traverse(int depth) {
	//base case(��絵�� �湮)
	if (depth == N) {
		int sum = 0;
		for (int i = 0; i < depth; i++) {
			//������ ���ö�� ���� ��δ� ��ߵ���
			if (i == depth - 1) { 
				if (cost[permutation[i]][permutation[0]] == 0)	return;
				sum += cost[permutation[i]][permutation[0]];	
				continue; 
			}

			if (cost[permutation[i]][permutation[i + 1]] == 0)	return;	//���ð� ����Ǿ����� �ʴٸ� return
			sum += cost[permutation[i]][permutation[i + 1]];
		}
		if (sum < minCost)	minCost = sum;
		return;
	}

	//����
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			permutation[depth] = i;

			traverse(depth + 1);

			visited[i] = 0;
		}
	}
}

int main() {
	init();
	traverse(0);
	cout << minCost;
}