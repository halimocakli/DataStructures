#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/* Komsuluk listesinde bulunan dugumleri temsil eden struct */
struct AdjListNode {
	int destination;
	struct AdjListNode* next;
};
typedef struct AdjListNode AdjListNode;

/* Komsuluk listesini temsil eden struct */
struct AdjList {
	AdjListNode* head;
};
typedef struct AdjList AdjList;

/*
 * Graph yapısını temsil eden struct.
 * Graf bir komşuluk listesi dizisidir.
 * Bu dizinin boyutu "vertices" olarak
 * yaratılan değişkendir. "vertices" graftaki
 * tepe sayısını temsil etmektedir. */
struct Graph {
	int vertices;
	AdjList* array;
};
typedef struct Graph Graph;

/* Yeni bir komsuluk listesi dugumu ureten fonksiyon */
AdjListNode* CreateAdjListNode(int _destination)
{
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->destination = _destination;
	newNode->next = NULL;

	return newNode;
}

Graph* CreateGraph(int _vertices)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = _vertices;

	/* Komlusuluk listesi dizisi olusturuluyor, dizi boyutu = _vertices */
	graph->array = (AdjList*)malloc(_vertices * sizeof(AdjList));

	/* head = NULL islemiyle butun komsuluk matrisleri baslangıncta empty oluyor (Initialization) */
	for (int i = 0; i < _vertices; ++i)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

/* Yonsuz grafa ayrıt ekleyen fonksiyon */
void AddEdge(Graph* graph, int source, int _destination)
{
	/* Kaynak dugumden hedef dugume ayrıt ekliyoruz. Kaynagin komsuluk
	 * listesine yeni bir dugum eklendi. Dugum baslangica ekleniyor. */
	AdjListNode* newNode = CreateAdjListNode(_destination);
	newNode->next = graph->array[source].head;
	graph->array[source].head = newNode;

	/* Graf yonsuz oldugu icin, hedef dugumden kaynak
	 * dugume de bir ayrit eklemeyi ihmal etmiyoruz */
	newNode = CreateAdjListNode(source);
	newNode->next = graph->array[_destination].head;
	graph->array[_destination].head = newNode;
}

/* Grafi, komsuluk matrisi kullanilarak yazdiran fonksiyon */
void PrintGraph(Graph* graph)
{
	int v;
	for (v = 0; v < graph->vertices; ++v)
	{
		AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->destination);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

int main()
{
	int vertices = 5;
	Graph* graph = CreateGraph(vertices);

	AddEdge(graph, 0, 1);
	AddEdge(graph, 0, 4);
	AddEdge(graph, 1, 2);
	AddEdge(graph, 1, 3);
	AddEdge(graph, 1, 4);
	AddEdge(graph, 2, 3);
	AddEdge(graph, 3, 4);

	PrintGraph(graph);

	getch();
	return 0;
}
