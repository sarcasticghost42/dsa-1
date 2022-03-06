#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void push(char item){
  if(top>=size-1)
  printf("\nstack overflow");
  else{
    top=top+1;
    stack[top]=item;
  }
}
char pop(){char item;
  if(top<0)
  printf("stack underflow\n");
  else
  item=stack[top];
  top=top-1;
  return item;
}
int is_op(char s){
  if(s=='^'||s=='*'||s=='/'||s=='+'||s=='-') return 1;
  else return 0;
}
int precedence(char s){
  if(s=='^') return 3;
  if(s=='*'||s=='/') return 2;
  if(s=='+'||s=='-') return 1;
  else return 0;
}
void itp1(char infix[],char postfix[]){
  int i=0,j=0;
  char x,item;
  push('(');
  strcat(infix,")");
  item=infix[i];
  while(item!='\0'){
    if(item=='(') push(item);
    else if(isdigit(item)||isalpha(item)){
      postfix[j]=item;
      j++;
    }
    else if(is_op(item)==1){
      x=pop();
      while(is_op(x)==1 && precedence(x)>=precedence(item)){
        postfix[j]=x;
        j++;
        x=pop();
      }
      push(x);
      push(item);
    }
    else if(item==')'){
      x=pop();
      while(x!='('){
        postfix[j]=x;
        j++;
        x=pop();
      }
    }
    else{
      printf("invalid 1\n");
      exit(1);    }
  i++;
  item=infix[i];
  }
  if(top>0) {
    printf("invalid\n");
    exit(1);
  }
   if(top>0) {
    printf("invalid\n");
    exit(1);
  }
  postfix[j]='\0';
  }

  int main(){
    char infix[size],postfix[size];
    printf("enter infix exp\n");
    gets(infix);

    itp1(infix,postfix);
    printf("the postfix exp is \n");
    puts(postfix);
    return 0;
  }