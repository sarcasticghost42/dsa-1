#include<stdio.h>
#include<string.h>
void selection(char s[]){
    char t;
    int l,i,j,min;
    l=strlen(s);
    for(i=0;i<l-1;i++){
        min=i;
        for(j=i+1;j<l;j++){
            if(s[j]<s[min]){
                min=j;
            }
        }
    t=s[min];
    s[min]=s[i];
    s[i]=t;
}
printf("the sorted array is %s",s);
}
void insertion(char s[]){
    int i,j,l;
    char t;
    l=strlen(s);
    for(i=1;i<l;i++){
        for(j=i;j>0;j--){
            if(s[j]<s[j-1]){
                t=s[j-1];
                s[j-1]=s[j];
                s[j]=t;
            }
        }
    }
    printf("sorted array is %s",s);
}
int main(){
    char s[200];
    printf("enter the char array\n");
    scanf("%s",&s);
    insertion(s);
}