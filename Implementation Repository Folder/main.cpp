#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "T_Static.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Infotype Data=0;
	
	Tree Pohon[MAX_SIZE+1];
	for (int i=0;i<MAX_SIZE+1;i++){
		Pohon[i].FirstSon = Pohon[i].Parent = Pohon[i].Brother = 0;
		Pohon[i].Info = NULL;
	}
	CreateRoot(Pohon,"MyStuff");
	InsertNode(Pohon,"MyStuff","Home");
	InsertNode(Pohon,"Home","NewFolder1");
	InsertNode(Pohon,"NewFolder1","File1.ai");
	InsertNode(Pohon,"NewFolder1","File2.ai");
	InsertNode(Pohon,"NewFolder1","File3.ai");
	InsertNode(Pohon,"Home","Budget.txt");
	InsertNode(Pohon,"MyStuff","Work");
	InsertNode(Pohon,"MyStuff","Play");
	InsertNode(Pohon,"Play","CS-GO");
	InsertNode(Pohon,"Play","Dota");
	InsertNode(Pohon,"Play","GamesHouse");
	InsertNode(Pohon,"CS-GO","CS1.txt");
	InsertNode(Pohon,"CS-GO","CS2.txt");
	InsertNode(Pohon,"Dota","Dota1.txt");
	InsertNode(Pohon,"GamesHouse","GamesHouse.txt");
	InsertNode(Pohon,"MyStuff","School");
	InsertNode(Pohon,"School","SDA1.pdf");
	InsertNode(Pohon,"School","SDA2.pdf");
	InsertNode(Pohon,"Work","Work1.txt");
	
	PreOrder(Pohon);
//	int Choose;
//	do{
//		system("cls");
//		printf("===================================================\n");
//		printf("\t\t~ Welcome To My Computer ~\n");
//		printf("===================================================\n\n");
//		
//		printf(" [1] Tambah Folder/File\n");
//		printf(" [2] Delete Folder/File\n");
//		printf(" [3] Cari Folder/File\n");
//		printf(" [4] Tampil Hirarki Folder\n");
//		printf(" [0] Exit\n");
//		printf("\n");
//		printf(" > ");scanf("%d",&Choose);
//		switch(Choose){
//			case 1 :{
//				break;
//			}
//			case 2 :{
//				break;
//			}
//			case 3 :{
//				break;
//			}
//			case 4 :{
//				break;
//			}
//			case 5 :{
//				break;
//			}
//			default :{
//				break;
//			}
//		}
//	}while(Choose!=0);
	return 0;
}
