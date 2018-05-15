#include "sarray.h"
#include "boolean.h"
#include "conio.h"

boolean IsEmpty(int Next){
	if(Next == Nil) return true;
	else return false;
}

boolean IsFull(tSt_ElmnList Linked){
	int Sum = NbElmt(Linked);
	if(Sum == MAX_ELM-1) return true;
	else return false;
	
}

void Initial_Next(tSt_ElmnList* Linked){
	int i;
	for(i=Linked->First;i<MAX_ELM;i++){
		Linked->Node[i].next = Linked->Node[i].info = Nil;
	}
}

void Insert_Awal(tSt_ElmnList* Linked, int value){
	int pos=1;
	boolean found=false;
	if(IsEmpty(Linked->First)){
		Linked->First = Linked->Last = 1;
		Linked->Node[Linked->First].next = Nil;        
   		Linked->Node[Linked->First].info = value;
	}
	else {
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked->Node[pos].next)) pos++;
				if (Linked->Last == pos) pos++;
				else found=true;
			}
			Linked->Node[pos].info = value;
			Linked->Node[pos].next = Linked->First;
			Linked->First = pos;
		
	}
}

void Insert_Akhir(tSt_ElmnList* Linked, int value){
	int pos=1;
	boolean found=false;
	if(IsEmpty(Linked->Last)){
		Linked->First = Linked->Last = 1;
		Linked->Node[Linked->Last].next = Nil;        
   		Linked->Node[Linked->Last].info = value;
	}
	else {
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked->Node[pos].next)) pos++;
				if (Linked->Last == pos) pos++;
				else found=true;
			}
			Linked->Node[Linked->Last].next = pos;
			Linked->Node[pos].info = value;
			Linked->Node[pos].next = Nil;
			Linked->Last = pos;
		
	}
}

void Insert_After(tSt_ElmnList* Linked,int alamat,int value){
	int pos=1;
	boolean found=false;
	if(!IsEmpty(alamat)){
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked->Node[pos].next)) pos++;
				if (Linked->Last == pos) pos++;
				else found=true;
			}
			
			Linked->Node[pos].info = value;
			Linked->Node[pos].next = Linked->Node[alamat].next;
			Linked->Node[alamat].next = pos;
			
			if(alamat==Linked->Last) Linked->Last = pos;
		
	}
}

void BalikList(tSt_ElmnList* Linked){
		int i,prev,next1,temp;
		i = Linked->First;
		prev = Nil;
		while(Linked->Node[i].next!=Nil){
			next1 = Linked->Node[i].next;
			Linked->Node[i].next = prev;
			prev = i;
			i = next1; 
		}
			
		Linked->Node[i].next = prev;
		temp = Linked->First;
		Linked->First = Linked->Last;
		Linked->Last = temp;
}

void Delete_Awal(tSt_ElmnList* Linked){
	int i=Linked->First;
	
	if(!IsEmpty(Linked->First)){
		Linked->First = Linked->Node[i].next;
		Linked->Node[i].next = Nil;
	}
}

void Delete_Akhir(tSt_ElmnList* Linked){
	int i=Linked->First;
	int before;
	if(!IsEmpty(Linked->First)){
		if(Linked->Last!=Linked->First){
			while(!IsEmpty(Linked->Node[i].next)){
				before=i;
				i=Linked->Node[i].next;
			}
			Linked->Node[before].next = Nil;
			Linked->Last = before;
		}
		else Linked->Last = Linked->First = Linked->Node[Linked->Last].next = Nil;
	}
}

void Delete_After(tSt_ElmnList* Linked,int alamat){
	int i=Linked->Node[alamat].next;
	if(!IsEmpty(alamat) && alamat!=Linked->Last){
		Linked->Node[alamat].next = Linked->Node[i].next;
		Linked->Node[i].next = Nil;
		if(Linked->Node[alamat].next == Nil) Linked->Last = alamat;
	}
}

void Delete_Position(tSt_ElmnList* Linked,int alamat){
	int temp;
	
	if(!IsEmpty(alamat)){
		if(alamat == Linked->First) Delete_Awal(Linked);
		else if(alamat == Linked->Last) Delete_Akhir(Linked);
		else {
			int j,i=Linked->First;
			boolean found=false;
			while((!IsEmpty(i) || i == Linked->Last) && !found){
				if (i == alamat) found=true;
				else {
					j=i;
					i=Linked->Node[i].next;
				}
			}
			temp = Linked->Node[j].next;
			Linked->Node[j].next = Linked->Node[Linked->Node[j].next].next;
			Linked->Node[i].next = Nil;
		}
	}
}

int search(tSt_ElmnList Linked,int value){
	int i=Linked.First;
	
	boolean found=false;
	
	if(!IsEmpty(Linked.First)){
		while((!IsEmpty(Linked.Node[i].next) || i == Linked.Last) && !found){
			if (Linked.Node[i].info == value) found=true;
			else i=Linked.Node[i].next;
		}
		if(found) return i;
		else return 0;
	}
}

void Tampil(tSt_ElmnList Linked){
	int i=Linked.First;
	
	while(!IsEmpty(Linked.Node[i].next)){
		printf("%d ",Linked.Node[i].info);
		i=Linked.Node[i].next;
	}
	printf("%d ",Linked.Node[i].info);
	printf("\n");
}

int Min(tSt_ElmnList Linked){
	int min,i;
	if(!IsEmpty(Linked.First)){	
			i = Linked.First;
			min = Linked.Node[i].info;
			while(Linked.Node[i].next != Nil){
				i = Linked.Node[i].next;
				if(Linked.Node[i].info < min){
					min = Linked.Node[i].info;
				}
			}
			if(Linked.Node[i].info < min) min = Linked.Node[i].info;
			return min;
		}
	else return 0;
}

int Rerata(tSt_ElmnList Linked){
		if (!IsEmpty(Linked.First)){
			int Tot, Sum, Avg; 
			int i = Linked.First;
			Tot = Linked.Node[i].info;
			while(Linked.Node[i].next!=Nil){
				i = Linked.Node[i].next;
				Tot = Tot + Linked.Node[i].info;
			}
			Sum=NbElmt(Linked);
			Avg = Tot/Sum;
			return Avg;	
		}
		else return 0;
}

int NbElmt (tSt_ElmnList Linked){
		if (!IsEmpty(Linked.First)){
			int Sum = 1;
			int i = Linked.First;
			while(Linked.Node[i].next!=Nil){
				i = Linked.Node[i].next;
				Sum++;
			}
			return Sum;	
		}
}

void Sort(tSt_ElmnList* Linked){
	int i;
	infotype data_min,min;
	tSt_ElmnList temp;
	temp = *Linked;

	data_min = Min(temp);
	min = search(temp,data_min);
	Linked->First = i = min;
	
	while(!IsEmpty(temp.First)){
		
		data_min = Min(temp);
		min = search(temp,data_min);
		Linked->Node[i].next=min;
		i=min;
		Delete_Position(&temp,min);
	}
	
	if(IsEmpty(temp.First)) Linked->Node[i].next = 0;
	Linked->Last = i;
}
