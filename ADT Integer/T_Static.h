#define MAX_SIZE 15
#define IndexRoot 1
#define Nil 0
#include <stdio.h>
#include "Queue\sarray.h"

typedef int Infotype;
typedef struct Tree{
	Infotype Info;
	int Parent;
	int FirstSon;
	int Brother;
}Node;

//bool IsEmpty(int Indexs);
bool IsFull(Tree Array[]);

int Search(Tree Array[],Infotype Data);

/*--------- About Create / Delete A Node/Tree -----------*/
void CreateRoot(Tree Array[],Infotype Data);
void InsertNode(Tree Array[],int IndexParent,Infotype Data);
void DeleteNode(Tree Array[],int Indexs);
void _DeleteNode(Tree Array[],int Indexs);

/*--------- Info About The Tree -----------*/
int Depth(Tree Array[],int Indexs);
int Min(Tree Array[],int Indexs);
int Max(Tree Array[],int Indexs);
void Leaf(Tree Array[],int Indexs);
int Height(Tree Array[],int Indexs);
int Size(Tree Array[],int Indexs);
int MaxDegree(Tree Array[],int Indexs);

/*--------- Info About The Node -----------*/
int Degree(Tree Array[],int Indexs);
int Level(Tree[],int Indexs);
void Ancestor(Tree Array[],int Indexs);
void Descendant(Tree[],int Indexs);
void SubTree(Tree Array[],int Indexs);

/*--------- Get About The Node -----------*/
int GetRoot(Tree Array[],int Indexs);
int GetParent(Tree Array[],int Indexs);
int GetSon(Tree Array[],int Indexs);
int GetBrother(Tree Array[],int Indexs);

/*--------- Traversing -----------*/
void PreOrder (Tree Array[]);
void PostOrder (Tree Array[]);
void InOrder(Tree Array[]);
void LevelOrder(Tree Array[]);
