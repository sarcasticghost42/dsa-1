#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void in(struct node* root){
    if(root==NULL) return;
    in(root->left);
    printf("%d->",root->data);
    in(root->right);
}
void pre(struct node* root){
    if(root==NULL) return;
    printf("%d->",root->data);
    pre(root->left);
    pre(root->right);
}
void post(struct node* root){
    if(root==NULL) return;
    post(root->left);
    post(root->right);
    printf("%d->",root->data);
}
struct node* create(int value){
    struct node* newn=malloc(sizeof(struct node));
    newn->data =value;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}
struct node* insert(struct node* node,int value){
    if(node ==NULL) return create(value);
   if(value<node->data)
   node->left=insert(node->left,value);
   else node->right=insert(node->right,value);
    return node;
}
int flag=0;
void search(struct node* root,int key){
    if(root->data==key){
        flag=1;
        return;
    }
    else{
    if(flag==0 && root->left!=NULL){
        search(root->left,key);
    }
    if(flag==0 && root->right!=NULL){
        search(root->right,key);
    }
    return;
    }
}
int main(){
    int i,n,ele;
    printf("enter the number of values\n");
    scanf("%d",&n);
    struct node* root=NULL;
    for(i=0;i<n;i++){
        printf("enter node\n");
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    in(root);
    printf("\n");
    pre(root);
    printf("\n");
    post(root);
    printf("\n");
    search(root,85);
    if(flag==0) printf("not found");
    else printf("found");
    return 0;
}