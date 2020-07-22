#include<iostream>
#include<memory.h>
#define MAX 50

using namespace std;

int input[MAX][MAX];	//1은 땅,0은 바다
int visited[MAX][MAX];
int w, h;

int nexth[8] = {-1,-1,-1,0,1,1,1,0};
int nextw[8] = {-1,0,1,1,1,0,-1,-1};
void dfs(int hindex,int windex) {
	visited[hindex][windex] = 1;

	for (int i = 0; i < 8; i++) {
		int hidx = nexth[i] + hindex;
		int widx = nextw[i] + windex;

		if (!visited[hidx][widx] && input[hidx][widx])	dfs(hidx, widx);
	}
}

int main() {
	while (1) {
		//초기화 및 입력받음
		int result = 0;
		memset(input, 0, sizeof(input));
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;

		if (w == 0 && h == 0)	break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> input[i][j];
			}
		}

		//함수실행
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j]&&input[i][j]) {
					dfs(i, j); result++;
				}
			}
		}

		cout << result << endl;
	}
}