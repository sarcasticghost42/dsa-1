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
struct node* insertleft(struct node* root,int value){
    root->left=create(value);
    return root->left;
}
struct node* insertRight(struct node* root, int value) {
  root->right = create(value);
  return root->right;
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
    struct node* root=create(1);
    insertleft(root,2);
    insertRight(root,3);
    insertleft(root->left,4);
    insertRight(root->left,5);
    insertleft(root->right,6);
    insertRight(root->right,7);
    in(root);
    printf("\n");
    pre(root);
    printf("\n");
    post(root);
    printf("\n");
    search(root,8);
    if(flag==0) printf("not found");
    else printf("found");
    return 0;
}