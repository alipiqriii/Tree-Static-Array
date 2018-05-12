#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "T_Static.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Infotype Data=0;
	
	Tree Pohon[MAX_SIZE+1];
	for (int i=0;i<MAX_SIZE+1;i++){
		Pohon[i].FirstSon = Pohon[i].Info = Pohon[i].Parent = Pohon[i].Brother = 0;
	}
	CreateRoot(Pohon,'A');
//	InsertNode(Pohon,'A','Z');
	InsertNode(Pohon,Search(Pohon,'A'),'B'); 
	InsertNode(Pohon,Search(Pohon,'A'),'C');
	InsertNode(Pohon,Search(Pohon,'A'),'D');
	InsertNode(Pohon,Search(Pohon,'B'),'E');
	InsertNode(Pohon,Search(Pohon,'B'),'F');
	InsertNode(Pohon,Search(Pohon,'B'),'G');
	InsertNode(Pohon,Search(Pohon,'B'),'H');
	InsertNode(Pohon,Search(Pohon,'F'),'I');
	InsertNode(Pohon,Search(Pohon,'F'),'J');
	InsertNode(Pohon,Search(Pohon,'C'),'K');
	InsertNode(Pohon,Search(Pohon,'D'),'L');
	InsertNode(Pohon,Search(Pohon,'D'),'M');
	InsertNode(Pohon,Search(Pohon,'M'),'N');
	InsertNode(Pohon,Search(Pohon,'M'),'O');
	InsertNode(Pohon,Search(Pohon,'O'),'P');
//	DeleteNode(Pohon,Search(Pohon,'B'));
	printf("\n");
	printf("Index\t\tInfo\tParent\tFC\tBrother\n------------------------------------------------------------------\n");
	for(int i=1;i<MAX_SIZE+1;i++){
		printf("idx: %d\t\t%c\t%d\t%d\t%d\n",i,Pohon[i].Info,Pohon[i].Parent,Pohon[i].FirstSon,Pohon[i].Brother);
	}
	printf("\n[+] --- [ PreOrder ] ---\n");
	PreOrder(Pohon);
	printf("\n");
	printf("\n[+] --- [ PostOrder ] ---\n");
	PostOrder(Pohon);
	printf("\n");
	printf("\n[+] --- [ InOrder ] ---\n");
	InOrder(Pohon);
	
	printf("\n\nDegree \t\t\t: %d\n",Degree(Pohon,'C'));
	printf("Depth Tree \t\t: %d\n",Depth(Pohon));
	printf("Height Tree \t\t: %d\n",Height(Pohon));
	printf("Min \t\t\t: %c\n",Min(Pohon));
	printf("Max \t\t\t: %c\n",Max(Pohon));
	printf("Size Tree \t\t: %d\n",Size(Pohon));
	printf("Leaf Tree \t\t: ");Leaf(Pohon);
	printf("Ancestor (G)\t\t: ");Ancestor(Pohon,Search(Pohon,'G'));
	printf("Descendant (E)\t\t: ");Descendant(Pohon,Search(Pohon,'E'));
	printf("Root from (E)\t\t: %c\n",Pohon[GetRoot(Pohon,Search(Pohon,'E'))].Info);
	printf("Parent from (E)\t\t: %c\n",Pohon[GetParent(Pohon,Search(Pohon,'E'))].Info);
	printf("Brother from (B)\t: %c\n",Pohon[GetBrother(Pohon,Search(Pohon,'B'))].Info);
	printf("FirstSon from (A)\t: %c\n",Pohon[GetSon(Pohon,Search(Pohon,'A'))].Info);
	printf("Subtree from (A)\t: ");SubTree(Pohon,Search(Pohon,'A'));
	MaxDegree(Pohon);
	return 0;
}
