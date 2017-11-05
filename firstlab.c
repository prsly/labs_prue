#include <stdio.h>
#include "stdafx.h"
#include <conio.h>

int main(){
  int a [10][10],i,j,m,n,p;
  int f,d,f0,f1,f2,z;
  printf("vvedite m n");
  scanf("%d%d",&m,&n);
  printf("\n vvedite elementy\n");
  for (i=0;i<m;i++) for (j=0;j<n;j++) scanf("%d",&a[i][j]);
  printf("vvod zakonchen");
  printf("\n vvedite p \n");
  scanf("%d",&p);
  for (i=0;i<m;i++) for (j=0;j<n;j++) for (d=p+1;d<=a[i][j];d++) if(a[i][j]%d==0){
    f0=1;f1=1;
    while (f1<d){
      f2=f0+f1;
      f0=f1;
      f1=f2;
    }
    if (f1==d){
      f=1;
      z=a[i][j]+1;
      while (f){
        q=1;
        for (d=2;d<=z/2;d++) if (z%d==0) q=0;
        if(q){
          a[i][j]=z;
          f=0;
        }
      }
    }
    if(f==0) break;
  }
  printf ("matrica");
  for (i=0;i<m;i++){
    for (j=0;j<n;j++) printf("%6d",a[i][j]);
    printf("\n");
  }
  return 0;
}
