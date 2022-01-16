#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int mssv;
	struct node *next;
}node;


void dealloc(node **root){  //ham giai phong bo nho cac node trong danh sach lien ket 
	node *curr = *root;
	while(curr != NULL){
		node *aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void swap(int *a , int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void add_end(node **root){  //ham them phan tu vao cuoi danh sach
	node *new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	printf("Nhap ma so sinh vien: "); scanf("%d",&new_node->mssv);
	if (*root == NULL){
		*root = new_node;
		return;
	}
	node *curr = *root;
	while(curr->next!=NULL){
		curr = curr->next;
	}
	curr->next = new_node;
}

void add_head(node **root){ //ham them phan tu vao dau danh sach
	node *new_node = (node*)malloc(sizeof(node));
	printf("Nhap ma so sinh vien: "); scanf("%d",&new_node->mssv);
	if (*root == NULL){
		*root = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = *root;
	*root = new_node;
}

void post_data_head_insert(node **root, int data){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->mssv = data;
	if (*root == NULL){
		*root = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = *root;
	*root = new_node;
}

void sorted_insert(node **root){  //ham chen phan tu vao danh sach ma khong lam thay doi thu tu cac
	node *new_node = (node*)malloc(sizeof(node));
	printf("Nhap ma so sinh vien: "); scanf("%d",&new_node->mssv);
	new_node->next = NULL;
	if (*root == NULL || (*root)->mssv >= new_node->mssv){
		post_data_head_insert(root,new_node->mssv);
	}
	node *curr = *root;
	while(curr->next != NULL){
		if ( (curr->next)->mssv >= new_node->mssv){
			break;
		}
		curr = curr->next;
	}
	if (curr->next == NULL){
		curr->next = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = curr->next;
	curr->next = new_node;
}

void delete_element(node **root){  //ham xoa phan tu
	if (*root == NULL){
		return;
	}
	int pos;
	printf("Xoa phan tu thu: "); scanf("%d",&pos);
	if (pos == 1){
		node *aux = *root;
		*root = (*root)->next;
		free(aux);
		return;
	}
	node *curr = *root;
	for (int i=1;i<pos-1;i++){
		curr = curr->next;
	}
	node *aux = (curr->next)->next;
	free(curr->next);
	curr->next = aux;
}

void sort_list(node **root){ //ham sap xep cac phan tu theo thu tu tang dan
	node *i = *root;
	while (i != NULL){
		node *j = i->next;
		while (j != NULL){
			if ( (i->mssv) > (j->mssv) ){
				swap( &(i->mssv) , &(j->mssv) );
			}
			j = j->next;
		}
		i = i->next;
	}
}

void print_list(node **root){ //ham in cac phan tu
	node *curr = *root;
	while(curr!=NULL){
		printf("%d\n",curr->mssv);
		curr = curr->next;
	}
}

int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	node *root = NULL;
	for (int i=1;i<=n;i++){
		printf("Sinh vien thu %d: \n",i);
		add_end(&root);
	}
	add_head(&root);
	sort_list(&root);
	sorted_insert(&root);
	delete_element(&root);
	print_list(&root);
	dealloc(&root);
	return 0;
}
