#include <stdio.h>

int main()
{
   int n, i, j, t = 0, wt[10], at[10], ct[10], bt[10], pr[10], proc[10]= {0}, tat[10], total, temp;
    //bt is the burst time
   //ct is the completion time
   //at is the arrival time
   //wt is the waiting time
   //tat is the turn around time
   printf("enter the number of process\n");
   scanf("%d", &n);
   printf("enter the burst time, priority for each task\n");
   for(i = 0; i <n ;i++)
   {
       scanf("%d", &bt[i]);
       scanf("%d", &pr[i]);
       proc[i] = i+1;//stores the process index
       
   }
     printf("enter the arrival time for each task\n");
   for(i = 0; i <n ;i++)
   {  
       printf("proc[%d]:",i+1);
       scanf("%d", &at[i]);
   }
   
   printf("\nprocess\tburst time\tpriority\n");
   for(i =0; i< n;i++)
   {
       printf("proc[%d]\t \t%d\t \t%d\n", i+1, bt[i], pr[i]);
   }
   printf("\n");  
   //selection sort is used to select the process with less priority   
   for(i = 1; i < n ;i++)
   {
       int iMax = i;
       for(j =i+1; j<n ;j++)
       {
           if(pr[j] > pr[iMax])
           iMax = j;
       }
       
       temp = bt[iMax];
       bt[iMax] = bt[i];
       bt[i] = temp;
       
       temp = pr[iMax];
       pr[iMax] = pr[i];
       pr[i] = temp;
       
       temp = proc[iMax];
       proc[iMax] = proc[i];
       proc[i] = temp;
       
       
   }

     
  //displays the value after the sorting
     printf("\nprocess\tburst time\tpriority\n");
   for(i =0; i< n;i++)
   {
       printf("proc%d\t \t%d\t \t%d\n", proc[i], bt[i], pr[i]);
   }
   
   wt[0] = 0;
   
   for(i =0; i<n ; i++)
   {
       if(at[0] >= 1)
       {
        t =  t + at[0];//scheduler remains idle without incrementing the time
        
       }
      
       
       t = t + bt[i];// adds the time process for each task
       ct[i] = t;
       //t = t - at[0];//to balance the scheduler task
   }

   for(i =0; i<n ; i++)
   {
       tat[i] = ct[i] - at[i];//turn around time is difference between completion time and arrival time 
      
       
   }
    for(i =0; i<n ; i++)
   {
       wt[i] = tat[i] - bt[i];//waiting time is the difference between turn around time and burn time
       
   }
   int avtat = total/n;
   printf("\nprocess\tburst time\tcompletion time\twaiting time\tturnaround time\n");
   for(i = 0; i <n;i++)
   {
       printf("proc%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i], bt[i], ct[i], wt[i], tat[i] );
   }
   
    return 0;
    
}

