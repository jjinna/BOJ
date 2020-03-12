#include<iostream>
#include<vector>
#include<algorithm>
#define NMAX 1001

using namespace std;

int visited[NMAX];
vector<int> input;
void make_graph(int x) {
	visited[x] = 1;

	if (visited[input[x]] == 0) {
		make_graph(input[x]);
	}
}

int main() {
	int t_case;
	cin >> t_case;

	int N;
	while (t_case--) {
		cin >> N;
		input.clear();
		input.push_back(0);
		fill(visited, visited + N + 1, 0);
		
		for(int i=0;i<N;i++) {
			int num;
			cin >> num;
			input.push_back(num);
		}

		int cnt=0;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				make_graph(i);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}