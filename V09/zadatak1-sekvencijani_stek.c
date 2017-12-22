# include <stdio.h>
# include <stdlib.h>
# define BUFFER 40


typedef struct Stek {
    int *pStek;
    int duzina;
    int popunjenost;
} STEK;

void init (STEK *);             // Inicijalizuj stek
void prosiri (STEK *);          // Povecaj kapacitet
void push (STEK *, int);        // Dodaj novi element
int pop (STEK *);               // Skini poslednji dodati element
int top (STEK *);               // Pogledaj poslednji dodati element
FILE *otvori (char *, char *); // Otvara fajl i vraca pokazivac na njega
int racunaj (char *);           // Sam zadatak

int main () {

    printf ("Resenje izraza  je: %d.\n", racunaj("ulaz.txt"));
    
    return 0;
}


void init(STEK * S) {

    S->pStek = malloc(10 * sizeof (int));
    if (S->pStek == NULL) {
        printf ("Greska prilikom alokacije memorije...\n\n");
        exit(1);
    }
    S->duzina = 10;
    S->popunjenost = 0;
    
}

void prosiri(STEK * S) {

    S->duzina *= 2;
    S->pStek = realloc(S -> pStek, S -> duzina * sizeof (int));
    
}

void push(STEK * S, int novi) {

    if (S->duzina <= S->popunjenost) {
        prosiri (S);
    }
    
    ++S->popunjenost;
    S->pStek[S->popunjenost] = novi;
    
}

int pop(STEK * S) {

    if (S->popunjenost == 0) {
        printf ("Stek je prazan.\n");
        exit(2);
    }
    
    int a = S->pStek[S->popunjenost];
    --S->popunjenost;
    return a;
    
}

int top(STEK * S) {

    return S->pStek[S->popunjenost];
    
}


FILE *otvori(char * ime, char * rez) {

    FILE * pok = fopen(ime, rez);
    if (pok == NULL) {
        printf ("Greska prilikom otvaranja fajla.\n\n");
        exit (3);
    }
    return pok;
    
}

int racunaj(char *ulazni) {

    char c;
    int a, b;
    STEK s;
    
    init(&s);
    
    FILE * F = otvori (ulazni, "r");
    
    while ((c = fgetc(F)) != EOF) {
        if (c >= '0' && c <= '9') {
            push(&s, (int)c - 48);       // ASCII(48) je nula
        } else if (c == '/') {
            a = pop(&s);
            b = pop(&s);
            b /= a;
            push (&s, b);
        } else if (c == '*') {
            a = pop(&s);
            b = pop(&s);
            b *= a;
            push (&s, b);
        } else if (c == '+') {
            a = pop(&s);
            b = pop(&s);
            b += a;
            push (&s, b);
        } else if (c == '-') {
            a = pop(&s);
            b = pop(&s);
            b -= a;
            push (&s, b);
        }
    }
    
    fclose (F);
    
    a = pop(&s);
    
    free(s.pStek);
    
    return a;
}
