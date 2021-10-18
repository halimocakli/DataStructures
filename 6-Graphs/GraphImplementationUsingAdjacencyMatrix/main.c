#include <conio.h>
#include <stdio.h>

int InDegree(int arr[][5], int column)
{
	int degree = 0;
	int raw;

	for (raw = 0; raw < 5; raw++)
	{
		degree = degree + arr[raw][column];
	}
	return degree;
}

int OutDegree(int arr[][5], int raw)
{
	int degree = 0;
	int column;

	for (column = 0; column < 5; column++)
	{
		degree = degree + arr[raw][column];
	}
	return degree;
}

/* For directed graphs */
/* We can calculate the number of edges with using outdegree addition or indegree addition*/
int Edges(int arr[][5])
{
	int result = 0;
	int i;
	int j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			result = result + arr[i][j];
		}
	}
	return result;
}

int main()
{
	int adjacencyMatrix[5][5] = {{0, 1, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 1}, {0, 1, 1, 0, 0}, {0, 0, 0, 1, 0}};

	int i;
	int j;

	printf("---------------- ADJACENCY MATRIX -------------------\n\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%9d", adjacencyMatrix[i][j]);
		}
		printf("\n\n");
	}

	printf("-----------------------------------------------------\n\n");

	printf(" Indegree number of vertex[1] is: %d\n", InDegree(adjacencyMatrix, 0));
	printf(" Indegree number of vertex[2] is: %d\n", InDegree(adjacencyMatrix, 1));
	printf(" Indegree number of vertex[3] is: %d\n", InDegree(adjacencyMatrix, 2));
	printf(" Indegree number of vertex[4] is: %d\n", InDegree(adjacencyMatrix, 3));
	printf(" Indegree number of vertex[5] is: %d\n", InDegree(adjacencyMatrix, 4));

	printf("\n");

	printf(" Outdegree number of vertex[1] is: %d\n", OutDegree(adjacencyMatrix, 0));
	printf(" Outdegree number of vertex[2] is: %d\n", OutDegree(adjacencyMatrix, 1));
	printf(" Outdegree number of vertex[3] is: %d\n", OutDegree(adjacencyMatrix, 2));
	printf(" Outdegree number of vertex[4] is: %d\n", OutDegree(adjacencyMatrix, 3));
	printf(" Outdegree number of vertex[5] is: %d\n", OutDegree(adjacencyMatrix, 4));

	printf("\n");

	printf(" Number of edges int the graph is: %d\n", Edges(adjacencyMatrix));

	getch();
	return 0;
}

/*
			  2 -------* 3
		   * |*		    *|
		  /	 ||		  /  |
		1    ||     /    |   => "*" is stand for ">"
		  \  ||   /      |
		   * *| /        *
			  4 -------* 5
 */
