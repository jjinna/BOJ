#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define NMAX 20001

using namespace std;

int visited[NMAX];
int group[NMAX];
bool isbipar = true;

void dfs(int x, vector<int>* graph) {
	visited[x] = 1;

	for (int i = 0; i < graph[x].size(); i++) {
		if (visited[graph[x][i]] == 0) {
			if (group[x] == 1)	group[graph[x][i]] = 2;
			else	group[graph[x][i]] = 1;

			dfs(graph[x][i], graph);
		}

		if (visited[graph[x][i]] == 1) {
			if ((group[x] == group[graph[x][i]])) {
				isbipar = false;
			}
		}
	}
}


int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		int V, E;
		cin >> V >> E;

		vector<int> graph[NMAX];

		fill(visited, visited + V + 1, 0);
		fill(group, group + V + 1, 0);
		isbipar = true;

		int node1, node2;
		for (int i = 0; i < E; i++) {
			cin >> node1 >> node2;

			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		for (int i = 1; i <= V; i++) {
			if (group[i] == 0) {
				group[i] = 1;
				dfs(i, graph);
			}
		}

		if (isbipar == true)	cout << "YES" << "\n";
		else	cout << "NO" << "\n";

	}
}