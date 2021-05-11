#include <stdio.h>
#include <stdlib.h>
//sorting a arr using selection sort
void selectionSort(int *arr,	//ptr to array
					int n)		//no. of elements
{
	int i,l,t;
	
	for(i=1;i<n;i++)
	{
		t=0;
		for(l=1;l<n-i+1;l++)
		{
			if(arr[l]>arr[t])
				t=l;				
		}
		l=arr[n-i];
		arr[n-i]=arr[t];
		arr[t]=l;
		
	}
}
void main()
{
	int n,*arr;
	int i;
	printf("Enter the total no. of elements");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter %d no.: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	selectionSort(arr,n);
	
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
}
