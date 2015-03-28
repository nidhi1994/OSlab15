/*There are 5 processes requiring the memory :
P1 -> 100 KB
P2 -> 275 KB
P3 -> 170 KB
P4 -> 340 KB
P5 -> 500 KB
Take the suitable layout and size of memory  and show graphically  how first fit, best fit, worse fit and next fit will assign the memory block.
What will the amount of Internal  / External fragmentation.
Try to make your program  general as possible.  Add some graphical components . You may design your scenario around this. 
*/
#include<stdio.h>
#include<malloc.h>
void main()
{
	int m[10],p[5],x[10],i,j,choice,min,max,k,cnt,intf=0,extf=0,y[10]={0};
	char n[10];
	p[0]=100;
	p[1]=275;
	p[2]=170;
	p[3]=340;
	p[4]=500;

	m[0]=200;
	m[1]=80;
	m[2]=700;
	m[3]=120;
	m[4]=225;
	m[5]=300;
	m[6]=400;
	m[7]=100;
	m[8]=180;
	m[9]=900;

	for(i=0;i<10;i++)
	{

		x[i]=m[i];

	}

	for(i=0;i<10;i++)
	{

		n[i]=(char*)malloc(m[i]*1000);

	}

	printf("1.First Fit\n");
	printf("2.Best Fit\n");
	printf("3.Worst Fit\n");
	printf("4.Next Fit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{

		case 1: //first fit

			i=0;			
			while(i!=5)			
			{

				for(j=0;j<10;j++)
				{

					if(m[j]>=p[i])
					{

						m[j]=m[j]-p[i];
						y[j]=m[j];						
						n[j]=(char*)malloc(p[i]*1000);
						break;

					}

				}
				i++;

			}
			break;

		case 2: //best fit

			cnt=0;
		b:	for(i=0;i<9;i++)
			{

				min=x[i];
				for(j=i+1;j<10;j++)
				{

					if(min>x[j])
					{

						min=x[j];
						x[j]=x[i];
						x[i]=min;
				
					}

				}
	
			}			

						
			while(cnt!=5)			
			{

				for(j=0;j<10;j++)
				{

					if(x[j]>=p[cnt])
					{

						for(k=0;k<10;k++)
						{

							if(m[k]==x[j])
							{
	
								m[k]=m[k]-p[cnt];	
								y[k]=m[k];								
								break;						

							}

						}
						x[j]=x[j]-p[cnt];
						n[j]=(char*)malloc(p[i]*1000);
						break;

					}

				}
				cnt++;
				goto b;

			}
			
			break;			


		case 3: //worst fit
			cnt=0;
		a:	for(i=0;i<9;i++)
			{

				max=x[i];
				for(j=i+1;j<10;j++)
				{

					if(max<x[j])
					{

						max=x[j];
						x[j]=x[i];
						x[i]=max;
				
					}

				}
	
			}
			
			
						
			while(cnt!=5)			
			{

				for(j=0;j<10;j++)
				{

					if(x[j]>=p[cnt])
					{

						for(k=0;k<10;k++)
						{

							if(m[k]==x[j])
							{
	
								m[k]=m[k]-p[cnt];	
								y[k]=m[k];								
								break;						
								
							}

						}
						x[j]=x[j]-p[cnt];
						n[j]=(char*)malloc(p[cnt]*1000);
												
						break;

					}

				}
				cnt++;
				goto a;

			}
			break;

		case 4: //next fit

			i=0;
			k=0;
			while(i!=5)
			{

				for(j=k;j<10;j++)
				{
				
					if(m[j]>=p[i])
					{

						k=j;
						m[j]=m[j]-p[i];
						y[j]=m[j];
						n[j]=(char*)malloc(p[i]*1000);
						break;

					}
					if(j==9)
					{

						k=0;
					}

				}
				i++;

			}

			break;

		default:

			printf("Wrong choice\n");
			break;						

	}

	for(i=0;i<10;i++)
	{

		printf("%d\n",m[i]);

	}
	for(i=0;i<10;i++)
	{

		extf=extf+m[i];

	}

	for(i=0;i<10;i++)
	{

		intf=intf+y[i];

	}
	printf("Internal fragmentation %d\n",intf);
	printf("External fragmentation %d\n",extf);

}	
//printf("\t|-----|\n");
	//	printf("\t  %d\n",m[i]);	
