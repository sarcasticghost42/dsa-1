#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int compute(char sym,int op1,int op2){
    switch(sym){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '%':return op1 % op2;
        case '^':return pow(op1,op2);
        default:return 0;
    }
}
void main(){
    int s[20],res,op1,op2;
    int top,i;
    char postfix[100],sym;
    printf("enter exp\n");
    scanf("%s",postfix);
    top=-1;
    for(i=0;i<strlen(postfix);i++){
        sym=postfix[i];
        if(isdigit(sym))
        s[++top]=sym-'0';
        else{
            op2=s[top--];
            op1=s[top--];
            res=compute(sym,op1,op2);
            s[++top]=res;

        }
    }
    res=s[top--];
    printf("result is %d \n",res);
}