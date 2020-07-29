#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>

#define MAX 10
using namespace std;

int N, M, input[MAX][MAX], copying[MAX][MAX];
int result = 0; bool visited[MAX][MAX];

//상하좌우
int dy[4] = { -1,1,0,0}, dx[4] = { 0,0,-1,1 };

void spread_virus() {
    queue<pair<int, int>> virus;
    int afterSpread[MAX][MAX];
    
    memset(visited, false, sizeof(visited));

    //배열 복사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            afterSpread[i][j] = copying[i][j];
            if (afterSpread[i][j] == 2)   virus.push(make_pair(i, j));
        }
    }
    
    int cury, curx, nexty, nextx;
    while (!virus.empty()) {
        cury = virus.front().first;
        curx = virus.front().second;
        virus.pop();
        visited[cury][curx] = true;

        for (int i = 0; i < 4; i++) {
            nexty = cury + dy[i];nextx = curx + dx[i];
            if (nexty < 0 || nexty >= N || nextx < 0 || nextx >= M)   continue;
            if (!visited[nexty][nextx]&&afterSpread[nexty][nextx] == 0) {
                afterSpread[nexty][nextx] = 2;
                visited[nexty][nextx] = true;
                virus.push(make_pair(nexty, nextx));
            }
        }
    }

    //안전영역 구하기
    int size = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (afterSpread[i][j] == 0)   size++;
        }
    }
   
    result = max(size, result);
}

void setWall(int cnt) {
    //base case
    if (cnt == 3) {
        spread_virus();
        return;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copying[i][j] == 0)
            {
                copying[i][j] = 1;
                setWall(cnt + 1);
                copying[i][j] = 0;
            }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i][j] == 0)
            {
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < M; l++) {
                        copying[k][l] = input[k][l];
                    }
                }
                copying[i][j] = 1;
                setWall(1);
                copying[i][j] = 0;
            }
        }
    }
    cout << result << endl;
}
