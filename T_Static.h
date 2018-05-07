#define MAX_SIZE 15
#define IndexRoot 1
#define Nil 0
#include <stdio.h>
typedef int Infotype;
typedef struct Tree{
	Infotype Info;
	int Parent;
	int FirstSon;
	int Brother;
};

void CreateRoot(Tree Array[],Infotype Data);
void InsertNode(Tree Array[],int Parent,Infotype Data);
void PreOrder (Tree Array[]);
void PostOrder (Tree Array[]);
int Depth(Tree Array[]);
int Degree(Tree Array[]);
int DepthRecursive(Tree Array[],int indexs);
void DeleteNode(Tree Array[],int Indexs);
void _DeleteNode(Tree Array[],int Indexs);
