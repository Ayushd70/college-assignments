#include<stdio.h>
#include<stdlib.h>
int* getMat(int m,int n)
{
	int i,l;
	int *a=(int*)malloc(m*n*sizeof(int));
	printf("\n Enter %d*%d=%d numbers:\n",m,n,m*n);
	for(i=0;i<m;i++) 
		for(l=0;l<n;l++)
			scanf("%d",&a[i*n+l]);
	return a;
}
void sortRow(int *a,int m,int n)
{
	int i,l,j,t;
	for(i=0;i<m;i++)
	{
		for(l=0;l<n-1;l++)
			for(j=0;j<n-1-l;j++)
			{
				if(a[i*n+j]>a[i*n+j+1] && i%2==0 || a[i*n+j]<a[i*n+j+1] && i%2!=0)
				{
					t=a[i*n+j];
					a[i*n+j]=a[i*n+j+1];
					a[i*n+j+1]=t;		
				}
			}
	}
}
void sortCol(int *a,int m,int n)
{
	int i,l,j,t;
	for(i=0;i<m;i++)
	{
		for(l=0;l<n-1;l++)
		{
			for(j=0;j<n-1-l;j++)
			{
				if(a[j*n+i]>a[(j+1)*n+i])
				{
					t=a[j*n+i];
					a[j*n+i]=a[(j+1)*n+i];
					a[(j+1)*n+i]=t;		
				}
			}
		}
	}
}
void snake_sort(int *a,int m,int n)
{
	int c1=0,max=((m>n)?m:n);
	
	while(c1<max)
	{
		sortRow(a,m,n);
		sortCol(a,m,n);
		c1++;
	}
}
void print_mat(int *a,int m,int n)
{
	int i,l;
	for(i=0;i<m;i++)
	{
		for(l=0;l<n;l++)
			printf("%d\t",a[i*n+l]);
		printf("\n");
	}
}
int main()
{
	int m,n,*a;
	printf("\n Enter dimention: ");
	scanf("%d",&n);
	a=getMat(n,n);
	
	printf("\n Initial: \n");
	print_mat(a,n,n);
	
	printf("\n Final: \n");
	snake_sort(a,n,n);
	print_mat(a,n,n);
	return 0;
}
/*
4
12 43 54 2
7 8 4 3
4 56 3 09
-34 32 2 8
*/
