#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct Cellule{
	int info;
	struct Cellule* suivant;
};

typedef struct Cellule Liste;

void Créer(Liste **L) ;
void AjoutTete(Liste **L, int e) ;
void SuppPos(Liste **L, int k);
void Trier(Liste **L) ;
void Affiche(Liste *L) ;
int IsSorted(Liste *L);
void get_min_and_skip_first_n(Liste *L,int n,int* min_index,int* min_value);

int main(){
	Liste *L = NULL;
	Créer(&L);
	L->info = 6;
	AjoutTete(&L,51);
	AjoutTete(&L,1);
	AjoutTete(&L,16);
	AjoutTete(&L,-14);
	AjoutTete(&L,51);
	AjoutTete(&L,6);
	AjoutTete(&L,-34);
	AjoutTete(&L,21);
	AjoutTete(&L,32);
	AjoutTete(&L,14);
	Affiche(L);
	printf("is storted :%d \n",IsSorted(L));
	Trier(L);
	Affiche(L);

	printf("is storted :%d \n",IsSorted(L));
	return 0;
}

void Créer(Liste **L){
	*L = (Liste *)malloc(sizeof(Liste));
	(*L)->info = 0;
	(*L)->suivant = NULL;
}

void AjoutTete(Liste **L, int e){
	printf("add %d\n", e);
	Liste *P;
	Créer(&P);
	P->info = e;
	P->suivant = (*L);
	(*L) = P;
}

// //récursive
void SuppPos(Liste **L, int k) {
    if (*L == NULL || k < 1) {
        return; // list is empty or k is invalid
    }
    if (k == 1) {
        Liste *P = *L;
        *L = (*L)->suivant;
        free(P); // remove the first node
    } else {
        Liste *P = *L;
        for (int i = 1; i < k - 1 && P != NULL; i++) {
            P = P->suivant; // move to the (k-1)th node
        }
        if (P == NULL || P->suivant == NULL) {
            return; // k is larger than the number of nodes
        }
        Liste *Q = P->suivant;
        P->suivant = Q->suivant;
        free(Q); // remove the kth node
    }
}

void Trier(Liste **L) {
	int counter = 0;
	int max_index;
	int max_value;
	int sorted_numbers_counter = 0;
	int index = 0;
	int idk = 0;
	while (!IsSorted(*L)) 
	{
		printf("not sorted %d\n", idk);
		idk = idk + 1;
		Liste *P = *(L);
		max_value = INT_MIN;
		max_index = -1;
		index = 0;
		while (P != NULL)
		{
			
			index = index + 1;
			if (index > sorted_numbers_counter)
			{
				if (P->info > max_value )
				{
					max_value = P->info;
					max_index = index;
				}
			}
			P = P->suivant;
		}
		SuppPos(&L,max_index);
		AjoutTete(&L,max_value);
		sorted_numbers_counter = sorted_numbers_counter + 1;

	}
	
}

// void get_min_and_skip_first_n(Liste *L,int n,int* min_index,int* min_value) {
	// *min_value = INT_MAX;
	// *min_index = -1;
	// int index = 0;

	// while (L != NULL)
	// {	
	// 	index = index +1;
		
	// 	if (index > n){
		
	// 		if (L->info < *min_value){
	// 				*min_value  = L->info;
	// 				*min_index = index;
	// 		}
	// 	}
	// 	L = L->suivant;
	// }
// }

int IsSorted(Liste **L){
	Liste *P;
	P = *L;
	while (P->suivant != NULL)
	{
		if (P->info > P->suivant->info)
		{
			return 0;
		}
		P = P->suivant;
	}
	return 1;
}

// // typedef struct Cellule{
// // 	int info;
// // 	struct Cellule* suivant;
// // }Cellule;


void Affiche(Liste *L){
	printf("=================[ affichage starts ]================\n[");
	while (L != NULL) 
	{
		printf("%d ,", L->info);
		L = L->suivant;
	}
	printf("]\n=================[ affichage ends ]==================\n");
}