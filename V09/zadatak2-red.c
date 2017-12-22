#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 50

typedef struct
{
    FILE *datoteka;
    int ukupno_vreme;
} salter_t;

typedef struct node
{
    struct node *next;
    char ime[MAX_IME];
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} queue_t;

void init_queue(queue_t *queue)
{
    queue->head = queue->tail = NULL;
}

int enqueue(queue_t *queue, char *ime)
{
    node_t *new = malloc(sizeof(node_t));
    if (!new) return 0;

    strcpy(new->ime, ime);
    new->next = NULL;

    if (queue->tail) queue->tail->next = new;
    else queue->head = new;
    queue->tail = new;

    return 1;
}

int dequeue(queue_t *queue, char *ime)
{
    if (queue->head == NULL) return 0;
    node_t *temp = queue->head;
    queue->head = temp->next;
    if (!queue->head) queue->tail = NULL;
    strcpy(ime, temp->ime);
    free(temp);
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Primer pokretanja programa: ./a.out ime_datoteke.txt broj_saltera\n");
        return 1;
    }

    FILE *ulaz = fopen(argv[1], "r");
    if (ulaz == NULL)
    {
        printf("Greska pri otvaranju datoteke!\n");
        return 2;
    }

    int broj_saltera = atoi(argv[2]);
    char ime[MAX_IME];

    queue_t red;
    init_queue(&red);

    while (fscanf(ulaz, "%s", ime) == 1)
    {
        enqueue(&red, ime);
    }

    fclose(ulaz);

    salter_t *salteri = calloc(broj_saltera, sizeof(salter_t));

    int i;
    for (i = 0; i < broj_saltera; i++)
    {
        char naziv[20];
        sprintf(naziv, "salter%d.txt", i + 1);

        salteri[i].ukupno_vreme = 0;
        salteri[i].datoteka = fopen(naziv, "w");
    }

    int salter = 0;
    while (dequeue(&red, ime))
    {
        fprintf(salteri[salter].datoteka, "%s\n", ime);
        salteri[salter].ukupno_vreme++;

        salter++;
        salter %= broj_saltera;
    }

    for (i = 0; i < broj_saltera; i++)
    {
        fprintf(salteri[i].datoteka, "--------------\n%d\n", salteri[i].ukupno_vreme);
        fclose(salteri[i].datoteka);
    }

    free(salteri);
    return 0;
}

