#include<iostream>
#include<queue>

using namespace std;

int F, S, G, U, D;	//ÃÑFÃş, ÇöÀçSÃş, ½ºÅ¸Æ®¸µÅ©GÃş
int visited[1000001];
int bfs(int stair) {
	queue<int> result;
	result.push(stair);
	visited[stair] = 1;

	int curStair;
	while (!result.empty()) {
		curStair = result.front();
		result.pop();

		//¸ñÇ¥Ãş¿¡ µµ´Ş
		if (curStair == G) {
			cout << visited[curStair]; return 0;
		}

		if (curStair + U <= F && !visited[curStair + U]) {
			result.push(curStair + U);
			visited[curStair + U] = visited[curStair] + 1;
		}
		if (curStair - D > 0 && !visited[curStair - D]) {
			result.push(curStair - D);
			visited[curStair - D] = visited[curStair] + 1;
		}

	}
	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	if(bfs(S)==-1)	cout<<"use the stairs";
}