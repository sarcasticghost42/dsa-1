#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo,coeff;
    struct node *link; 
};
typedef struct node x;
x *insert(x *head,int co,int ex){
    x *temp;
    x *newp=malloc(sizeof(x));
    newp->coeff=co;
    newp->expo=ex;
    if(head==NULL||ex>head->expo){
        newp->link=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->link!=NULL && head->link->expo>=ex){
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }
    return head;
}
x *create(x *head){
    int n,i,coeff,expo;
    printf("enter the number of terms\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the coeffient\n");
        scanf("%d",&coeff);
        printf("enter the exponent\n");
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void print(x *head){
    if(head==NULL)
    printf("no polynomial exist\n");
    else{
        x *temp=head;
        while(temp!=NULL){
            printf("(%d ^ %d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            printf("+");
            else
            printf("\n");
        }
    }
}
void add(x *head1,x *head2){
    x *ptr1=head1,*ptr2=head2,*head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr2->expo>ptr1->expo){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while (ptr1!=NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->link;
    }
    printf("final result : \n");
    print(head3);
}
int main(){
    x *head1=NULL,*head2=NULL;
    printf("enter the first poly\n");
    head1=create(head1);
    printf("enter the second poly\n");
    head2=create(head2);
    add(head1,head2);
    return 0;
}