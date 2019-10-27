#include <stdio.h>
void main()
{
	int length=10;
	int i=0,n=0,a[10]={8,9,1,7,6,10,11,21,5,15},x,y;
	scanf("%d%d",&x,&y);
	while(i<10)
	{
		if(a[i]>=x&&a[i]<=y)
		n++;
		else
		a[i-n]=a[i];
		i++;
	}
	length-=n;
	for(i=0;i<length;i++)
		printf("\n%d",a[i]);
}
