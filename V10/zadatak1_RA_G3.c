#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
	int value;
	struct node_st *right, *left, *parent;
} NODE;

typedef struct descriptor_st {
	NODE *root;
} DESCRIPTOR;

void initialize(DESCRIPTOR *desc);
void insert(DESCRIPTOR *desc, int value);
void insertNode(NODE *root, NODE *pnew);
NODE *createNode(int value);
NODE* find(DESCRIPTOR *desc, int value);
NODE* findNode(NODE *node, int value);
void delete(DESCRIPTOR *desc, int value);
void deleteNode(NODE *node);
void destroy(NODE *node);
void destroyTree(DESCRIPTOR *desc);
void inorder(NODE *root);
void preorder(NODE *root);
void postorder(NODE *root);
void reverse_order(NODE *root);

int main(){
	DESCRIPTOR desc;
	
	initialize(&desc);
	insert(&desc, 8);
	insert(&desc, 5);
	insert(&desc, 9);
	insert(&desc, 6);
	insert(&desc, 4);
	
	find(&desc, 8); 
	
	printf("Inorder: \n");
	inorder(desc.root);
	printf("\n");
	
	printf("Reverse order:\n");
	reverse_order(desc.root);
	printf("\n");
		
	printf("Preorder:\n");
	preorder(desc.root);
	printf("\n");
	
	printf("Postorder:\n");
	postorder(desc.root);
	printf("\n");
	
	delete(&desc, 5);
	delete(&desc, 8);
	delete(&desc, 9);

	destroyTree(&desc);

	return 0;
}

void initialize(DESCRIPTOR *desc){
	desc->root = NULL;
}

NODE *createNode(int value){
	NODE *pnew = malloc(sizeof(NODE));
	
	pnew->value = value;
	pnew->right = NULL;
	pnew->left = NULL;
	
	return pnew;
}

void insert(DESCRIPTOR *desc, int value){
	NODE *pnew = createNode(value);
	
	if(desc->root == NULL){
		pnew->parent = NULL;
		desc->root = pnew;
		return;
	} 
	
	insertNode(desc->root, pnew);
}

void insertNode(NODE *root, NODE *pnew){
	if(root->value == pnew->value){
		free(pnew);
		return;
	}
	
	if(root->value < pnew->value){
		if(root->right == NULL){
			pnew->parent = root;
			root->right = pnew;
		} else {
			insertNode(root->right, pnew);
		}
	} else {
		if(root->left == NULL){
			pnew->parent = root;
			root->left = pnew;
		} else {
			insertNode(root->left, pnew);
		}
	}
}

NODE* find(DESCRIPTOR *desc, int value){
	if(desc->root == NULL){
		return NULL;
	}
	
	return findNode(desc->root, value);
}

NODE* findNode(NODE *node, int value){
	if(node == NULL){
		return NULL;
	}
	
	if(node->value == value){
		return node;
	}
	
	if(node->value > value){
		return findNode(node->left, value);
	} else {
		return findNode(node->right, value);
	}
	
}

void destroy(NODE *node){
	if(node){
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

void destroyTree(DESCRIPTOR *desc){
	if(desc->root == NULL){
		return;
	}
	
	destroy(desc->root);
}

void delete(DESCRIPTOR *desc, int value){
	NODE *del = find(desc, value);
	
	if(del == NULL){
		return;
	}
	
	if(desc->root == del){
		if(del->left == NULL){
			desc->root = del->right;
			free(del);
			return;
		}
		if(del->right == NULL){
			desc->root = del->left;
			free(del);
			return;
		}
	}

	deleteNode(del);	
}

int isLeaf(NODE* node){
	if(node->right == NULL && node->left == NULL){
		return 1;
	} else {
		return 0;
	}
}

void deleteNode(NODE *node){
	NODE *parent = node->parent;
	
	if(isLeaf(node)){	//ukoliko je u pitanju list
		if(parent->left == node){
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}
		
		free(node);
		return;
	}
	
	//ukoliko ima jedno podstablo
	if(node->left == NULL || node->right == NULL){
		NODE *child;
		
		if(node->left) {
			child = node->left;
		} else {
			child = node->right;
		}
		
		child->parent = parent;
		
		if(parent->left == node){
			parent->left = child;
		} else {
			parent->right = child;
		}
		
		free(node);
		return;
	}
	
	//ukoliko ima oba podstabla
	NODE *maxLeft = node->left;
	
	// Pratimo pokazivac do krajnjeg desnog
	// elementa (najveceg) u levom podstablu
	while(maxLeft->right){
		maxLeft = maxLeft->right;
	}
	
	int maxLeftValue = maxLeft->value;
	
	deleteNode(maxLeft);
	
	node->value = maxLeftValue;	
}

void inorder(NODE *root){
	if(root->left){
		inorder(root->left);
	}
	
	printf("%d\t", root->value);
		
	if(root->right){
		inorder(root->right);
	}
	
}

void preorder(NODE *root){

	printf("%d\t", root->value);
	
	if(root->left){
		preorder(root->left);
	}
		
	if(root->right){
		preorder(root->right);
	}
	
}

void postorder(NODE *root){

	if(root->left){
		postorder(root->left);
	}
	
	if(root->right){
		postorder(root->right);
	}
	
	printf("%d\t", root->value);
	
}

void reverse_order(NODE *root){

	if(root->right){
		reverse_order(root->right);
	}
	
	printf("%d\t", root->value);
		
	if(root->left){
		reverse_order(root->left);
	}
	
}
