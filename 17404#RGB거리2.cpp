#include<iostream>
#include<algorithm>
#include<limits.h>
#define NMAX 1001
using namespace std;

int N; int cost[NMAX][3],cache[NMAX][3];

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <3; j++) {
			cin >> cost[i][j];
		}
	}
}

int dp() {
	int minn = 1000*1000+1;

	for (int i = 0; i < 3; i++) {
		//첫번째 집 특정색 지정
		for (int j = 0; j < 3; j++) {
			if (j == i)	cache[1][j] = cost[1][j];
			else cache[1][j] = 1000*1000+1;
		}

		for (int j = 2; j <= N; j++) {
			cache[j][0] = min(cache[j - 1][1] + cost[j][0], cache[j - 1][2] + cost[j][0]);
			cache[j][1] = min(cache[j - 1][0] + cost[j][1], cache[j - 1][2] + cost[j][1]);
			cache[j][2] = min(cache[j - 1][0] + cost[j][2], cache[j - 1][1] + cost[j][2]);
		}

		//첫번째 집 색과 다른 색중에 비용 최솟값 선택
		for (int j = 0; j < 3; j++) {
			if (j == i)	continue;
			minn = min(minn, cache[N][j]);
		}
	}

	return minn;
}

int main() {
	init();
	cout<<dp();
}