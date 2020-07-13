//Àç±Í
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int visited[300000];
int index = 1;
int result;
void get_graph(int A,int P) {
	visited[A] = index;

	int next=0;
	while (A != 0) {
		next += pow(A % 10,P);
		A /= 10;
	}

	if (visited[next] == 0) {
		index++;
		get_graph(next, P);
	}
	else {
		result = visited[next] - 1;
	}
}

int main() {
	int A, P;
	cin >> A >> P;

	fill(visited, visited + 300000 + 1, 0);
	get_graph(A, P);

	cout << result << endl;
}