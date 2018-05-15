#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "T_Static.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Infotype Data=0;
	int Action,Choose,IndexParent;
	
	Tree Pohon[MAX_SIZE+1];
	for (int i=0;i<MAX_SIZE+1;i++){
		Pohon[i].FirstSon = Pohon[i].Info = Pohon[i].Parent = Pohon[i].Brother = 0;
	}
	//Create Dummy Data
	CreateRoot(Pohon,'A');
	InsertNode(Pohon,Search(Pohon,'A'),'B'); 
	InsertNode(Pohon,Search(Pohon,'A'),'C');
	InsertNode(Pohon,Search(Pohon,'A'),'D');
	InsertNode(Pohon,Search(Pohon,'B'),'E');
	InsertNode(Pohon,Search(Pohon,'B'),'F');
	InsertNode(Pohon,Search(Pohon,'B'),'G');
	InsertNode(Pohon,Search(Pohon,'E'),'H');
	InsertNode(Pohon,Search(Pohon,'F'),'I');
	InsertNode(Pohon,Search(Pohon,'F'),'J');
	InsertNode(Pohon,Search(Pohon,'C'),'K');
	InsertNode(Pohon,Search(Pohon,'C'),'L');
	InsertNode(Pohon,Search(Pohon,'D'),'M');
	InsertNode(Pohon,Search(Pohon,'M'),'N');
	InsertNode(Pohon,Search(Pohon,'M'),'O');
	do{
	system("cls");
	printf("(*) Info Node Berupa Char Yang Akan DIkonversi Ke ASCII\n\n");
	printf("1. CreateRoot \n");
	printf("2. InsertNode \n");
	printf("3. DeleteNode \n");
	printf("4. PreOrder \n");
	printf("5. PostOrder \n");
	printf("6. InOrder \n");
	printf("7. LevelOrder \n");
	printf("8. Tabel Pohon \n");
	printf("9. Degree \n");
	printf("10. MaxDegree \n");
	printf("11. Level \n");
	printf("12. Depth \n");
	printf("13. Height \n");
	printf("14. Min\n");
	printf("15. Max\n");
	printf("16. Size\n");
	printf("17. Leaf\n");
	printf("18. Ancestor\n");
	printf("19. Descendant\n");
	printf("20. GetRoot\n");
	printf("21. GetParent/Predecessor \n");
	printf("22. GetSon/Successor \n");
	printf("23. GetBrother\n");
	printf("24. Subtree\n");
	printf("25. Tampilkan Semuanya\n");
	printf("0. Exit\n\n");
	printf("[+] Input : ");scanf("%d",&Action);
	
	switch(Action){
		case 1 : {
			system("cls");
			printf("[] CreateRoot\n");
			if(IsEmpty(Pohon[IndexRoot].Info)) {
				fflush(stdin);
				printf("Info Root : ");scanf("%c",&Data);
				CreateRoot(Pohon,Data);	
			}
			else printf("Root Sudah ada\n");
			break;
		}
		case 2 : {
			system("cls");
			printf("[] InsertNode\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				if(!IsFull(Pohon)){
					fflush(stdin);
					printf("Info Parent : ");scanf("%c",&Data);
					if(!IsEmpty(Search(Pohon,Data))) {
						IndexParent = Search(Pohon,Data);
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						InsertNode(Pohon,IndexParent,Data);
						printf("Success");	
					}
					else printf("Parent Tidak Tersedia\n");		
				}
				else printf("Tree Penuh\n");
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 3 : {
			system("cls");
			printf("[] DeleteNode\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					DeleteNode(Pohon,Search(Pohon,Data));
					printf("Success\n");	
				}
				else printf("Data Tidak Ditemukan\n");	
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 4 : {
			system("cls");
			printf("[] PreOrder\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				PreOrder(Pohon);	
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 5 : {
			system("cls");
			printf("[] PostOrder\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				PostOrder(Pohon);	
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 6 : {
			system("cls");
			printf("[] InOrder\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				InOrder(Pohon);	
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 7 : {
			system("cls");
			printf("[] LevelOrder\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				LevelOrder(Pohon);	
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 8 : {
			system("cls");
			printf("[] TabelPohon\n");
			printf("Index\t\tInfo\tParent\tFC\tBrother\n------------------------------------------------------------------\n");
			for(int i=1;i<MAX_SIZE+1;i++){
				printf("idx: %d\t\t%c\t%d\t%d\t%d\n",i,Pohon[i].Info,Pohon[i].Parent,Pohon[i].FirstSon,Pohon[i].Brother);
			}
			break;
		}
		case 9 : {
			system("cls");
			printf("[] Degree\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Degree Dari Root\n");
				printf("2. Degree Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Deegre From Root : %d\n",Degree(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Degree From Node %c : %d\n",Data,Degree(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 10 : {
			system("cls");
			printf("[] MaxDegree\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. MaxDegree Dari Root\n");
				printf("2. MaxDegree Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("MaxDeegre From Root : %d\n",MaxDegree(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("MaxDegree From Node %c : %d\n",Data,MaxDegree(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		case 11 : {
			system("cls");
			printf("[] Level\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) printf("Level From Node %c : %d\n",Data,Level(Pohon,Search(Pohon,Data)));	
				else printf("Data Tidak Ada\n");
					
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 12 : {
			system("cls");
			printf("[] Depth\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Depth Dari Root\n");
				printf("2. Depth Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Depth From Root : %d\n",Depth(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Depth From Node %c : %d\n",Data,Depth(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 13 : {
			system("cls");
			printf("[] Height\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Height Dari Root\n");
				printf("2. Height Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Height From Root : %d\n",Height(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Height From Node %c : %d\n",Data,Height(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 14 : {
			system("cls");
			printf("[] Min\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Min Dari Root\n");
				printf("2. Min Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Min From Root : %d\n",Min(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Min From Node %c : %c\n",Data,Min(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 15 : {
			system("cls");
			printf("[] Max\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Max Dari Root\n");
				printf("2. Max Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Max From Root : %d\n",Max(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Max From Node %c : %c\n",Data,Max(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 16 : {
			system("cls");
			printf("[] Size\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Size Dari Root\n");
				printf("2. Size Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : printf("Size From Root : %d\n",Size(Pohon,IndexRoot));break;
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) printf("Size From Node %c : %d\n",Data,Size(Pohon,Search(Pohon,Data)));	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 17 : {
			system("cls");
			printf("[] Leaf\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Leaf Dari Root\n");
				printf("2. Leaf Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : {
						printf("Leaf From Root : ");
						Leaf(Pohon,IndexRoot);
						break;
					}
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) {
							printf("Leaf From Node %c : ",Data);Leaf(Pohon,Search(Pohon,Data));	
						}	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 18 : {
			system("cls");
			printf("[] Ancestor\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
					
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					printf("Ancestor From Node %c : ",Data);Ancestor(Pohon,Search(Pohon,Data));	
				}	
				else printf("Data Tidak Ada\n");
				break;
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 19 : {
			system("cls");
			printf("[] Descendant\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Descendant Dari Root\n");
				printf("2. Descendant Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : {
						printf("Descendant From Root : ");
						Descendant(Pohon,IndexRoot);
						break;
					}
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) {
							printf("Descendant From Node %c : ",Data);Descendant(Pohon,Search(Pohon,Data));	
						}	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 20 : {
			system("cls");
			printf("[] GetRoot\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
					
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					printf("Root From Node %c : %c",Data,GetRoot(Pohon,Search(Pohon,Data)));	
				}	
				else printf("Data Tidak Ada\n");
				break;
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 21 : {
			system("cls");
			printf("[] GetParent/Predecessor\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
					
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					printf("Parent From Node %c : %c",Data,GetParent(Pohon,Search(Pohon,Data)));	
				}	
				else printf("Data Tidak Ada\n");
				break;
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 22 : {
			system("cls");
			printf("[] GetSon/Successor\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
					
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					printf("Son From Node %c : %c",Data,GetSon(Pohon,Search(Pohon,Data)));	
				}	
				else printf("Data Tidak Ada\n");
				break;
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 23 : {
			system("cls");
			printf("[] GetBrother\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
					
				fflush(stdin);
				printf("Info Node : ");scanf("%c",&Data);
				if(!IsEmpty(Search(Pohon,Data))) {
					printf("Brother From Node %c : %c",Data,GetBrother(Pohon,Search(Pohon,Data)));	
				}	
				else printf("Data Tidak Ada\n");
				break;
				
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 24 : {
			system("cls");
			printf("[] Subtree\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
				printf("1. Subtree Dari Root\n");
				printf("2. Subtree Dari Node Tertentu\n");
				printf("[+] Input : ");scanf("%d",&Choose);
				switch(Choose){
					case 1 : {
						printf("Subtree From Root : ");
						SubTree(Pohon,IndexRoot);
						break;
					}
					case 2 : {
						fflush(stdin);
						printf("Info Node : ");scanf("%c",&Data);
						if(!IsEmpty(Search(Pohon,Data))) {
							printf("SubTree From Node %c : ",Data);SubTree(Pohon,Search(Pohon,Data));	
						}	
						else printf("Data Tidak Ada\n");
						break;
					}
					default : printf("Input Tidak Valid\n");
				}
			}
			else printf("Root Tidak ada\n");
			break;
		}
		
		case 25:{
			system("cls");
			printf("[] All\n");
			if(!IsEmpty(Pohon[IndexRoot].Info)) {
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
				
				printf("\n\nDegree (C) \t\t: %d\n",Degree(Pohon,Search(Pohon,'C')));
				printf("Level (C) \t\t: %d\n",Level(Pohon,Search(Pohon,'O')));
				printf("Depth Tree \t\t: %d\n",Depth(Pohon,IndexRoot));
				printf("Height Tree \t\t: %d\n",Height(Pohon,IndexRoot));
				printf("Min \t\t\t: %c\n",Min(Pohon,IndexRoot));
				printf("Max \t\t\t: %c\n",Max(Pohon,IndexRoot));
				printf("Size Tree \t\t: %d\n",Size(Pohon,IndexRoot));
				printf("Leaf Tree \t\t: ");Leaf(Pohon,IndexRoot);
				printf("Ancestor (G)\t\t: ");Ancestor(Pohon,Search(Pohon,'G'));
				printf("Descendant (E)\t\t: ");Descendant(Pohon,Search(Pohon,'E'));
				printf("Root from (E)\t\t: %c\n",Pohon[GetRoot(Pohon,Search(Pohon,'E'))].Info);
				printf("Parent from (E)\t\t: %c\n",Pohon[GetParent(Pohon,Search(Pohon,'E'))].Info);
				printf("Brother from (B)\t: %c\n",Pohon[GetBrother(Pohon,Search(Pohon,'B'))].Info);
				printf("FirstSon from (A)\t: %c\n",Pohon[GetSon(Pohon,Search(Pohon,'A'))].Info);
				printf("Subtree from (A)\t: ");SubTree(Pohon,Search(Pohon,'A'));
				printf("Degree Tree\t\t: %d\n\n",MaxDegree(Pohon,IndexRoot));
			}
			else printf("Root Tidak ada\n");	
			break;
		}
		case 0 : break;
		default : printf("Input Tidak Valid\n");break;
		
	}
	system("pause");
	}while(Action!=0);
	return 0;
}
