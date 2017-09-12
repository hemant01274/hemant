#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int, int);
int height(struct Node*);
struct Node* newnode(int);
struct Node *Rright(struct Node*);
struct Node *Rleft(struct Node*);
int balfact(struct Node*);
struct Node* insert(struct Node*, int);
struct Node * minnode(struct Node*);
struct Node* del(struct Node*, int);
void pre(struct Node*);
void in(struct Node*);
void post(struct Node*);
int main(){
  struct Node *root = NULL;
    root = insert(root, 14);
    root = insert(root, 10) ;
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 16);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 7);
    printf("Preorder traversal of the constructed AVL tree is \n");
    pre(root);
    printf("\n");
    printf("inorder traversal of the constructed AVL tree is \n");
    in(root);
    printf("\n");
	printf("Postorder traversal of the constructed AVL tree is \n");
    post(root);
    printf("\n");
    root = del(root, 15);
    printf("\nPreorder traversal after deletion of 15 \n");
    pre(root);
    return 0;
}
int height(struct Node *h){
    if (h == NULL)
        return 0;
    return h->height;
}
int max(int a, int b){
    return (a > b)? a : b;
}
struct Node* newnode(int item){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->item   = item;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}
struct Node* insert(struct Node* node, int item){
    if (node == NULL)
        return(newnode(item));
 
    if (item < node->item)
        node->left  = insert(node->left, item);
    else if (item > node->item)
        node->right = insert(node->right, item);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balfact(node);
    if (balance > 1 && item < node->left->item)
        return Rright(node);
    if (balance < -1 && item > node->right->item)
        return Rleft(node);
    if (balance < -1 && item < node->right->item)
    {
        node->right = Rright(node->right);
        return Rleft(node);
    }
    if (balance > 1 && item > node->left->item)
    {
        node->left =  Rleft(node->left);
        return Rright(node);
    }
    return node;
}

struct Node *Rright(struct Node *p){
    struct Node *s = p->left;
    struct Node *t = s->right;
     s->right = p;
    p->left = t;
    p->height = max(height(p->left), height(p->right))+1;
    s->height = max(height(s->left), height(s->right))+1;
     return s;
}
struct Node *Rleft(struct Node *p){
    struct Node *s = p->right;
    struct Node *t = s->left;
    s->left = p;
    p->right = t;
    p->height = max(height(p->left), height(p->right))+1;
    s->height = max(height(s->left), height(s->right))+1;
    return s;
}
int balfact(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node * minnode(struct Node* node){
    struct Node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}
struct Node* del(struct Node* root, int item){
    if (root == NULL)
        return root;
    if ( item < root->item )
        root->left = del(root->left, item);
    else if( item > root->item )
        root->right = del(root->right, item);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :root->right;
           if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
             struct Node* temp = minnode(root->right);
             root->item = temp->item;
             root->right = del(root->right, temp->item);
        }
    }
     if (root == NULL)
      return root;
     root->height = 1 + max(height(root->left),height(root->right));
     int balance = balfact(root);
     if (balance > 1 && balfact(root->left) >= 0)
        return Rright(root);
     if (balance < -1 && balfact(root->right) <= 0)
        return Rleft(root);
     if (balance < -1 && balfact(root->right) > 0)
    {
        root->right = Rright(root->right);
        return Rleft(root);
    }
    if (balance > 1 && balfact(root->left) < 0)
    {
        root->left =  Rleft(root->left);
        return Rright(root);
    }
 
    return root;
}
void pre(struct Node *root){
    if(root != NULL)
    {
        printf("%d ", root->item);
        pre(root->left);
        pre(root->right);
    }
}
void post(struct Node *root){
    if(root != NULL)
    {
        post(root->left);
        post(root->right);
    	printf("%d ", root->item);
	}
}
void in(struct Node *root){
    if(root != NULL)
    {
        in(root->left);
     	printf("%d ", root->item);
	    in(root->right);
    }
}
