#include<stdio.h>
#include<stdlib.h>

void main()
{

int i, j, n, bt[10], wt[10], tat[10], awt = 0, atat = 0;

//n is number of tasks
//bt is the process time for each task
//wt is the waiting tie for each task
//awt is the average waiting time
//atat is the average turn around time

printf("enter the number of tasks\n");
scanf("%d", &n);

printf("enter the process time for each task\n");
for(i = 0; i < n; i++)
{
scanf("%d", &bt[i]);
}

wt[0] = 0;// first task should not wait

for(i = 1; i< n; i++)
{
    wt[i] = 0;
 for(j =0; j < i; j++)
 {
  wt[i] = wt[i] + bt[j]; // to calculate waiting time
 }
}


for(i = 0; i < n; i++)
{
tat[i] = bt[i] + wt[i]; // to calculate turn around time
}

for(i = 0; i < n ; i++)
{
awt += wt[i]; // to calculate average waiting time
atat += tat[i]; // to calculate average turn around time
}

awt = awt/n;
atat = atat/n;
printf("\n process time\tBurst time\tWaiting time\tTurnaround Time");

for(i = 0; i < n; i++)
{
// to print the tasks time

printf("\n%d\t\t%d\t\t%d\t\t%d\t\t",i+1, bt[i], wt[i], tat[i]);
}

printf("\nthe average waitng time and average turn around time are %d and  %d \t \n", awt, atat);


}
