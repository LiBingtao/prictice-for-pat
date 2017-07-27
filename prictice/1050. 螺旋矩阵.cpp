#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 

int compare(const void *p, const void *q);

int main()
{
	int N;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i<N; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, N, sizeof(int), compare);
	int row = ceil(sqrt(N));
	int col = sqrt(N);
	while (row * col != N) {
		if (row * col < N) {
			row++;
		}
		else if (row * col > N) {
			col--;
		}
	} // 计算行数与列数 

	int b[row][col];
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			b[i][j] = 0;
		}
	} // 二维数组初始化 

	int i = 0, j = 0;
	int count = 0;
	while (count != N) {
		for (; j<col; j++) {
			if (!b[i][j]) {
				b[i][j] = a[count++];
			}
			else {
				break;
			}
		} // 向右走 
		j--; // 退出不满足的列 
		i++; // 进入下一行 
		for (; i<row; i++) {
			if (!b[i][j]) {
				b[i][j] = a[count++];
			}
			else {
				break;
			}
		} // 向下走 
		i--; // 退出不满足的行 
		j--; // 进入下一列 （向左） 
		for (; j >= 0; j--) {
			if (!b[i][j]) {
				b[i][j] = a[count++];
			}
			else {
				break;
			}
		} // 向左走 
		i--; // 进入下一行 （向上） 
		j++; // 退出不满足的列 
		for (; i >= 0; i--) {
			if (!b[i][j]) {
				b[i][j] = a[count++];
			}
			else {
				break;
			}
		} // 向上走 
		i++; // 退出不满足的行（下一步向右） 
		j++; // 进入下一列（向右）                               
	}

	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			printf("%d", b[i][j]);
			if (j < col - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}

int compare(const void *p, const void *q) {
	int x = *(int *)p;
	int y = *(int *)q;
	if (x > y) {
		return -1;
	}
	else if (x < y) {
		return 1;
	}
	return 0;
}