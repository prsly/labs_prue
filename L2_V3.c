#include <stdio.h>
int main(){
 	int a[100][100],i,j,j2,m,n,max,sum,c,s,buf;
 	puts("Введите число M: ");
 	scanf("%d",&m);
 	puts("Введите число N: ");
 	scanf("%d",&n);
 	puts("Vvedite 4isla");
 	for (i=0;i<m;i++) for (j=0;j<n;j++) scanf("%d",&a[i][j]);
	for (i=0;i<m;i++){
		max=-2147483647;
		sum=0;
		for (j=0;j<n;j++)
    if (a[i][j]>max) max=a[i][j];
		if (max>0){
			for (c=1;c<max;c++) if (max % c == 0) sum+=c;
			if (max == sum) {
				for(s = 0; s < n/2; s++) {
    			    buf = a[i][s];
     	  	 	  a[i][s] = a[i][n - s - 1];
    			    a[i][n - s - 1] = buf;
 			    }
			}
		}
	}
  printf("\n");
	 for (i=0;i<m;i++){
     for (j=0;j<n;j++) printf("%5d",a[i][j]);
     printf("\n");
	}
	return 0;
}
