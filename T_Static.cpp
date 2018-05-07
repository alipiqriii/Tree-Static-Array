#include "T_Static.h"
bool IsEmpty(int Indexs){
	if(Indexs != Nil) return false;
	else return true;	
}
void CreateRoot(Tree Array[],Infotype Data){
	if(IsEmpty(Array[IndexRoot].Info)){
		Array[IndexRoot].Parent = Nil;
		Array[IndexRoot].FirstSon = Nil;
		Array[IndexRoot].Brother = Nil;
		Array[IndexRoot].Info = Data;
	}
	else printf("(!) ~ Root Sudah Ada\n");
	
}

void InsertNode(Tree Array[],int Parent,Infotype Data){
	int i=IndexRoot;
	int IndexLastBrother=Nil;
	int IndexParent=Nil;
	bool Found=false;
	
	//Cari Parent
	while((Array[i].Parent != Nil || i == IndexRoot) && !Found && i<(MAX_SIZE+1)){
		if(Array[i].Info == Parent) {
			Found=true;
			IndexParent = i;
		}
		i++;
	}
	
	if(IndexParent != Nil){
		
		//Cari Posisi
		i=IndexRoot;
		while(Array[i].Parent != Nil || i == IndexRoot){
			if(Array[i].Parent == IndexParent) IndexLastBrother = i;
			i++;
		}
			
		//Cek Jika Parent Tidak Ada First Child
		if(Array[IndexRoot].FirstSon == Nil) Array[IndexRoot].FirstSon = i;
		if(Array[IndexParent].FirstSon == Nil) Array[IndexParent].FirstSon = i;
		
		Array[i].Info = Data;
		Array[IndexLastBrother].Brother = i;
		Array[i].Brother = Nil;
		Array[i].Parent = IndexParent;
		Array[i].FirstSon = Nil;	
			
	}
	
	else printf("(!) ~ Parent Dengan Value %c Tidak Tersedia\n",Parent);
	
}

void PreOrder (Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	printf("%c ",Array[NodeCurrent].Info);
	Resmi = true;
	int y,z;
	y=0;z=0;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
			printf("%c ",Array[NodeCurrent].Info);
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				NodeCurrent = Array[NodeCurrent].Brother;
				printf("%c ",Array[NodeCurrent].Info);
				Resmi = true;
			}
			else {
				if(y>z) z=y;
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
}

int DepthRecursive(Tree Array[],int Indexs)
{
	int y=0,z=0;

	if(Array[Indexs].FirstSon==Nil )
		return 0;
	y=DepthRecursive(Array,Array[Indexs].FirstSon);
	z=DepthRecursive(Array,Array[Indexs].Brother);
	if (y > z)
		return (y+1);
	else
		return (z+1);
}

void DeleteNode(Tree Array[],int Indexs){
	
	Tree DeleteNode;
	//Save Information Node Delete
	DeleteNode.Parent	= Array[Indexs].Parent;
	DeleteNode.FirstSon	= Array[Indexs].FirstSon;
	DeleteNode.Info		= Array[Indexs].Info;
	DeleteNode.Brother	= Array[Indexs].Brother;
	
	//Recursive Function To Delete Tree
	
	
	//Check If This Node Is FirstSon / Not
	if(Array[DeleteNode.Parent].FirstSon == Indexs){
		//If FirstSon But Have Brother
		//Move The FirstSon To Brother
		if(DeleteNode.Brother != Nil){
			Array[DeleteNode.Parent].FirstSon = DeleteNode.Brother;
			if(Array[Indexs].FirstSon != Nil) {
				_DeleteNode(Array,Array[Indexs].FirstSon);	
			}
			Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;
		}
		//If FirstSon But NotHave Brother
		else {
			Array[DeleteNode.Parent].FirstSon = Nil;
			if(Array[Indexs].FirstSon != Nil) {
				_DeleteNode(Array,Array[Indexs].FirstSon);	
			}
			Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;
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
			Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;
		}
		//If Not FirstSon (Brother) And Not Have Other Brother
		else {
			Array[Before].Brother = Nil;
			if(Array[Indexs].FirstSon != Nil) {
				_DeleteNode(Array,Array[Indexs].FirstSon);	
			}
			Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;	
		}
	}
}

void _DeleteNode(Tree Array[],int Indexs){

    if (Array[Indexs].Info == Nil) return;
 
    //Delete SubTree
    _DeleteNode(Array,Array[Indexs].FirstSon);
    _DeleteNode(Array,Array[Indexs].Brother);
 
    //Then Delete The Node
    printf("Delete %c \n",Array[Indexs].Info);
    Array[Indexs].Parent = Nil;
    Array[Indexs].FirstSon = Nil;
    Array[Indexs].Brother = Nil;
    Array[Indexs].Info = Nil;
}
int Depth(Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int y,z;
	y=0;z=0;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
			y++;		
			NodeCurrent = Array[NodeCurrent].FirstSon;
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				if(y>z) z=y;
				y--;
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	
	return z;
	
}

int Degree(Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int y,z;
	y=1;z=0;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				y++;
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				if(y>z) z=y;
				y=1;
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	return z;
}

void PostOrder (Tree Array[]){
	
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
		
	while(NodeCurrent != 0){
		if (Array[NodeCurrent].FirstSon != 0 && Resmi) NodeCurrent=Array[NodeCurrent].FirstSon;
		else {
			printf("%c ",Array[NodeCurrent].Info);
			if (Array[NodeCurrent].Brother != 0){
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}
}
