#include<stdio.h>
#include<stdlib.h>

void main()
{

int i, j, n, bt[10], at[10], rem_bt[10], ct[10], wt[10], tat[10],  t = 0;
float  awt = 0, atat = 0;
//n is number of tasks
//bt is the process time for each task
//wt is the waiting tie for each task
//ct is the completion time for each task
//t is the run-time for each task
//tat is the turn around time for each task
//awt is the average waiting time
//atat is the average turn around time

printf("enter the number of tasks\n");
scanf("%d", &n);

printf("enter the process time for each task\n");
for(i = 0; i < n; i++)
{
scanf("%d", &bt[i]);
rem_bt[i] = bt[i];
}

printf("enter the arrival time for each task\n");
for(i = 0; i < n; i++)
{
scanf("%d", &at[i]);
}
wt[0] = 0;// first task should not wait




for(i = 0; i < n; i++)
{
 t = t+ bt[i];//computes time t for eac task(run-time)
 ct[i] = t;//t is the actual value for the completion time
}






for(i = 0; i < n; i++)
{
tat[i] = ct[i] - at[i]; // to calculate turn around time
}
for(i = 0; i < n; i++)
{
 wt[i] = tat[i] - bt[i];// to calculate waiting time
}


for(i = 0; i < n ; i++)
{
awt += wt[i]; // to calculate average waiting time
atat += tat[i]; // to calculate average turn around time
}

awt = awt/n;
atat = atat/n;
printf("\nprocess time\tBurst time\tarrival time\t completion time\tWaiting time\tTurnaround Time");
for(i = 0; i< n ;i++)
{
printf("p[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i+1, bt[i], at[i], ct[i], wt[i], tat[i]);
}

printf("\nthe average waitng time and average turn around time are %f and  %f \t \n", awt, atat);


}
