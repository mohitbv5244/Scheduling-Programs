#include <stdio.h>

int main()
{
   int n, i, j, wt[10], bt[10], proc[10]= {0}, tat[10], total, temp;
   printf("enter the number of process\n");
   scanf("%d", &n);
   printf("enter the burst time for each task\n");
   for(i = 0; i <n ;i++)
   {
       scanf("%d", &bt[i]);
   }
   
   printf("\nprocess\tburst time\n");
   for(i =0; i< n;i++)
   {
       printf("proc[%d]\t  \t%d\n", i+1, bt[i]);
   }
   printf("\n");   
   for(i = 0; i < n ;i++)
   {
       int iMax = i;
       for(j =i+1; j<n ;j++)
       {
           if(bt[j] < bt[iMax])
           iMax = j;
       }
       
       temp = bt[iMax];
       bt[iMax] = bt[i];
       bt[i] = temp;
       
       temp = proc[iMax];
       proc[iMax] = proc[i];
       proc[i] = temp;
       
       
   }

     printf("\nafter\n");
     printf("\nprocess\tburst time\n");
   for(i =0; i< n;i++)
   {
       printf("proc[%d]\t \t%d\n", i+1, bt[i]);
   }
   
   wt[0] = 0;
   
   for(i = 1; i< n ;i++)
   {
       wt[i] = 0;
       for(j = 0; j< i; j++)
       {
           wt[i] = wt[i] + bt[j];
           
       }
       
   }
   
   
   total = 0;
   for(i =0; i<n ; i++)
   {
       tat[i] =  wt[i] + bt[i];
               
   }
   int avtat = total/n;
   printf("\nprocess\tburst time\twaiting time\tturnaround time\n");
   for(i = 0; i <n;i++)
   {
       printf("proc[%d]\t\t%d\t\t%d\t\t\t%d\n", i+1, bt[i], wt[i], tat[i] );
   }
   
    return 0;
    
}

