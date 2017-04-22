#include <stdio.h>

int main()
{
    int quantum, t , i, at[10], bt[10], n, rem_bt[10], tat[10], wt[10], flag = 1;
    printf("enter the number of process\n");
    scanf("%d", &n);
    printf("enter the quantum\n");
    scanf("%d", &quantum);
    printf("enter the burst time for each task\n");
    for(i = 0; i< n; i++)
    {
        scanf("%d", &bt[i]);
    }
     printf("enter the arrival time for each task\n");
    for(i = 0; i< n; i++)
    {
        scanf("%d", &at[i]);
    }
    for(i = 0; i< n; i++)
    {
        rem_bt[i] = bt[i];
    }
    
    while(1)
    {
     flag = 1;
     for(i = 0; i <n ; i++)
     {
       if(rem_bt[i] > 0)
       {
          flag = 0;
            if(rem_bt[i] > quantum)
            {
                t = t + quantum;
                rem_bt[i] = rem_bt[i] - quantum;
            }
            else
            {
                t = t + rem_bt[i];
                wt[i] = t - at[i]- bt[i];
                rem_bt[i] = 0;
            }
         }
       }
       if(flag == 1)
    {
        break;
    }
    }
    
    for(i = 0; i < n; i++)
    {
        tat[i] =  wt[i] + bt[i];//waiting time + burst time for each task
    }

printf("\nprocess\tarrival time\tburst time\twaiting time\tturnaround time\n");
for(i  =0; i < n;i++)
{
    printf("p[%d]\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1, at[i], bt[i], wt[i], tat[i] );
}

    return 0;
}

