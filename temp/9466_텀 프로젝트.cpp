#include<iostream>
#include<vector>
#include<algorithm>

#define VMAX 100001

using namespace std;

int graph[VMAX];
int visited[VMAX];
int team[VMAX];

int dfs(int x,int team_num,int cnt) {
	int next = graph[x];

	if (visited[x] == 0) {
		team[x] = team_num;
		visited[x] = cnt;
		return dfs(next,team_num,cnt+1);
	}
	else {
		if (team_num == team[next]) {
			return cnt-visited[x];
		}
		else {
			return 0;
		}
	}
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		int v_num;
		cin >> v_num;

		fill(graph, graph + VMAX + 1, 0);
		fill(visited, visited + VMAX + 1, 0);
		fill(team, team + VMAX + 1, 0);

		int input;
		for (int i = 1; i <= v_num; i++) {
			cin >> input;
			graph[i] = input;
		}
		
		int ans=0;
		for (int i = 1; i <= v_num; i++) {
			ans+=dfs(i,i,1);
		}

		cout << v_num-ans<<"\n";
		
	}
}
