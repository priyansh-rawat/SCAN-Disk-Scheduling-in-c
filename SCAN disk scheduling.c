#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void sort(int a[],int size, int flag)
{
	int i;
	qsort(a,size, sizeof(int),cmpfunc);
	if(flag==1)
	{
		for(i=size-1;i>=0;i--)
		{
			printf(" -> %d",a[i]);
		}
	}
	else
	{
		for(i=0;i<size;i++)
		{
			printf(" -> %d",a[i]);
		}
	}
}

int main()
{
	int n,max,current,prev,*a,i,*q1,*q2,j=0,k=0;
	static int total=0;
	
	printf("Enter size of disk: ");
	scanf("%d",&max);
	printf("Enter number of pending requests: ");
	scanf("%d",&n);
	printf("Enter the current request: ");
	scanf("%d",&current);
	printf("Enter the previous request: ");
	scanf("%d",&prev);
	
	a=(int*)malloc(n*(sizeof(int)));	
	q1=(int*)malloc(n*(sizeof(int)));
	q2=(int*)malloc(n*(sizeof(int)));
	
	printf("Enter the requests: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<current)
		{
			q1[j]=a[i];
			j++;	
		}
		else
		{
			q2[k]=a[i];
			k++;	
		}	
	}

	/*	
	for(i=0;i<j;i++)
	{
		printf("%d",q1[i]);
	}
	for(i=0;i<k;i++)
	{
		printf("%d",q2[i]);
	}
	*/
	
	if(current<prev)
	{	
		printf("%d",current);
		sort(q1,j,1);
		printf(" -> 0");
		sort(q2,k,0);
		
	}
	else
	{
		printf("%d",current);
		sort(q2,k,0);
		printf("-> %d",max);
		sort(q1,j,1);
	}
	
	free(a);
	free(q1);
	free(q2);
	return 0;
}
