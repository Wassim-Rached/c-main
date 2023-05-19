#include<stdio.h>
#include<stdlib.h>

typedef struct Cellule
{
	int info; 
	struct Cellule *suivant;
}Cellule;

typedef struct Cellule *Liste;

void Créer(Liste *L);
void AjoutTete(Liste *L, int e);
void SuppPos(Liste *L, int k);
void Trier(Liste *L);
void Affiche(Liste L);

int main(){
	Liste L;
	Créer(&L);
	
	int i,N,value;

	printf("saisir N :");
	scanf("%d",&N);

	for (i = 0; i < N; i++)
	{
		printf("===> ");
		scanf("%d",&value);
		AjoutTete(&L,value);
	}
	
	puts("non sorted :");
	Affiche(L);

	Trier(&L);

	puts("sorted :");
	Affiche(L);

	return 0;
}

void Créer(Liste *L){
	*L = NULL;
}

void AjoutTete(Liste *L, int e){
	Liste new_liste = (Liste) malloc(sizeof(Cellule));

	new_liste->info = e;
	new_liste->suivant = *L;

	*L = new_liste;
}

void SuppPos(Liste *L, int k){
    if (k <= 0 || *L == NULL)
        return;

    if (k == 1)
    {
        Liste deleted_node = *L;
        *L = (*L)->suivant;
        free(deleted_node);
    }
    else
    {
        SuppPos(&((*L)->suivant), k - 1);
    }
}

void Trier(Liste *L){
	if (*L == NULL) return;

	Liste sorted_liste;
	Créer(&sorted_liste);

	int max = (*L)->info;
	int postion_max;
	int postion;

	Liste P = (*L);
	while (*L != NULL)
	{	
		// reset values
		max = (*L)->info;
		postion = 1;
		postion_max =1; 

		while (P != NULL)
		{
			if(P->info > max){
				max = P->info;
				postion_max=postion;
			}
			postion++;
			P = P->suivant;
		}

		printf("max :%d \n",max);
		printf("po max :%d \n",postion_max);
		puts("");

		SuppPos(L,postion_max);
		AjoutTete(&sorted_liste,max);
		// reset max
		P = *L;
	}

	*L = sorted_liste;
}



void Affiche(Liste L){
	while (L != NULL)
	{
		printf("%d\n",L->info);
		L = L->suivant;
	}
}
