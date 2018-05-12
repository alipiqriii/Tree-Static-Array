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
}Node;

bool IsEmpty(int Indexs);
int Search(Tree Array[],Infotype Data);

/*--------- About Create / Delete A Node/Tree -----------*/
void CreateRoot(Tree Array[],Infotype Data);
void InsertNode(Tree Array[],int IndexParent,Infotype Data);
void DeleteNode(Tree Array[],int Indexs);
void _DeleteNode(Tree Array[],int Indexs);

/*--------- Info About The Tree -----------*/
int Depth(Tree Array[]);
int Min(Tree Array[]);
int Max(Tree Array[]);
void Leaf(Tree Array[]);
int Height(Tree Array[]);
int Size(Tree Array[]);
int MaxDegree(Tree Array[]);

/*--------- Info About The Node -----------*/
int Degree(Tree Array[],Infotype Data);
int Level(Tree[],Infotype Data);
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
