#include<iostream>
#include<algorithm>
#define NMAX 200001
using namespace std;

int home[NMAX];
int main() {
	int N, C;
	cin >> N >> C;

	fill(home, home + N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home, home + N);

	int min = 1;
	int max = home[N - 1];

	int cnt=0,check;
	int result=0;
	while (min <= max) {
		cnt = 1;
		check = (min + max) / 2;

		int start = home[0];
		for (int i = 1; i < N; i++) {
			if (home[i] - start >= check) { 
				start = home[i];
				cnt++; }
		}

		if(cnt>=C){
			result = check;
			min = check + 1;
		}
		else {
			max = check - 1;
		}

	}

	cout << result;

}