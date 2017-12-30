#include <stdio.h>
#include <stdlib.h>

#define MAX_MARKA 21

typedef struct
{
    char marka[MAX_MARKA];
    unsigned int kubikaza;
    int godina;
} automobil_t;

typedef struct node
{
    struct node *left;
    struct node *right;
    automobil_t value;
} node_t, *tree_t;

void insert(tree_t *tree, automobil_t a)
{
    if (*tree == NULL)
    {
        node_t *new = malloc(sizeof(node_t));
        new->value = a;
        new->left = new->right = NULL;
        *tree = new;
    }
    else if (strcmp(a.marka, (*tree)->value.marka) < 0)
    {
        insert(&(*tree)->left, a);
    }
    else
    {
        insert(&(*tree)->right, a);
    }
}

void deltree(tree_t *tree)
{
    if (*tree != NULL)
    {
        deltree(&(*tree)->left);
        deltree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

void ucitaj(FILE *file, tree_t *tree)
{
    automobil_t a;
    deltree(tree);

    while (fscanf(file, "%s%u%d", a.marka, &a.kubikaza, &a.godina) == 3)
    {
        insert(tree, a);
    }
}

automobil_t *pronadji(tree_t tree, char *marka)
{
    if (tree == NULL) return NULL;

    if (strcmp(marka, tree->value.marka) == 0)
    {
        return &tree->value;
    }
    else if (strcmp(marka, tree->value.marka) < 0)
    {
        return pronadji(tree->left, marka);
    }
    else
    {
        return pronadji(tree->right, marka);
    }
}

void ispis(FILE *file, automobil_t *a)
{
    if (a != NULL) fprintf(file, "%s %u %d\n", a->marka, a->kubikaza, a->godina);
    else printf("Trazeni automobil ne postoji\n");
}

int brisanje(tree_t *tree, char *marka)
{
    if (*tree == NULL) return 0;

    if (strcmp(marka, (*tree)->value.marka) == 0)
    {
        node_t *node = *tree;

        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            *tree = NULL;
        }
        else if (node->left && node->right == NULL)
        {
            *tree = node->left;
            free(node);
        }
        else if (node->right && node->left == NULL)
        {
            *tree = node->right;
            free(node);
        }
        else
        {
            node_t *p = node->right;
            node_t *q = node;

            while (p->left)
            {
                q = p;
                p = p->left;
            }

            if (q->left == p) q->left = p->right;
            else if (q->right == p) q->right = p->right;

            node->value = p->value;
            free(p);
        }
    }
    else if (strcmp(marka, (*tree)->value.marka) < 0)
    {
        return brisanje(&(*tree)->left, marka);
    }
    else
    {
        return brisanje(&(*tree)->right, marka);
    }
}

void snimi(FILE *file, tree_t tree)
{
    if (tree)
    {
        snimi(file, tree->left);
        ispis(file, &tree->value);
        snimi(file, tree->right);
    }
}

automobil_t *najnoviji(tree_t tree, unsigned kubikaza)
{
    automobil_t *rezultat = NULL;
    if (tree == NULL) return NULL;

    automobil_t *nl = najnoviji(tree->left, kubikaza);
    automobil_t *nr = najnoviji(tree->right, kubikaza);

    if (tree->value.kubikaza <= kubikaza)
    {
        rezultat = &tree->value;
    }

    if (rezultat == NULL || (nl != NULL && nl->godina > rezultat->godina))
    {
        rezultat = nl;
    }

    if (rezultat == NULL || (nr != NULL && nr->godina > rezultat->godina))
    {
        rezultat = nr;
    }
}

int main(void)
{
    int radi = 1;
    tree_t tree = NULL;

    while (radi)
    {
        puts("1 - Unos iz datoteke");
        puts("2 - Unos jednog automobila");
        puts("3 - Pronalazenje po marki");
        puts("4 - Brisanje automobila");
        puts("5 - Snimanje u datoteku");
        puts("6 - Pronalazenje najnovijeg");
        puts("7 - Izlaz iz programa");

        int c;
        scanf("%d", &c);

        automobil_t a;
        FILE *file;
        char naziv[100];

        switch (c)
        {
        case 1:
            printf("Unesite ime datoteke: ");
            scanf("%s", naziv);
            file = fopen(naziv, "r");
            if (file)
            {
                ucitaj(file, &tree);
                fclose(file);
            }
            else
            {
                puts("Nije moguce otvoriti datoteku");
            }
            break;

        case 2:
            printf("Unesite marku: ");
            scanf("%s", a.marka);
            printf("Unesite kubikazu: ");
            scanf("%u", &a.kubikaza);
            printf("Unesite godinu: ");
            scanf("%d", &a.godina);
            insert(&tree, a);
            break;

        case 3:
            printf("Unesite marku: ");
            scanf("%s", a.marka);
            ispis(stdout, pronadji(tree, a.marka));
            break;

        case 4:
            printf("Unesite marku: ");
            scanf("%s", a.marka);

            if (brisanje(&tree, a.marka))
            {
                puts("Uspesno obrisan!");
            }
            else
            {
                puts("Nije uspesno obrisan!");
            }
            break;

        case 5:
            printf("Unesite ime datoteke: ");
            scanf("%s", naziv);
            file = fopen(naziv, "w");
            snimi(file, tree);
            fclose(file);
            break;

        case 6:
            printf("Unesite kubikazu: ");
            scanf("%u", &a.kubikaza);
            ispis(stdout, najnoviji(tree, a.kubikaza));
            break;

        case 7:
            radi = 0;
            break;

        default:
            puts("Nepoznata opcija!");
        }
    }

    deltree(&tree);
    return 0;
}
