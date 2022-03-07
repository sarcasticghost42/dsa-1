#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int xexpo;
    int yexpo;
    int zexpo;
    struct node *next;
};
struct node * insert(struct node *head,int coeff,int xexpo,int yexpo,int zexpo)
{
    struct node *newnode=(struct node *) malloc(sizeof(struct node));
    newnode->xexpo=xexpo;
    newnode->yexpo=yexpo;
    newnode->zexpo=zexpo;
    newnode->data=coeff;
    if((head==NULL)|| xexpo>=head->xexpo)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    struct node *temp=head;
    while(temp->next!=NULL && temp->next->xexpo>=xexpo)
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node * create(struct node *head)
{
    int n,coeff,xexpo,yexpo,zexpo;
    printf("Enter number of terms:-");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter coefficients,exponents (x,y,z) of term %d:-",i);
        scanf("%d%d%d%d",&coeff,&xexpo,&yexpo,&zexpo);
        head=insert(head,coeff,xexpo,yexpo,zexpo);
    }
    return head;
}
struct node * add(struct node *head1,struct node *head2)
{
    struct node *temp1,*temp2,*head3;
    temp1=head1; temp2=head2; head3=NULL; 
    while(temp1!=NULL && temp2!=NULL){
    if((temp1->xexpo == temp2->xexpo && temp1->yexpo == temp2->yexpo && temp1->zexpo == temp2->zexpo))
    {
        head3=insert(head3,temp1->data+temp2->data,temp1->xexpo,temp1->yexpo,temp1->zexpo);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    else if((temp1->xexpo + temp1->yexpo + temp1->zexpo) < (temp2->xexpo + temp2->yexpo + temp2->zexpo))
    {
        head3=insert(head3,temp2->data,temp2->xexpo,temp2->yexpo,temp2->zexpo);
        temp2=temp2->next;
    }
    else if((temp1->xexpo + temp1->yexpo + temp1->zexpo) > (temp2->xexpo + temp2->yexpo + temp2->zexpo))
    {
        head3=insert(head3,temp1->data,temp1->xexpo,temp2->yexpo,temp2->zexpo);
        temp1=temp1->next;
    }
    }
    while(temp1!=NULL)
    {
        head3=insert(head3,temp1->data,temp1->xexpo,temp1->yexpo,temp1->zexpo);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        head3=insert(head3,temp2->data,temp2->xexpo,temp2->yexpo,temp2->zexpo);
        temp2=temp2->next;
    }
    return head3;
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d x^%d y^%d z^%d +",temp->data,temp->xexpo,temp->yexpo,temp->zexpo);
        temp=temp->next;
    }
}
void main()
{
    struct node *head1,*head2,*head3;
    head1=head2=head3=NULL;
    int ch;
    while(1)
    {
        printf("\nEnter 1 to create a poly 1,2 to create poly 2,3 to add, 4 to evaluate poly 1, 5 to display poly 3, 6 to exit:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head1=create(head1);
                   break;
            case 2:head2=create(head2);
                   break;
            case 3:head3=add(head1,head2);
                   break;  
            case 5:display(head3);
                   break;  
            case 6:exit(0);
        }
    }
}