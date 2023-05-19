#include<stdio.h>
#include<stdlib.h>

typedef struct Cellule
{
	int info; 
	struct Cellule *suivant;
}Cellule;

typedef struct Cellule *Liste;


// fucntions
Liste CreerTrie();
void AjoutTrie(Liste *L, int e);
void Affiche(Liste L);
void Affiche_r(Liste L);

int main(){
	Liste L = CreerTrie();
	int i,N,value;

	printf("enter n:\n");
	scanf("%d",&N);

	for(i=0; i < N; i++)
	{
		printf("==> ");
		scanf("%d",&value);
		AjoutTrie(&L,value);
	}
	
	Affiche(L);
	Affiche_r(L);
	return 0;
}

Liste CreerTrie(){
	return (Liste) NULL;
}

void AjoutTrie(Liste *L, int e){
	Liste new_liste = (Liste) malloc(sizeof(Cellule));
	new_liste->info = e;
	new_liste->suivant = NULL;


	if (*L == NULL)
	{
		*L = new_liste;
	}else{
		Liste P = *L;
		while (P->suivant != NULL)
		{
			P = P->suivant;
		}
		// if the value is not ascending, then we back off
		if (P->info > new_liste->info) return;

		// otherwise we add the new list at the end  
		P->suivant = new_liste;

	}
}	

void Affiche(Liste L){
	printf("\n[");
	while (L!=NULL)
	{
		printf("%d ",L->info);
		if (L->suivant != NULL)
		{
			printf(",");
		}
		L = L->suivant;
	}
	printf("]\n");
}

void Affiche_r(Liste L){
	if (L == NULL) return;

	printf("%d ",L->info);

	Affiche_r(L->suivant);

}