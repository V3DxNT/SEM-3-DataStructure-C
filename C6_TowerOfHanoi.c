#include<stdio.h>
#include<stdlib.h>

void TOI(int,char,char,char);

int main() {
    int n;
    char s="S";
    char a="A";
    char d="D";

    printf("Enter the Total Number of Disks:");
    scanf("%d",&n);

    TOI(n,s,a,d);
}