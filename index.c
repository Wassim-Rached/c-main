#include<stdio.h>
#include<stdlib.h>

typedef struct Cellule{
	int info;
	struct Cellule *suivant;
}Cellule;

typedef struct File{
	Cellule *queue;
	Cellule *tete;
}File;


File init();
void difiler(File *file);
void enfiler(File *file,int a);
Cellule* tete(File *file);
int vide(File file);
int sommet(File file);
// 
void Copie(File *F1,File *F2);
int SommeIteratif(File F);
int SommeRecursif(File F);
void SupprimerElementsNegatifs(File *F);
void afficherRecursif(File F);
void AfficherInverseRecursif(File F);

int main(){
	File F1 = init();
	int i;
	int values[4] = {1 ,2 ,3 ,4 };
	for (i = 0; i < 4; i++)
	{
		enfiler(&F1,values[i]);
	}

	return 0;
}

File init(){
	File file;
	file.queue=NULL;
	file.tete=NULL;
	return file;
}

int vide(File F){
	return F.tete == NULL;
}

int sommet(File file){
	return file.tete->info;
}

Cellule* tete(File *file){
	return file->tete;
}

void enfiler(File *file,int a){
	Cellule *new_item = (Cellule*) malloc(sizeof(Cellule));
	new_item->info = a;
	new_item->suivant = NULL;
	if (!vide(*file)){
		file->queue->suivant = new_item;
	}else{
		file->tete = new_item;
	}
		file->queue = new_item;
}


void difiler(File *file){
	if(vide(*file)) return;

	Cellule *first_item = tete(file);
	if (tete(file)->suivant == NULL)
	{
		file->tete = NULL;
		file->queue = NULL;
	}else{
		file->tete = file->tete->suivant;
	}
	free(first_item);
}

void Copie(File *F1,File *F2){
	while(!vide(*F1)){
		enfiler(F2,sommet(*F1)); 
		difiler(F1);
	}
}

int SommeIteratif(File F){
	int sum=0;
	 while(!vide(F)){
		sum+=sommet(F);
		difiler(&F);
	 }
	 return sum; 
}

int SommeRecursif(File F){
	if(vide(F)) return 0;
	else {
		int valeur = sommet(F);
        difiler(&F);
		return SommeRecursif(F)+valeur;
	}
}

void SupprimerElementsNegatifs(File *F){
	File aux =init(); 
	while(!vide(*F)){
		if(sommet(*F)>0){
			enfiler(&aux,sommet(*F));
			difiler(F);
		}
	F->tete=aux.tete;
	F->queue=aux.queue;
	}
}
void afficherRecursif(File F){
	if(vide(F)) return; 

	printf("%d\n",sommet(F));
	difiler(&F);
	afficherRecursif(F);
}

void afficherRecursifInverser(File F){
	if(vide(F)) return;
	else {
		int value = sommet(F);
		difiler(&F);
		afficherRecursifInverser(F);
		printf("%d\n",value);
	}
}

