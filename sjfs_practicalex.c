#include<stdio.h>
void main()
{
	int n,i,j,temp;
	printf("Enter number of process\n");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],bt1[n];
	printf("Enter burst time for each process\n");
	for(i=0;i<n;i++)
	{
	printf("Process %d:\t",i+1);	
	scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	{
	bt1[i]=bt[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bt1[i]>bt1[j])
			{
				temp=bt1[i];
				bt1[i]=bt1[j];
				bt1[j]=temp;
							
					
			}		
				
		}
	}
	for(i=0;i<n;i++)
	printf("%d",bt1[i]);
	

	for(i=0;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<n;j++)
		{
		if(bt[i]==bt1[j])
		break;
		wt[i]=wt[i]+bt1[j];	
		}
	
	}
	for(i=0;i<n;i++)
	tat[i]=wt[i]+bt[i];
	printf("wait time\tturnaround time\n");	
	for(i=0;i<n;i++)
	{
	printf("%d\t\t\t%d\n",wt[i],tat[i]);	
	
	}
}
