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
	InsertNode(Pohon,'A','B'); 
	InsertNode(Pohon,'A','C');
	InsertNode(Pohon,'A','D');
	InsertNode(Pohon,'B','E');
	InsertNode(Pohon,'C','K');
	InsertNode(Pohon,'D','M');
	InsertNode(Pohon,'M','N');
	InsertNode(Pohon,'M','O');
	InsertNode(Pohon,'C','L');
	InsertNode(Pohon,'B','F');
	InsertNode(Pohon,'B','G');
	InsertNode(Pohon,'E','H');
	InsertNode(Pohon,'F','I');
	InsertNode(Pohon,'F','J');
//	DeleteNode(Pohon,'A');
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
//	DegreeRecursive(Pohon,1);
	printf("\n\nDegree \t: %d\n",Degree(Pohon,'C'));
	printf("Depth \t: %d\n",DepthRecursive(Pohon,IndexRoot));
	
	return 0;
}
