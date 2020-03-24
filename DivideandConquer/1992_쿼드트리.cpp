#include<iostream>
#include<cstdio>
#include<memory.h>
#include<string>
#define NMAX 64

using namespace std;

int inputArray[NMAX][NMAX];

int checking(int xstart, int ystart, int size) {
	int num = inputArray[xstart][ystart];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (inputArray[xstart + i][ystart + j] != num)	return -10;
		}
	}

	return num;
}

void quadTree(int xstart,int ystart,int size) {
	int result = checking(xstart,ystart,size);

	
	if(result==-10) {
		cout << "(";
		quadTree(xstart ,ystart,size/2);
		quadTree(xstart, ystart + (size / 2), size / 2);
		quadTree(xstart + (size / 2), ystart, size / 2);
		quadTree(xstart + (size / 2), ystart + (size / 2), size / 2);
		cout << ")";
	}
	else {
		cout << result;

	}
	
}

int main() {
	int N;
	cin >> N;
	memset(inputArray, 0, sizeof(inputArray));

	string temp[NMAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d",&inputArray[i][j]);
		}
	}

	quadTree(0,0,N);
}