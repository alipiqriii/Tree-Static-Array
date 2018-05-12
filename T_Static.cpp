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

int Search(Tree Array[],Infotype Data){
	int i=IndexRoot;
	bool Found=false;
	//Cari Parent
	while((!IsEmpty(Array[i].Info) || i == IndexRoot) && !Found && i<(MAX_SIZE+1)){
		if(Array[i].Info == Data) {
			Found=true;
		}
		else i++;
	}
	if (Found) return i;
	else return Nil;
}

void InsertNode(Tree Array[],int IndexParent,Infotype Data){
	int i=IndexRoot;
	int IndexLastBrother=Nil;
	bool Found=false;
//	printf("Parent Nil %d\n",IndexParent);
//	if(IndexParent==Nil){
//		printf("Parent Nil %d\n",IndexParent);
//	}
	if(IsEmpty(Array[IndexRoot].Info)) printf("(!) ~ Root Ga Ada\n");
	else{
		if(!IsEmpty(IndexParent)){
			//Cari Posisi
			i=IndexRoot;
			while(!IsEmpty(Array[i].Parent) || i == IndexRoot){
				if(Array[i].Parent == IndexParent) IndexLastBrother = i;
				i++;
			}
				
			//Cek Jika Parent Tidak Ada First Child
			if(IsEmpty(Array[IndexParent].FirstSon)) Array[IndexParent].FirstSon = i;
			
			Array[i].Info = Data;
			Array[IndexLastBrother].Brother = i;
			Array[i].Brother = Nil;
			Array[i].Parent = IndexParent;
			Array[i].FirstSon = Nil;	
				
		}
		else printf("(!) ~ Parent Tidak Tersedia\n");
	}
	
}

void DeleteNode(Tree Array[],int Indexs){
	
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
			if(!IsEmpty(DeleteNode.Brother)){
				Array[DeleteNode.Parent].FirstSon = DeleteNode.Brother;
				if(!IsEmpty(Array[Indexs].FirstSon)) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;
			}
			//If FirstSon But NotHave Brother
			else {
				Array[DeleteNode.Parent].FirstSon = Nil;
				if(!IsEmpty(Array[Indexs].FirstSon)) {
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
			if(!IsEmpty(DeleteNode.Brother)) {
				Array[Before].Brother = DeleteNode.Brother;
				if(!IsEmpty(Array[Indexs].FirstSon)) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;
			}
			//If Not FirstSon (Brother) And Not Have Other Brother
			else {
				Array[Before].Brother = Nil;
				if(!IsEmpty(Array[Indexs].FirstSon)) {
					_DeleteNode(Array,Array[Indexs].FirstSon);	
				}
				Array[Indexs].Parent = Array[Indexs].FirstSon = Array[Indexs].Info = Array[Indexs].Brother = Nil;	
			}
		}	
	}
	else _DeleteNode(Array,Indexs);
	
}

void _DeleteNode(Tree Array[],int Indexs){

    if (IsEmpty(Array[Indexs].Info)) return;
 
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

int Min(Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int Min,Temp_Min;
	Min=0;Min=0;
	Min=Array[NodeCurrent].Info;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
			NodeCurrent = Array[NodeCurrent].FirstSon;
			Temp_Min = Array[NodeCurrent].Info;
			if(Temp_Min < Min) Min = Temp_Min;
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				NodeCurrent = Array[NodeCurrent].Brother;
				Temp_Min = Array[NodeCurrent].Info;
				if(Temp_Min < Min) Min = Temp_Min;
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	
	return Min;
	
}

int Max(Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int Max,Temp_Max;
	Max=0;Temp_Max=0;
	Max=Array[NodeCurrent].Info;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
			NodeCurrent = Array[NodeCurrent].FirstSon;
			Temp_Max = Array[NodeCurrent].Info;
			if(Temp_Max > Max) Max = Temp_Max;
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				NodeCurrent = Array[NodeCurrent].Brother;
				Temp_Max = Array[NodeCurrent].Info;
				if(Temp_Max > Max) Max = Temp_Max;
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	
	return Max;
	
}

int Degree(Tree Array[],Infotype Data){
	int NodeCurrent,IndexsData;
	bool Resmi;
	IndexsData=Search(Array,Data);
	NodeCurrent=IndexsData;
	Resmi = true;
	int _Degre=Nil;
//	y=1;z=0;
	do{
		if(Array[NodeCurrent].FirstSon != Nil && Resmi){
			_Degre++;		
			NodeCurrent = Array[NodeCurrent].FirstSon;
		}
		else {
			if(Array[NodeCurrent].Brother != Nil){
				_Degre++;
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while( NodeCurrent != IndexsData);
	return _Degre;
}

void PostOrder (Tree Array[]){
	
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
		
	while(!IsEmpty(NodeCurrent)){
		if (!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi) NodeCurrent=Array[NodeCurrent].FirstSon;
		else {
			printf("%c ",Array[NodeCurrent].Info);
			if (!IsEmpty(Array[NodeCurrent].Brother)){
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

void InOrder(Tree Array[]){
	
	int NodeCurrent = IndexRoot;
	bool Resmi = true;
	while (!IsEmpty(NodeCurrent)){
		if (!IsEmpty(Array[NodeCurrent].FirstSon) != 0 && Resmi){
			NodeCurrent = Array[NodeCurrent].FirstSon;
			
		}else{
			if (Resmi){
				printf ("%c ",Array[NodeCurrent].Info);
			}
			if (NodeCurrent == Array[Array[NodeCurrent].Parent].FirstSon){
				printf ("%c ",Array[Array[NodeCurrent].Parent].Info);
				
			}
			if(!IsEmpty(Array[NodeCurrent].Brother)){
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}else {
				NodeCurrent = Array[NodeCurrent].Parent;
				  Resmi = false;
			}
		}
	}
	
}

void PreOrder (Tree Array[]){
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	printf("%c ",Array[NodeCurrent].Info);
	Resmi = true;
	do{
		if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
			printf("%c ",Array[NodeCurrent].Info);
		}
		else {
			if(!IsEmpty(Array[NodeCurrent].Brother)){
				NodeCurrent = Array[NodeCurrent].Brother;
				printf("%c ",Array[NodeCurrent].Info);
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
}

int Height(Tree Array[]){
	return (Depth(Array) + 1);
}

void Leaf(Tree Array[]){
	
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int _Leaf=0;
	printf("{ ");
	do{
		if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
		}
		else {
			if(!IsEmpty(Array[NodeCurrent].Brother)){
				if(IsEmpty(Array[NodeCurrent].FirstSon)){
					printf("%c ",Array[NodeCurrent].Info);
					_Leaf++;	
				}
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				if(IsEmpty(Array[NodeCurrent].FirstSon)){
					printf("%c ",Array[NodeCurrent].Info);
					_Leaf++;	
				}
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	printf("} [%d]\n",_Leaf);	

}

int Size(Tree Array[]){
	
	int NodeCurrent;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	int _Size=0;
	if(!IsEmpty(Array[NodeCurrent].Info)){
		_Size++;
		do{
		if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
			_Size++;
		}
		else {
			if(!IsEmpty(Array[NodeCurrent].Brother)){
				_Size++;
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
		}while(Array[NodeCurrent].Parent != Nil);
	}
	else return 0;
	return _Size;
}

void Ancestor(Tree Array[],int Indexs){
	int _Ancestor=0;
	int NodeCurrent = Array[Indexs].Parent;
	if(!IsEmpty(NodeCurrent)){
		printf("{ ");
		do {
			_Ancestor++;
			printf("%c ",Array[NodeCurrent].Info);
			NodeCurrent = Array[NodeCurrent].Parent;
		}while(!IsEmpty(NodeCurrent));	
		printf("} [%d]\n",_Ancestor);
	}
	else printf("(*) Tidak Ada Ancestor Lainnya\n");
	
}

void Descendant (Tree Array[],int Indexs){
	int NodeCurrent;
	bool Resmi;
	int _Descendant=0;
	NodeCurrent=Array[Indexs].FirstSon;
	if(!IsEmpty(NodeCurrent)){
		_Descendant++;
		printf("{ ");
		printf("%c ",Array[NodeCurrent].Info);
		Resmi = true;
		do{
			if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){	
				_Descendant++;	
				NodeCurrent = Array[NodeCurrent].FirstSon;
				printf("%c ",Array[NodeCurrent].Info);
			}
			else {
				if(!IsEmpty(Array[NodeCurrent].Brother)){
					_Descendant++;
					NodeCurrent = Array[NodeCurrent].Brother;
					printf("%c ",Array[NodeCurrent].Info);
					Resmi = true;
				}
				else {
					NodeCurrent = Array[NodeCurrent].Parent;
					Resmi = false;
				}
			}
		}while(NodeCurrent != Indexs);
		printf("} [%d]\n",_Descendant);
	}
	
	else printf("(*) Tidak Ada Descendant Lainnya\n");	
}

int GetRoot(Tree Array[],int Indexs){
	int _Root;
	_Root = Indexs;
	if(!IsEmpty(_Root)){
		if(!IsEmpty(Array[_Root].Parent)){
			do{
				_Root = Array[_Root].Parent;
			}while(!IsEmpty(Array[_Root].Parent));	
		}
		return _Root;
	}
	else {
		printf("(!) Tidak Ada Elemen Tersebut Dalam Tree\n");
		return Nil;
	}
}

int GetParent(Tree Array[],int Indexs){
	if(!IsEmpty(Indexs)) return Array[Indexs].Parent;
	else {
		printf("(!) Tidak Ada Elemen Tersebut Dalam Tree\n");
		return Nil;
	}
}

int GetSon(Tree Array[],int Indexs){
	if(!IsEmpty(Indexs)) return Array[Indexs].FirstSon;
	else {
		printf("(!) Tidak Ada Elemen Tersebut Dalam Tree\n");
		return Nil;
	}
}

int GetBrother(Tree Array[],int Indexs){
	if(!IsEmpty(Indexs)) return Array[Indexs].Brother;
	else {
		printf("(!) Tidak Ada Elemen Tersebut Dalam Tree\n");
		return Nil;
	}
}

int RecSize(Tree Array[],int Indexs){
	int _Rec=0;	
    if (IsEmpty(Array[Indexs].Info)) return 0;
    _Rec+=RecSize(Array,Array[Indexs].FirstSon);
    _Rec+=RecSize(Array,Array[Indexs].Brother);
    return (_Rec + 1);
}

void SubTree(Tree Array[],int Indexs){
	int NodeCurrent,NodeChild;
	bool Resmi;
	NodeChild=Array[Indexs].FirstSon;
	int NumberOfSubTree = 0;
	while(!IsEmpty(NodeChild)){
		if(!IsEmpty(Array[NodeChild].FirstSon)){
			NumberOfSubTree++;
			NodeCurrent = NodeChild;
			printf("{ ");
			printf("%c ",Array[NodeCurrent].Info);
			Resmi = true;
			do{
				if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){	
					NodeCurrent = Array[NodeCurrent].FirstSon;
					printf("%c ",Array[NodeCurrent].Info);
				}
				else {
					if(!IsEmpty(Array[NodeCurrent].Brother)){
						NodeCurrent = Array[NodeCurrent].Brother;
						printf("%c ",Array[NodeCurrent].Info);
						Resmi = true;
					}
					else {
						NodeCurrent = Array[NodeCurrent].Parent;
						Resmi = false;
					}
				}
			}while(NodeCurrent != NodeChild);
			printf("}, ");
		}
		NodeChild = Array[NodeChild].Brother;
	}
	printf("[%d] Subtree\n",NumberOfSubTree);
}

int MaxDegree(Tree Array[]){
	int NodeCurrent;
	int MaxDegree;
	int TempMaxDegree;
	bool Resmi;
	NodeCurrent=IndexRoot;
	Resmi = true;
	TempMaxDegree = 0;
	MaxDegree = 0;
	do{
		if(!IsEmpty(Array[NodeCurrent].FirstSon) && Resmi){		
			NodeCurrent = Array[NodeCurrent].FirstSon;
			TempMaxDegree=1;
		}
		else {
			if(!IsEmpty(Array[NodeCurrent].Brother)){
				TempMaxDegree+=1;
				NodeCurrent = Array[NodeCurrent].Brother;
				Resmi = true;
			}
			else {
				if(TempMaxDegree>=MaxDegree) MaxDegree = TempMaxDegree;
				NodeCurrent = Array[NodeCurrent].Parent;
				Resmi = false;
			}
		}
	}while(Array[NodeCurrent].Parent != Nil);
	printf("Max Degree %d \n",MaxDegree);	
}
