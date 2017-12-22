#include <stdio.h>
#include <stdlib.h>

/* Struktura koja predstavlja cvor liste */
struct node_t {
  char contents;
  struct node_t *pnext;
};

/* Struktura koja predstavlja deskriptor liste i sadrzi pokazivac na pocetak liste */
struct list_descriptor_t {
  struct node_t *phead; // pokazivac na pocetak liste (glava liste)
};

typedef struct node_t NODE;
typedef struct list_descriptor_t LIST_DESCRIPTOR;

/* Inicijalizacija liste - postavljanje glave na NULL */
void initialize(LIST_DESCRIPTOR *);

/* Oslobadjanje svih elemenata u listi i postavljanje glave na NULL */
void destroy(LIST_DESCRIPTOR *);

/* Dodavanje elemenata na kraj liste */
LIST_DESCRIPTOR *push_back(LIST_DESCRIPTOR *, char);  // dodaje element na kraj liste

/* Ispis elemenata liste */
void print_list(LIST_DESCRIPTOR);

/* Ispis sadrzaja deskriptora liste */
void print_descriptor(LIST_DESCRIPTOR);

/* Dodavanje elementa na pocetak liste */
LIST_DESCRIPTOR *add_first(LIST_DESCRIPTOR *, char); // dodaje element na pocetak liste

/* Dodavanje elementa u listu */
int insert(LIST_DESCRIPTOR *, char, int); // dodaje element na proizvoljnu poziciju u listi koja se zadaje, broji se od 0

/* Brisanje elementa liste */
LIST_DESCRIPTOR *delete(LIST_DESCRIPTOR *, char); // brise zadati karalter iz liste

int main() {
  LIST_DESCRIPTOR descriptor;

  initialize(&descriptor);
  
  print_descriptor(descriptor);

  push_back(push_back(push_back(&descriptor, 'a'), 'b'), 'c');

  print_list(descriptor);
  
  insert(&descriptor, 'd', 1);
  
  print_list(descriptor);
  
  insert(&descriptor, 'e', 2); 
  
  print_list(descriptor);
  
  print_descriptor(descriptor);

  destroy(&descriptor);
  
  print_descriptor(descriptor);
  
  add_first(add_first(add_first(&descriptor,'a'), 'b'), 'c');
  
  print_list(descriptor);
  
  print_descriptor(descriptor);
  
  delete(&descriptor, 'b');
  
  print_list(descriptor);

  destroy(&descriptor);

  return 0;
}

void initialize(LIST_DESCRIPTOR *pdescriptor) {
  pdescriptor->phead = NULL;
}

NODE *new_node(char contents) {
  NODE *pnew = malloc(sizeof(char));
  pnew->contents = contents;
  pnew->pnext = NULL;
  return pnew;
}

LIST_DESCRIPTOR *push_back(LIST_DESCRIPTOR *pdescriptor, char contents) {
  NODE *pnew = new_node(contents);
  NODE *pcurr = pdescriptor->phead;
  if (pcurr == NULL) {
    pdescriptor->phead = pnew;
  } else {
    while (pcurr->pnext != NULL) {  // prolazak do poslednjeg elementa u listi
      pcurr = pcurr->pnext;
    }
    pcurr->pnext = pnew;
  }
  return pdescriptor;
}

LIST_DESCRIPTOR *add_first(LIST_DESCRIPTOR *pdescriptor, char contents){
	NODE *pnew = new_node(contents);
	if (pdescriptor->phead == NULL){
		pdescriptor->phead = pnew;
	} else {
		pnew->pnext = pdescriptor->phead;
		pdescriptor->phead = pnew;
	}
}

void print_list(LIST_DESCRIPTOR descriptor) {
  NODE *pcurr = descriptor.phead;
  printf("[ ");
  while (pcurr != NULL) {
    printf("%c", pcurr->contents);
    pcurr = pcurr->pnext;
    if (pcurr != NULL) {
      printf(", ");
    }
  }
  printf(" ]\n");
}

LIST_DESCRIPTOR *delete(LIST_DESCRIPTOR *pdescriptor, char contents){
  NODE *pcurr = pdescriptor->phead;
  if (pcurr == NULL){ // lista je prazna
    return;
   }
  if (pcurr->contents == contents){ // ako brisemo sa pocetka
        pdescriptor->phead = pcurr->pnext;
        free(pcurr);
        return pdescriptor;
    }
  pcurr = pdescriptor->phead;
  while (pcurr->pnext != NULL){ 
	  if (contents == pcurr->pnext->contents){ // brisemo iz sredine ili sa kraja
		 NODE *ptemp = pcurr->pnext;
     pcurr->pnext = pcurr->pnext->pnext;
     free(ptemp);
     return pdescriptor;
		}
		pcurr = pcurr->pnext;
  }
    return pdescriptor;
}

void print_descriptor(LIST_DESCRIPTOR descriptor){
  printf("[ ");
  if (descriptor.phead != NULL) {
    printf("%p ", descriptor.phead);
  }
  printf(" ]\n");
}

int insert(LIST_DESCRIPTOR *pdescriptor, char contents, int position){
	NODE *pcurr = pdescriptor->phead;
	int i = 0;
	if(position==0){ // ukoliko se ubacuje na pocetak liste
		NODE *pnew = new_node(contents);
		pnew->pnext = pdescriptor->phead;
		pdescriptor->phead = pnew;
		return 1;
	}
	while(pcurr->pnext != NULL){
		if(i<position-1){
			pcurr = pcurr->pnext;
			i++;	
		} else break; 
	}
	if(position-1 > i){ // ukoliko se zada nepostojeca pozicija, ili prodje cela lista, nece se nista desiti
		return 0;
	}
	NODE *pnew = new_node(contents);
	pnew->pnext = pcurr->pnext;
	pcurr->pnext = pnew;
	return 1;
}

void destroy(LIST_DESCRIPTOR *pdescriptor) {
  NODE *ptemp = NULL;
  while (pdescriptor->phead) {
    ptemp = pdescriptor->phead;
    pdescriptor->phead = ptemp->pnext;
    free(ptemp);
  }
  initialize(pdescriptor);
}

