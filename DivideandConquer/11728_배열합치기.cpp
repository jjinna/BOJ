#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int N, M;
vector<int> merge(vector<int> N_array, vector<int> M_array);

int main() {
	scanf("%d %d",&N,&M);

	vector<int> N_array(N);
	vector<int> M_array(M);

	int temp;
	int index = 0;
	for(int i=0;i<N;i++) {
		scanf("%d", &N_array[index++]);
	}
	index = 0;
	for(int i=0;i<M;i++) {
		scanf("%d", &M_array[index++]);
	}

	vector<int> result=merge(N_array,M_array);

	for (int i = 0; i < N+M; i++) {
		printf("%d ",result[i]);
	}
}


vector<int> merge(vector<int> N_array, vector<int> M_array) {
	vector<int> result;
	int nPointer = 0, mPointer = 0;
	int index = 0;
	while (nPointer < N && mPointer < M) {
		if (N_array[nPointer] < M_array[mPointer]) {
			result.push_back(N_array[nPointer++]);
		}
		else {
			result.push_back(M_array[mPointer++]);
		}
	}

	if (M== mPointer) {
		for (int i = nPointer; i < N; i++) {
			result.push_back(N_array[i]);
		}
	}
	else if (N == nPointer) {
		for (int i = mPointer; i < M; i++) {
			result.push_back(M_array[i]);
		}
	}
	return result;
}