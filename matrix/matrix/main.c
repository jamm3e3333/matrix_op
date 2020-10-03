#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void print_column(int **matrix, int rows, int cols);

int main(){
	int i, j, r = 3, c = 4;
	int **mat;

	mat = (int**)malloc(sizeof(int*)*r);

	if(mat == NULL){
		printf("Error of dyn allocation\n");
	}

	for(i = 0; i < r; i++){
		mat[i] = (int*)malloc(sizeof(int)*c);
		if(mat[i] == NULL){
			printf("Error of dyn allocation\n");
			free(mat[i]);
			free(mat);
			return 0;
		}
	}

	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("Put the element matrix[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
			printf("\n");
		}
	}

	print_column(mat, r, c);

	for(i = 0; i < r; i++){
		free(mat[i]);
	}
	free(mat);

	return 0;
}

void print_column(int **matrix, int rows, int cols){
	int i, j, k, zeros = 0, index = -1;
	
	for(i = 0; i < cols; i++){
		for(j = 0;j < rows; j++){
			if(matrix[j][i] == 0){
				zeros++;
			}
		}
		if(zeros > index && zeros != 0){
			zeros = 0;
		}
		else if(zeros == 0){
			index = i;
			printf("The column number %d is zeroless\n",index);
			for(k = 0; k < rows; k++){
				printf("[%d]\n", matrix[k][i]);
			}
			printf("\n\n");
		}
	}
	
	if(index == -1){
		printf("There\'s no such a column in the matrix that has no zero.\n");
	}
}