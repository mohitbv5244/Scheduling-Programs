#include <stdio.h>

int main()
{
  int at[10], bt[10], rem_bt[10], i = 0, n, quantum,t=0, done = 0, p[10], ct[10];
  int wt[10], tat[10];
  printf("enter the number of process\n");
  scanf("%d", &n);
  printf("enter the burst time \n");
  for(i = 0; i <n ; i++)
  {
  scanf("%d", &bt[i]);
  
  }
  printf("enter the arrival time\n");
  for(i = 0; i <n ; i++)
  {
  scanf("%d", &at[i]);
      
  }
  
  printf("enter the quantum\n");
  scanf("%d", &quantum);
  
  for(i =0 ; i< n ; i++)
  {
      rem_bt[i] = bt[i];// copy of the 
  }
  
  while(1)
  {
      done = 1;//all the processes have been executed
      for(i = 0; i<n ; i++)
      {
	     if(rem_bt[i] > 0)
		 {
          done = 0;//all the processes have not been executed
          if(rem_bt[i] > quantum )
          {
              
			   t = t+ quantum;//add the time for each process with their quantum value
              rem_bt[i] = rem_bt[i] - quantum;// deduct the run-time quantum value from each process
          }
          else
          {
		  
		  t = t + rem_bt[i];//in the last cycle, add the left over value to the time
              
              rem_bt[i] = 0;//which means this task has finished its execution
			  ct[i] = t;//the updated t will give the value when the process has been completed
			  
          }
		  }
      }
       if(done == 1)
       {
            break;// condition for the while loop to break
       }
  
  }
  
 
  for(i = 0; i< n; i++)
      {
         tat[i] = ct[i] - at[i];// the turn around time is the difference in completion time and arrival time
	}
for(i = 0; i < n; i++)
{
         wt[i] = tat[i] - bt[i];// the waiting time is the difference in the turn around time and the burst time.
      }
      
  printf("\nprocess\tburst time\tarrival time\twaiting time\tturnaroundtime\tcompletion time\n");
  for(i = 0; i< n;i++)
  {
      printf("\np[%d]\t%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], at[i], wt[i], tat[i], ct[i]);
  }
  
    return 0;
}

