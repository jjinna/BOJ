#include<iostream>
#define scanf scanf_s
#define MAX 31
using namespace std;

int N, M, H;	//���μ� N��, ���μ� M��, ���μ� ���� �� �ִ� ��ġ H��
int a, b;	//b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� ����
int input[MAX][MAX];
int ans = -1,ladder_num;
void init() {
	scanf("%d %d %d", &N, &M, &H);

	int yindex, xindex;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &yindex, &xindex);
		input[yindex][xindex] = 1;
	}
}

bool ladder() {
	for (int i = 1; i <= N; i++) {	//������
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (input[j][cur])	cur+=1;	//���������� �̵�
			else if (input[j][cur - 1])	cur -= 1;	//�������� �̵�
		}
		if (i != cur)	return false;
	}

	return true;
}

void dfs(int x,int cnt) {
	if (cnt > 3)	return;	//3�� �̻� ���°��
	//������ ã�� ���
	if (ladder()) { ans = cnt;}
	if (ans != -1)	return;

	//���� Ž��
	for (int i = x; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j - 1]||input[i][j+1]||input[i][j])	continue;	//���μ��� �����ϸ� �ȵ�
			input[i][j] = 1;
			dfs(i,cnt + 1);
			input[i][j] = 0;
		}
	}
}

int main() {
	init();
	dfs(1, 0);
	cout << ans;
}