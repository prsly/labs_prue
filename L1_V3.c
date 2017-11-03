#include <stdio.h>
int main(){
 int a[100],i,n,max=0,maxp,min=32000;
 puts("������� ���������� �����: ");
 scanf("%d",&n);
 puts("������� �����: ");
 for (i=0;i<n;i++){
   scanf("%d",&a[i]);
   if (a[i]>=max)
     {
       max=a[i];
       maxp=i;
  	 }
   if (a[i]<min) min=a[i];
  }
if (maxp<=(n-1)/2 && max>100) for (i=maxp+1;i<n;i++) a[i]=min;
for (i=0;i<n;i++) printf("%d   ",a[i]);
return 0;
}
