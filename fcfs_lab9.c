/*Write a C program to implement First Come First Serve Scheduling Algorithm. (Consider all
processes are arrived at time 0).
Inputs: Number of processes, Burst Time of each process.
Outputs: Turnaround time and waiting time of each process.*/
#include<stdio.h>
void main()
{
	int n,i,j;
	printf("Enter number of process\n");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	printf("Enter burst time for each process\n");
	for(i=0;i<n;i++)
	{printf("Process %d:\t",i+1);	
	scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
	wt[i]=0;
	for(j=0;j<i;j++)
		wt[i]=wt[i]+bt[j];	
	}
	for(i=0;i<n;i++)
	tat[i]=wt[i]+bt[i];
	printf("wait time\tturnaround time\n");	
	for(i=0;i<n;i++)
	
	{
	printf("%d\t\t\t%d\n",wt[i],tat[i]);	
	
	}
}
