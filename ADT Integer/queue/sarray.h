#ifndef SARRAY_H
#define SARRAY_H

#include <stdio.h>
#include "boolean.h"

#define MAX_ELM 15+1
#define Nil 0

typedef int infotype;
typedef struct tStr_Node{
	infotype info;
	int next;
}Str_Node;

typedef struct tSt_ElmnList{
	int First;
	int Last;
	Str_Node Node[MAX_ELM];
}St_ElmnList;

boolean IsEmpty(int Next);
void Initial_Next(tSt_ElmnList* Linked);

void Insert_Akhir(tSt_ElmnList*  Linked, int value);
void Insert_Awal(tSt_ElmnList* Linked, int value);
void Insert_After(tSt_ElmnList* Linked,int alamat,int value);

void Delete_Akhir(tSt_ElmnList* Linked);
void Delete_Awal(tSt_ElmnList* Linked);
void Delete_After(tSt_ElmnList* Linked,int alamat);
void Delete_Position(tSt_ElmnList* Linked,int alamat);

void Tampil(tSt_ElmnList Linked);
int search(tSt_ElmnList Linked,int value);

int NbElmt (tSt_ElmnList Linked); 
int Min (tSt_ElmnList Linked); 
int Rerata (tSt_ElmnList Linked); 
void BalikList (tSt_ElmnList* Linked); 
void Sort(tSt_ElmnList* Linked);
#endif
