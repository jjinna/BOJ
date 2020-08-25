#include<iostream>
#include<iomanip>
using namespace std;

int N; double perc[4],ans=0;
int movdir[4][2] = { {0,1},{0,-1,},{1,0},{-1,0} };	//동,서,남,북
bool map[30][30];

void bf(int y,int x,int cnt,double percent) {
	//base case 1 : 이동경로가 단순하지 않음
	if (map[y][x]) return;
	//base case 2 : 이동경로가 단순함
	if (cnt == N) {
		ans += percent;
		return;
	}

	map[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nexty = y + movdir[i][0]; int nextx = x + movdir[i][1];
		bf(nexty, nextx, cnt + 1,percent*perc[i]);
	}
	map[y][x] = false;
}

int main() {
	//init
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < 4; i++) {
		double temp;
		cin >> temp; perc[i] = temp / 100;
	}

	bf(14, 14, 0, 1);
	cout << setprecision(10)<<ans;
}