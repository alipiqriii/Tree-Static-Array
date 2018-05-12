#include "T_Static.h"

bool IsEmpty(Infotype Indexs){
	if(Indexs != NULL) return false;
	else return true;	
}
void CreateRoot(Tree Array[],Infotype Data){
	Infotype Name;
	Name = (Infotype) malloc(sizeof(strlen(Data)));
	strcpy(Name,Data);
	
	if(IsEmpty(Array[IndexRoot].Info)){
		Array[IndexRoot].Parent = Nil;
		Array[IndexRoot].FirstSon = Nil;
		Array[IndexRoot].Brother = Nil;
		Array[IndexRoot].Info = Name;
	}
	else printf("(!) ~ Root Sudah Ada\n");
	
}

int Search(Tree Array[],Infotype Data){
	int i=IndexRoot;
	bool Found=false;
	
	//Cari Parent
	if(Array[IndexRoot].Info!=NULL){
		do{
			if(Array[i].Info != NULL)
				if(!strcmp(Array[i].Info,Data)) Found=true;
				else i++;
			else i++;
		}while(!Found && i<(MAX_SIZE+1));
		if (Found) return i;
		else return Nil;
	}
	else return Nil;
	
}

void InsertNode(Tree Array[],Infotype Parent,Infotype Data){
	
	int i=IndexRoot;
	int IndexLastBrother=Nil;
	int IndexParent=Nil;
	bool Found=false;
	Infotype Name;
	
	//Cari Parent
	IndexParent = Search(Array,Parent);
	
	if(Array[IndexRoot].Info==NULL) printf("(!) ~ Root Ga Ada\n");
	else{
	if(IndexParent!=Nil){
		
		//Cari Posisi
		i=IndexRoot;
		while(Array[i].Parent!=Nil || i == IndexRoot){
			if(Array[i].Parent == IndexParent) IndexLastBrother = i;
			i++;
		}
			
		//Cek Jika Parent Tidak Ada First Child
		if(Array[IndexParent].FirstSon==Nil) Array[IndexParent].FirstSon = i;
		
		Array[i].Info = Data;
		Array[IndexLastBrother].Brother = i;
		Array[i].Brother = Nil;
		Array[i].Parent = IndexParent;
		Array[i].FirstSon = Nil;	
			
	}
	
	else printf("(!) ~ Parent Dengan Value %s Tidak Tersedia\n",Parent);
	}
}

void PreOrder (Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	int space=0,j=0;
	if(Array[IndexRoot].FirstSon==Nil) printf("[-] ");
	else printf(" [+] ");
	printf("%s \n",Array[NodeCurrent].Info);
	Resmi = true;
	do{
		if(Array[NodeCurrent].FirstSon!=Nil && Resmi){
			space++;		
			NodeCurrent = Array[NodeCurrent].FirstSon;
			for(j=0;j<=(space*2);j++) {
				if(j%2==0 && j!=0) printf("| ");
				else printf(" ");	
			}
			if(Array[NodeCurrent].FirstSon==Nil) printf("[-] ");
			else printf("[+] ");
			printf("%s \n",Array[NodeCurrent].Info);
		}
		else {
			if(Array[NodeCurrent].Brother!=Nil){
				NodeCurrent = Array[NodeCurrent].Brother;
//				printf("|");
				for(j=0;j<=(space*2);j++) {
				if(j%2==0 && j!=0) printf("| ");
				else printf(" ");	
			}
				if(Array[NodeCurrent].FirstSon==Nil) printf("[-] ");
				else printf("[+] ");
				printf("%s \n",Array[NodeCurrent].Info);
				Resmi = true;
			}
			else {
				space--;
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
}
//
//int DepthRecursive(Tree Array[],int Indexs)
//{
//	int y=0,z=0;
//
//	if(Array[Indexs].FirstSon==Nil )
//		return 0;
//	y=DepthRecursive(Array,Array[Indexs].FirstSon);
//	z=DepthRecursive(Array,Array[Indexs].Brother);
//	if (y > z)
//		return (y+1);
//	else
//		return (z+1);
//}
//
//int DegreeRecursive(Tree Array[],int Indexs)
//{
//	int y=0,z=0;
//	int _Degree=0;
//	if(IsEmpty(Array[Indexs].FirstSon))
//		return 0;
//	y=DepthRecursive(Array,Array[Indexs].FirstSon);
//	z=DepthRecursive(Array,Array[Indexs].Brother);
//	return (y+z+1);
//	
//}
//
void DeleteNode(Tree Array[],Infotype Data){
	
	int Indexs;
	Indexs = Search(Array,Data);
	Tree DeleteNode;
	
	//Save Information Node Delete
	DeleteNode.Parent	= Array[Indexs].Parent;
	DeleteNode.FirstSon	= Array[Indexs].FirstSon;
	DeleteNode.Info		= Array[Indexs].Info;
	DeleteNode.Brother	= Array[Indexs].Brother;
	
	if(Indexs != IndexRoot){
		//Check If This Node Is FirstSon / Not
		if(Array[DeleteNode.Parent].FirstSon == Indexs){
			//If FirstSon But Have Brother
			//Move The FirstSon To Brother
			if(DeleteNode.Brother != Nil){
				Array[DeleteNode.Parent].FirstSon = DeleteNode.Brother;
				if(Array[Indexs].FirstSon != Nil) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				free(Array[Indexs].Info);
				Array[Indexs].Info = NULL;
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Brother = Nil;
			}
			//If FirstSon But NotHave Brother
			else {
				Array[DeleteNode.Parent].FirstSon = Nil;
				if(Array[Indexs].FirstSon != Nil) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				free(Array[Indexs].Info);
				Array[Indexs].Info = NULL;
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Brother = Nil;
			}
		}
		else {
			int i,Before;
			//Try To Search Position Before Node
			i = Array[DeleteNode.Parent].FirstSon;
			while(i != Indexs){
				Before = i;
				i = Array[i].Brother;
			}
			
			//If Not FirstSon (Brother) And Have Other Brother
			if(DeleteNode.Brother != Nil) {
				Array[Before].Brother = DeleteNode.Brother;
				if(Array[Indexs].FirstSon != Nil) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				free(Array[Indexs].Info);
				Array[Indexs].Info = NULL;
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Brother = Nil;
			}
			//If Not FirstSon (Brother) And Not Have Other Brother
			else {
				Array[Before].Brother = Nil;
				if(Array[Indexs].FirstSon != Nil) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				free(Array[Indexs].Info);
				Array[Indexs].Info = NULL;
				Array[Indexs].Parent = Array[Indexs].FirstSon  = Array[Indexs].Brother = Nil;	
			}
		}	
	}
	else _DeleteNode(Array,Indexs);
	
}

void _DeleteNode(Tree Array[],int Indexs){

    if (Array[Indexs].Info == NULL) return;
 
    //Delete SubTree
    _DeleteNode(Array,Array[Indexs].FirstSon);
    _DeleteNode(Array,Array[Indexs].Brother);
 
    //Then Delete The Node
    Array[Indexs].Parent = Nil;
    Array[Indexs].FirstSon = Nil;
    Array[Indexs].Brother = Nil;
    free(Array[Indexs].Info);
    Array[Indexs].Info = NULL;
}
//int Depth(Tree Array[]){
//	int NodeCurrent;
//	bool Resmi;
//	NodeCurrent=IndexRoot;
//	Resmi = true;
//	int y,z;
//	y=0;z=0;
//	do{
//		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
//			y++;		
//			NodeCurrent = Array[NodeCurrent].FirstSon;
//		}
//		else {
//			if(Array[NodeCurrent].Brother != Nil){
//				NodeCurrent = Array[NodeCurrent].Brother;
//				Resmi = true;
//			}
//			else {
//				if(y>z) z=y;
//				y--;
//				
//				NodeCurrent = Array[NodeCurrent].Parent;
//				Resmi = false;
//			}
//		}
//	}while(Array[NodeCurrent].Parent != Nil);
//	
//	return z;
//	
//}
//
//
//
////int Min(Tree Array[]){
////	int NodeCurrent;
////	bool Resmi;
////	NodeCurrent=IndexRoot;
////	Resmi = true;
////	int Min,Temp_Min;
////	Min=0;Min=0;
////	Min=Array[NodeCurrent].Info;
////	do{
////		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
////			NodeCurrent = Array[NodeCurrent].FirstSon;
////			Temp_Min = Array[NodeCurrent].Info;
////			if(Temp_Min < Min) Min = Temp_Min;
////		}
////		else {
////			if(Array[NodeCurrent].Brother != Nil){
////				NodeCurrent = Array[NodeCurrent].Brother;
////				Temp_Min = Array[NodeCurrent].Info;
////				if(Temp_Min < Min) Min = Temp_Min;
////				Resmi = true;
////			}
////			else {
////				NodeCurrent = Array[NodeCurrent].Parent;
////				Resmi = false;
////			}
////		}
////	}while(Array[NodeCurrent].Parent != Nil);
////	
////	return Min;
////	
////}
////
////int Max(Tree Array[]){
////	int NodeCurrent;
////	bool Resmi;
////	NodeCurrent=IndexRoot;
////	Resmi = true;
////	int Max,Temp_Max;
////	Max=0;Temp_Max=0;
////	Max=Array[NodeCurrent].Info;
////	do{
////		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
////			NodeCurrent = Array[NodeCurrent].FirstSon;
////			Temp_Max = Array[NodeCurrent].Info;
////			if(Temp_Max > Max) Max = Temp_Max;
////		}
////		else {
////			if(Array[NodeCurrent].Brother != Nil){
////				NodeCurrent = Array[NodeCurrent].Brother;
////				Temp_Max = Array[NodeCurrent].Info;
////				if(Temp_Max > Max) Max = Temp_Max;
////				Resmi = true;
////			}
////			else {
////				NodeCurrent = Array[NodeCurrent].Parent;
////				Resmi = false;
////			}
////		}
////	}while(Array[NodeCurrent].Parent != Nil);
////	
////	return Max;
////	
////}
//
//int Degree(Tree Array[],Infotype Data){
//	int NodeCurrent,IndexsData;
//	bool Resmi;
//	IndexsData=Search(Array,Data);
//	NodeCurrent=IndexsData;
//	Resmi = true;
//	int _Degre=Nil;
////	y=1;z=0;
//	do{
//		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
//			_Degre++;		
//			NodeCurrent = Array[NodeCurrent].FirstSon;
//		}
//		else {
//			if(Array[NodeCurrent].Brother != Nil){
//				_Degre++;
//				NodeCurrent = Array[NodeCurrent].Brother;
//				Resmi = true;
//			}
//			else {
//				NodeCurrent = Array[NodeCurrent].Parent;
//				Resmi = false;
//			}
//		}
//	}while( NodeCurrent != IndexsData);
//	return _Degre;
//}
//
//void PostOrder (Tree Array[]){
//	
//	int NodeCurrent;
//	bool Resmi;
//	NodeCurrent=IndexRoot;
//	Resmi = true;
//		
//	while(!IsEmpty(NodeCurrent)){
//		if (!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi) NodeCurrent=Array[NodeCurrent].FirstSon;
//		else {
//			printf("%c ",Array[NodeCurrent].Info);
//			if (!IsEmpty(Array[NodeCurrent].Brother)){
//				NodeCurrent = Array[NodeCurrent].Brother;
//				Resmi = true;
//			}
//			else {
//				NodeCurrent = Array[NodeCurrent].Parent;
//				Resmi = false;
//			}
//		}
//	}
//}
//
//void InOrder(Tree Array[]){
//	int NodeCurrent = IndexRoot;
//	bool Resmi = true;
//	while (!IsEmpty(NodeCurrent)){
//		if (!IsEmpty(Array[NodeCurrent].FirstSon) != 0 && Resmi){
//			NodeCurrent = Array[NodeCurrent].FirstSon;
//			
//		}else{
//			if (Resmi){
//				printf ("%c ",Array[NodeCurrent].Info);
//			}
//			if (NodeCurrent == Array[Array[NodeCurrent].Parent].FirstSon){
//				printf ("%c ",Array[Array[NodeCurrent].Parent].Info);
//				
//			}
//			if(!IsEmpty(Array[NodeCurrent].Brother)){
//				NodeCurrent = Array[NodeCurrent].Brother;
//				Resmi = true;
//			}else {
//				NodeCurrent = Array[NodeCurrent].Parent;
//				  Resmi = false;
//			}
//		}
//	}
//	
//}
