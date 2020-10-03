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
	int i, j, k, zeros = 0, number = cols, index = -1;
	
	for(i = 0; i < cols; i++){
		for(j = 0;j < rows; j++){
			if(matrix[j][i] == 0){
				zeros++;
			}
		}
		if(zeros > index && zeros != 0){
			index = zeros;
			zeros = 0;
			index = i;
		}
		else if(zeros == 0){
			printf("The column number %d is zeroless\n",i);
			for(k = 0; k < rows; k++){
				printf("[%d]\n", matrix[k][i]);
			}
			printf("\n\n");
		}
	}

	if(index == -1){
		printf("There is no zero in the matrix\n");
	}

	else{
		printf("Column no %d has the most numbers of zeros\n", index);
		for(i = 0; i < rows; i++){
			printf("%d\n",matrix[i][index]);
		}
	}

}