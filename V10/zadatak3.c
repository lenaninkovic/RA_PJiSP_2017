#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
	float inf;
	struct node_st *right;
	struct node_st *left;
} NODE;

float sum(NODE *);
int number_of_elements(NODE *);
void print(NODE *);
void print_leaf(NODE *);
NODE* findNode(NODE *, float);
float max_value(NODE *);
NODE* pointer_on_max_value(NODE *);
int depth(NODE *);
int number_of_elements_on_level(int, NODE *);

int main() {

	int i;

	NODE *tree = (NODE*) malloc(sizeof(NODE));
	tree->inf = 8;
	tree->left = (NODE*) malloc(sizeof(NODE));
	tree->right = (NODE*) malloc(sizeof(NODE));

	NODE *p;
	p = tree->left;
	p->inf = 5;
	p->left = (NODE*) malloc(sizeof(NODE));
	p->right = (NODE*) malloc(sizeof(NODE));
	
	p->left->inf = 4;
	p->right->inf = 6;
	
	p = tree->right;
	p->inf = 9;
	
	printf("Tree elements: ");
	print(tree); 
	printf("\nElement sum: %.2f\n", sum(tree));
	printf("Number of elements: %d\n", number_of_elements(tree));
	printf("Leaves: ");
	print_leaf(tree);
	printf("\n");
	
	float e;
	printf("Enter element value:\n");
	scanf("%f", &e);
	NODE *found =findNode(tree, e);
	if(found != NULL) {
		printf("Element %.2f found!\n", e);
	} else {
		printf("Element %.2f not found!\n", e);
	}
	
	printf("Tree depth: %d\n", depth(tree));
	for (i = 0; i < depth(tree); i++) {
		printf("Number of elements on %i. level is: %d\n", i, number_of_elements_on_level(i, tree));
	}

	return 0;
}

float sum(NODE *root) {
	if (root)
		return root->inf + sum(root->left) + sum(root->right);
	else
		return 0;
}

int number_of_elements(NODE *root) {
	if (root) {
		return 1 + number_of_elements(root->left) + number_of_elements(root->right);
	} else { 
		return 0;
	}
}

void print(NODE *root) {
	if (root) {
		printf("%.2f ", root->inf);
		print(root->left);
		print(root->right);
	}
}

void print_leaf(NODE *root) {
	if (root) {
		if (!root->left && !root->right) { 
			printf("%.2f ", root->inf); 
		} else { 
			print_leaf(root->left);
			print_leaf(root->right);
		}
	}
}

NODE* findNode(NODE *node, float value){
	if(node == NULL){
		return NULL;
	}
	
	if(node->inf == value){
		return node;
	}
	
	if(node->inf > value){
		return findNode(node->left, value);
	} else {
		return findNode(node->right, value);
	}
	
}

float max(float x, float y) {
	return x > y ? x : y;
}

float max_value(NODE *root) {
	if (root) {
		return max(root->inf, max(max_value(root->left), max_value(root->right)));
	}
}

int depth(NODE *root) {
	if (root) {
		return 1 + max(depth(root->left), depth(root->right)); 
	} else {
		return 0;
	}
}

int number_of_elements_on_level(int level, NODE *root) {
	if (root) {
		if (level == 0) { 
			return 1;
		} else { 
			return number_of_elements_on_level(level - 1, root->left) + number_of_elements_on_level(level - 1, root->right); 
		}
	} else {
		return 0;
	}
}
