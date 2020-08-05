#include<iostream>
#include<queue>

#define MAX 102
using namespace std;

int N, K,L;	//N:������ ũ��, K:����� ����, L:���� ���� ��ȯ Ƚ��
int board[MAX][MAX];
queue<pair<int, int>> turnInfo;	//<X��,����(1:������,-1:����)>
queue<pair<int, int>> tailInfo;
int nexty[4] = {0,1,0,-1},nextx[4] = {1,0,-1,0};	//�̵�����(������,�Ʒ�,����,��)

void init() {
	cin >> N;
	cin >> K;

	int temp1, temp2;
	for (int i = 0; i < K; i++) {
		cin >> temp1 >> temp2;
		board[temp1][temp2] = 2;
	}

	cin >> L;

	int temp3; char temp4;
	for (int i = 0; i < L; i++) {
		cin >> temp3 >> temp4;
		if (temp4 == 'D') {	//������
			turnInfo.push({ temp3,1 });
		}else {	//����
			turnInfo.push({ temp3,-1 });
		}
	}

	board[1][1] = 1;	//���� ���� ��ġ : (1,1)
}

int bfs() {
	int curMovedir = 0, curTime = 0, turnTime;
	int taily = 1, tailx = 1, heady = 1, headx = 1;
	int temp1, temp2;
	while (1) {
		curTime++;

		//�Ӹ� �̵�
		heady += nexty[curMovedir];
		headx += nextx[curMovedir];

		tailInfo.push({ heady,headx });

		if (heady<1 || headx<1 || heady>N || headx>N) { return curTime; }	//���� ���
		if (board[heady][headx] == 1) { return curTime; }

		if (board[heady][headx] == 0) {	//���������, �� ������
			board[taily][tailx] = 0;
			board[heady][headx] = 1;

			taily = tailInfo.front().first;
			tailx = tailInfo.front().second;
			tailInfo.pop();
		}
		else if (board[heady][headx] == 2) {	//��������� �� �ø�
			board[heady][headx] = 1;
		}

		if (!turnInfo.empty()) {
			turnTime = turnInfo.front().first;

			//������ȯ�ð�
			if (curTime == turnTime) {
				curMovedir += turnInfo.front().second;
				turnInfo.pop();

				if (curMovedir == -1)	curMovedir = 3;
				else if (curMovedir == 4)	curMovedir = 0;
			}
		}
	}
}
int main() {
	init();
	cout<<bfs();
}