#define MAX_SIZE 25
#define IndexRoot 1
#define Nil 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef char* Infotype;
typedef struct Tree{
	Infotype Info;
	int Parent;
	int FirstSon;
	int Brother;
};

void CreateRoot(Tree Array[],Infotype Data);
void InsertNode(Tree Array[],Infotype Parent,Infotype Data);
void PreOrder (Tree Array[]);
//void PostOrder (Tree Array[]);
//int Depth(Tree Array[]);
//int Degree(Tree Array[],Infotype Data);
//int DepthRecursive(Tree Array[],int indexs);
//int DegreeRecursive(Tree Array[],int Indexs);
void DeleteNode(Tree Array[],Infotype Indexs);
void _DeleteNode(Tree Array[],int Indexs);
//void InOrder(Tree Array[]);
int Search(Tree Array[],Infotype Data);
//bool IsEmpty(Infotype Indexs);
//int Min(Tree Array[]);
//int Max(Tree Array[]);


