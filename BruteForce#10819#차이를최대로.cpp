#include <iostream>
#include<memory.h>
#define MAX 8

using namespace std;

int N;
bool visited[MAX];
int input[MAX];
int seq[MAX];

int getSum() {
	int ret = 0;
	for (int i = 0; i < N-1; i++) {
		ret += abs(seq[i] - seq[i + 1]);
	}
	return ret;
}

void makeSeq(int PickSeq,int& max) {
	//base case
	if (PickSeq == N) {
		if (getSum() > max)	max = getSum();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i]=true;
			seq[PickSeq] = input[i];

			makeSeq(PickSeq + 1,max);

			visited[i] = false;
			seq[PickSeq] = -1;
		}
	}

}


int main() {
	cin >> N;

	memset(visited, false, sizeof(visited));
	memset(seq, -1, sizeof(seq));
	
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int max = -1;
	makeSeq(0, max);
	cout << max;
}