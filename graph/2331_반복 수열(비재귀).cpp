
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int visited[300000];
int index = 1;
int result;
int get_graph(int A, int P) {
	
	int next = A;
	while (visited[next] == 0) {
		visited[next] = index;

		int temp=0;
		while (next != 0) {
			temp += pow(next % 10, P);
			next /= 10;
		}

		next = temp;
		index++;
	}


	return visited[next] - 1;
}

int main() {
	int A, P;
	cin >> A >> P;

	fill(visited, visited + 300000 + 1, 0);
	result=get_graph(A, P);

	cout << result << endl;
}