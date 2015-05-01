#include<stdio.h>
#ifndef VST_NV_NODE
#define VST_NV_NODE
struct node
{
int processNumber, arrivalTime, deadline, executionTime;
struct node *next;

};
int prnum = 1, totalTime = 0;

inline void getdata(struct node *obj, struct node *nextlink)
{
obj->processNumber = prnum;
printf("\nEnter Arrival Time for Process %d:", prnum);
scanf("%d", &obj->arrivalTime);


printf("\nEnter Execution Time for Process %d:", prnum);
scanf("%d", &obj->executionTime);

printf("\nEnter Deadline for Process %d:", prnum);
scanf("%d", &obj->deadline);


obj->next=nextlink;
prnum++;
totalTime += obj->executionTime;
}

#endif


