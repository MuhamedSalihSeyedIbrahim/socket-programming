#include<stdio.h>
int main(){
    FILE *a;
    a=fopen("hulk.txt","r");
    int b[9];
    fscanf(a,"%d %d" , &b[0],&b[1]);
    printf("%d %d",b[0],b[1]);
    fclose(a);
}