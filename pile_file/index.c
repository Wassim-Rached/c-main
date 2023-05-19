#include<stdio.h>
#include<stdlib.h>


typedef struct 
{
	int num;
	int priority;
}Sommet;

struct Cellule
{
	Sommet sommet;
	struct Cellule *suivant;
};

typedef struct Cellule *Pile;


// functions
int vide(Pile P){
	return P == NULL;
}

void empiler(Pile *P,Sommet sommet){
	Pile new_pile = (Pile) malloc(sizeof(struct Cellule));
	new_pile->sommet = sommet;
	new_pile->suivant = *P;
	*P= new_pile;
}


void depiler(Pile *P){
	Pile K = *P;
	if (!vide(K))
	{
		*P = (*P)->suivant;
		free(K);
	}
}

void afficher(Pile P){
	while(P != NULL){
		printf("num : %d, priority: %d \n",P->sommet.num,P->sommet.priority);
		P=P->suivant;
	}
	}

Sommet sommet(Pile P){
	return P->sommet;
}

void range(Pile *P){
	Pile aux_1 = NULL;
	Pile aux_2 = NULL;
	while (!vide(*P))
	{
		if (sommet(*P).priority == 1)
		{
			empiler(&aux_1,sommet(*P));
		}else{
			empiler(&aux_2,sommet(*P));
		}
		depiler(P);
	};
	while (!vide(aux_1))
	{
		empiler(&aux_2,sommet(aux_1));
		depiler(&aux_1);
	};
	*P = aux_2;
}

int main(){
	Pile P = NULL;
	// 
	// Sommet s1,s2,s3,s4,s5,s6;
	// s1.num = 14;
	// s1.priority = 1;
	// s2.num = 13;
	// s2.priority = 1;
	// s3.num = 12;
	// s3.priority = 2;
	// s4.num = 11;
	// s4.priority = 1;
	// s5.num = 10;
	// s5.priority = 2;
	// s6.num = 19;
	// s6.priority = 1;
	// 
	int choix;
	while (0==0)
	{
		puts("1/ ajouter un dossier.");
		puts("2/ retirer un dossier.");
		puts("3/ consulter le dernier dossier.");
		puts("4/ organiser les dossiers.");
		puts("5/consulter le premier dossier.");
		puts("0/ quitter.");
		printf("====> ");
		scanf("%d", &choix);
		Sommet sommet_var;
		switch(choix)
		{
			case 1:
			do
			{
				printf("saisir le num : ");
				scanf("%d", &(sommet_var.num));
				printf("saisir le priority : ");
				scanf("%d", &(sommet_var.priority));
			} while (sommet_var.priority != 1 && sommet_var.priority !=2);
			empiler(&P,sommet_var);
			break;
			
			case 2:
				depiler(&P);
			break;

			case 3:
				if(vide(P)){
					puts("empty");
				}else{
					Pile aux = NULL;
					while (!vide(P))
					{
						empiler(&aux,sommet(P));
						depiler(&P);
					}
					printf("le dernier dossier , num : %d , priority : %d\n",sommet(aux).num,sommet(aux).priority);
					while (!vide(aux))
					{
						empiler(&P,sommet(aux));
						depiler(&aux);
					}
				}
			break;

			case 4:
				range(&P);
				break;

			case 5:
				if(vide(P)){
					puts("empty");
				}else{
				printf("tete , num : %d , priority : %d \n",sommet(P).num, sommet(P).priority);
				}
			break;

			case 0:
				puts("closing program...");

				break;
			
			default:
				puts("not valid choice");
				break;
		}
		if (choix == 0)
		{
			break;
		}
		
	}
	


	return 0;
}