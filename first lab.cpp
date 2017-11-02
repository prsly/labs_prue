#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void** magic(int** a, int m, int n, int p){
  int max, x, i, j, h, flag, flag2;
    for (i=0;i<m;i++){
      for (j=0;j<n;j++){
        max=a[i][j];
        x=fibocheck(max,p);
        if (x==1){
          flag2=0; flag=0;
          int ch=a[i][j]+1;
          while (flag!=1){
            for(h=2;h<(ch/2);h++){
              if (ch%h==0) flag2++;
              if (flag2=ide-c=0) flag=1;
              else{
                ch++; flag=1;
              }
            }
          }
          a[i][j]=ch;
        }
      }
    }
  printf("\n");
}

int fibocheck(int max, int p){
  int a=1,b=1,c=0,proverka;
  while (b<max){
    c=a+b;
    a=b;
    b=c;
    proverka=a;
    if ((proverka>p) & (max%proverka==0)) return 1;
  }
  return 0;
}

int main(){
  int m,n,i,j,p;
  printf("input size:\n");
  scanf("%d %d",&m, &n);
  int** a=(int**)malloc(sizeof(int*)*m);
  for (i = 0; i<m; i++) a[i] = (int*)malloc(sizeof(int) *n);
  printf("input matrix:\n");
  for (i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);
  printf("Input P:");
  scanf("%d",&p);
  magic(a,m,n,p);
  for (i=0;i<m;i++){
    for(j=0;j<n;j++)
      printf("%d ",a[i][j]);
    printf("\n");
    free(a[i]);
  }
  free(a);
  return 0;
}
