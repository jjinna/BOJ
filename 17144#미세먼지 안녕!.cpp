#include<iostream>
#include<vector>
#include<queue>
#define MAX 51

using namespace std;

int R, C, T,map[MAX][MAX];
int direction[4][2] = { {0,-1}, {0,1},{-1,0},{1,0} };	//좌,우,상,하

int counterClockwise[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };	//반시계방향
int clockwise[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };	//시계방향

vector<pair<int,int>> airLoc;
void init() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)	airLoc.push_back({ i,j });
		}
	}
}

//공기 청정기 작동
void wind(int mode) {
	//mode : 0 => 반시계방향, mode:1=>시계방향
	int idx = 0,yindex,xindex,nexty,nextx;

	queue<int> formove;
	formove.push(0);

	if(mode==0){
		yindex = airLoc[0].first; xindex = airLoc[0].second+1;
	}else{
		yindex = airLoc[1].first; xindex = airLoc[1].second+1;
	}

	while (1) {
		if (idx > 4)	break;

		formove.push(map[yindex][xindex]);
		map[yindex][xindex] = formove.front();
		formove.pop();

		if (mode == 0) {
			nexty = yindex + counterClockwise[idx][0]; nextx = xindex + counterClockwise[idx][1];
		}else {
			nexty = yindex + clockwise[idx][0]; nextx = xindex + clockwise[idx][1];
		}

		if (mode==0&&nexty == airLoc[0].first && nextx == airLoc[0].second)	break;
		if(mode==1 && nexty == airLoc[1].first && nextx == airLoc[1].second)	break;

		if (nexty < 0 || nextx < 0 || nexty >= R || nextx >= C) {
			idx++;
			if (mode == 0) {
				yindex+= counterClockwise[idx][0]; xindex+= counterClockwise[idx][1];
			}else {
				yindex+= clockwise[idx][0]; xindex+= clockwise[idx][1];
			}
			continue;
		}else {
			yindex = nexty; xindex = nextx;
		}
	}
}

void mapcpy(int a[MAX][MAX],int b[MAX][MAX]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void simulate() {
	int nexty,nextx,cnt,diffusion;
	int temp[MAX][MAX];
	//미세먼지 확산
	mapcpy(temp, map);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0 || map[i][j] == -1)	continue;

			//상,하,좌,우 순서대로 확산
			cnt = 0; diffusion = map[i][j] / 5;
			for (int k = 0; k < 4; k++) {
				int nexty = i + direction[k][0]; int nextx = j + direction[k][1];
				if (nexty < 0 || nextx < 0 || nexty >= R || nextx >= C)	continue;
				if (map[nexty][nextx] == -1)	continue;
				
				temp[nexty][nextx] += diffusion;
				cnt++;
			}
			temp[i][j] -= diffusion * cnt;
		}
	}
	mapcpy(map, temp);

	wind(0); wind(1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	init(); 
	for (int i = 0; i < T; i++) {
		simulate();
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1 && map[i][j] != 0)	ans += map[i][j];
		}
	}
	cout << ans;
}