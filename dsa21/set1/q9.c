#include <stdio.h>
int i,j;
int main() {
	int m,n;
	printf("Enter number of rows and columns (separated by space): ");
	scanf("%d %d",&m,&n);
	int matrix[100][100];
	printf("Enter elements of matrix: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}

	int arr[m * n];

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			int ind = i * n + j;
			arr[ind] = matrix[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			int ind = i * n + j;
			printf("2D:(%d,%d) -> 1D:%d\t ",i,j,ind);            
			printf("Element at %d in 1D array: %d\n", ind, arr[ind]);
		}
	}

	return 0;
}
