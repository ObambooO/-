#include <stdio.h>
void main()
{
	int a[5]={8,2,3,4,5},b[5]={2,5,3,6,8},c[5],i,j,k=0,temp=0;
	
	for(i=0;i<5;i++)
	    for(j=0;j<5;j++)
	       if(a[i]==b[j])
	       		{
	           	c[k]=a[i];
				k++;}
				//printf("%d\t",k);
	for(i=0;i<k-1;i++)
	{	for(j=i+1;j<k;j++)
	   {	if(c[j]>c[i])
	           {temp=c[j];
	            c[j]=c[i];
	            c[i]=temp;
			   }
	   			
	   			
		}
	}
	for(i=0;i<k;i++)
		printf("%d\n",c[i]);
 } 
