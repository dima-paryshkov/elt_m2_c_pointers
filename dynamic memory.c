#include <stdio.h>       
#include <stdlib.h>

float* enterArray(int* dimension)
{
	fprintf(stdout, "Write dimension of rectangular matrix in the format: n m\n");
	fscanf_s(stdin, "%d%d", dimension, dimension + 1);

	float** rectangularMatrix = (float*)malloc(sizeof(float) * (*dimension) * (*(dimension + 1)));

	fprintf(stdout, "Write array element. You can use space and line translation!\n");
	for (int i = 0; i < (*dimension); i++)
		for (int j = 0; j < (*(dimension + 1)); j++)
			fscanf_s(stdin, "%f", rectangularMatrix + i * *(dimension)+j);

	fprintf(stdout, "\n");

	return rectangularMatrix;
}

float* defaultArray(int* dimension)
{
	*dimension = 2;
	*(dimension + 1) = 2;

	float* rectangularMatrix = (float*)malloc(sizeof(float) * (*dimension) * (*(dimension + 1)));

	for (int i = 0; i < (*dimension); i++)
		for (int j = 0; j < (*(dimension + 1)); j++)
			*(rectangularMatrix + i * *(dimension)+j) = (rand() % 50) / 10;

	return rectangularMatrix;
}

void outputArray(float* rectangularMatrix, int* dimension)
{
	for (int i = 0; i < *dimension; i++, fprintf(stdout, "\n"))
		for (int j = 0; j < (*(dimension + 1)); j++)
			fprintf(stdout, "%.2f ", *(rectangularMatrix + i * *(dimension)+j));
}

int main()
{
	float** matrixs = (float**)malloc(sizeof(float*));
	int** dimensions = (int**)malloc(sizeof(int*));
	int curCountOfMatrix = 0;
	while (1)
	{
		fprintf(stdout, " 1. Add new matrix\n 2. Print all matrixs\n 3. Exit\n");
		int decision;
		fscanf_s(stdin, "%d", &decision);
		switch (decision)
		{
		case 1:
			curCountOfMatrix++;
			matrixs = (float**)realloc(matrixs, sizeof(float*) * curCountOfMatrix);
			dimensions = (int**)realloc(dimensions, sizeof(int*) * curCountOfMatrix);

			dimensions[curCountOfMatrix - 1] = (int*)malloc(sizeof(int) * 2);
			fprintf(stdout, "Do you want use default matrix 2x2 with random value? (y/n)\n");
			char decisionCh;
			while (1)
			{
				decisionCh = getchar();
				decisionCh = getchar();
				if (decisionCh == 'n')
				{
					matrixs[curCountOfMatrix - 1] = enterArray(dimensions[curCountOfMatrix - 1]);
					break;
				}
				else if (decisionCh == 'y')
				{
					matrixs[curCountOfMatrix - 1] = defaultArray(dimensions[curCountOfMatrix - 1]);
					break;
				}
				else fprintf(stdout, "Incorrct character. Write y - if yes, n - if no. \n");
			}
			break;

		case 2:
			for (int i = 0; i < curCountOfMatrix; i++, fprintf(stdout, "\n"))
			{
				fprintf(stdout, "Matrix number %d\n", i + 1);
				outputArray(matrixs[i], *(dimensions + i));
			}
			break;

		case 3:
			return 0;

		default:
			fprintf(stdout, "Incorrect number of menu. Try again!\n");
		}
	}

}