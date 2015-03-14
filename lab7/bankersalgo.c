#include<stdio.h>
void main()
{
	int re,p;
	printf("\nEnter number of resources :"); //enter number of resources
	scanf("%d",&re);
	printf("\nEnter number of processes:");  //enter number of processes
	scanf("%d",&p);	
	int av[re],c[p][re],al[p][re],i,j,n[p][re],flag,ch=1,r=0,m[6],state=0,res[re],s;
	
	printf("Enter the resource matrix\n");	//enter resource matrix
	for(i=0;i<re;i++)
	scanf("%d",&res[i]);
	
	
	



	printf("Enter the claim matrix\n");	//enter claim matrix
	for(i=0;i<p;i++)
	{
		for(j=0;j<re;j++)
		{
			scanf("%d",&c[i][j]);
		}
		printf("\n");
	}	
		
	printf("Enter the allocation matrix\n");	//enter allocation matrix
	for(i=0;i<p;i++)
	{
		for(j=0;j<re;j++)
		{
			scanf("%d",&al[i][j]);
		}
		printf("\n");
	}
	//calculating available matrix
	for(j=0;j<re;j++)
	{	
		s=0;		
		for(i=0;i<p;i++)
		{
			s=s+al[i][j];
		}
		av[j]=res[j]-s;
	}
	//printing available matrix	
	printf("Available matrix:\n");
	for(i=0;i<re;i++)
	printf("%d ",av[i]);
	//calculating needy matrix
	for(i=0;i<p;i++)
	{
		for(j=0;j<re;j++)
		{
			n[i][j]=c[i][j]-al[i][j];
		}
	}
	while(ch==1)
	{
	
	for(i=0;i<p;i++)
	{	
		if(m[i]==i)
		continue;		
				
		flag=0;		
		for(j=0;j<re;j++)
		{
			if(n[i][j]<=av[j]) 
			flag++;
		}
		if(flag==re)
		{
			state=1;
			for(j=0;j<re;j++)
			{			
			av[j]=av[j]+al[i][j];
			c[i][j]=0;
			al[i][j]=0;
			}
			r++;
			m[i]=i;
			printf("\nAfter running process %d\n",i+1);
			break;		
		}
	}
	if(state==0)
	{
		ch=0;
		printf("\nUnsafe state\n");
		break;
	}
	printf("Claim matrix:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<re;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

	printf("Availaible matrix:\n");
	for(i=0;i<re;i++)
	printf("%d ",av[i]);

	if(r==p)
	{	
		ch=0;
		printf("\nSafe state\n");
	}
	}
}
