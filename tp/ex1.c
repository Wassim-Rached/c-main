#include <stdio.h>
#include <stdlib.h> // needed for malloc()

typedef struct Cellule {
    int info;
    struct Cellule* suivant;
} Cellule;

typedef Cellule* Liste; // use pointer to struct instead of aliasing the struct to avoid confusion

void AjoutTrie(Liste* L, int e);
Liste CreerTrie();
void Affiche(Liste L);

int main() {
    Liste K;
    K = CreerTrie();
    AjoutTrie(&K, 0);
    AjoutTrie(&K, 13);
    AjoutTrie(&K, 23);
    AjoutTrie(&K, 4);
    AjoutTrie(&K, 50);
    AjoutTrie(&K, 1);
    AjoutTrie(&K, 9);
    Affiche(K);
    return 0;
}

Liste CreerTrie() {
    Liste L = NULL; // initialize pointer to NULL before allocation
    L = (Liste) malloc(sizeof(Cellule));
    L->info = 0;
    L->suivant = NULL;
    return L; // return pointer instead of dereferencing it
}

void AjoutTrie(Liste* L, int e) {
    Liste K = *L;
    Liste new_liste = (Liste) malloc(sizeof(Cellule)); // allocate memory for new list element
    new_liste->info = e;
    new_liste->suivant = NULL;
    if (K == NULL) {
        *L = new_liste; // if list is empty, new element becomes first element
    } else if (e < K->info) {
        new_liste->suivant = K;
        *L = new_liste; // if new element is smaller than first element, it becomes the new first element
    } else {
        while (K->suivant != NULL && K->suivant->info < e) { // traverse the list until the correct position for the new element is found
            K = K->suivant;
        }
        new_liste->suivant = K->suivant;
        K->suivant = new_liste;
    }
}

void Affiche(Liste L) {
    while (L != NULL) { // traverse the list and print each element's info
        printf("%d ", L->info);
        L = L->suivant;
    }
    printf("\n");
}
