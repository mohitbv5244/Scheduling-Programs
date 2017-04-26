#include <stdio.h>

int main()
{
    int allocation[10][10], safe = 0, exec = 0, maxallocation[10][10];
    int running[10], counter = 0, need[10][10], process, resources, i,j,n, claim_vector[5];
    int allocation_vector[5]= {0,0,0,0,0}, available_vector[5]={0,0,0,0,0};
    printf("enter the number of process\n");
    scanf("%d", &process);//total number of process
    
    printf("enter the number of resurces\n");
    scanf("%d", &resources);//total number of resources
    
    printf("enter the max claim vector");
    for(i = 0; i < resources; i++)
    {
        scanf("%d", &claim_vector[i]);
    }
    
    printf("the claim vector is\n");
     for(i = 0; i < resources; i++)
    {
        printf("%d\t", claim_vector[i]);//prints the maximum claim vector 
    }
    printf("\n");
    
    printf("enter the maximum alocation vector");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            scanf("%d", &maxallocation[i][j]);
        }
    }
    
      printf("enter the alocation vector");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    
     for(i = 0; i < process; i++)
    {
        running[i] = 1;//keeps the track of the process running
        counter++;// keeps the track of number of repeats
    }
    
    printf("the max allocation matrix is\n");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            printf("%d\t", maxallocation[i][j]);//prints the maximum allocation matrix
        }
        printf("\n");
    }
    
    printf("the allocation matrix is\n");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            printf("%d\t", allocation[i][j]);//prints the allocation matrix
        }
        printf("\n");
    }
    
    
    printf("the need matrix is\n");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            need[i][j] = maxallocation[i][j] - allocation[i][j];//calculates the need matrix
        }
    }
    
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            printf("%d\t", need[i][j]);//prints the need matrix
        }
        printf("\n");
    }
    
    printf("the allocation vector is\n");
    for(i = 0; i < process; i++)
    {
        for(j = 0; j < resources; j++)
        {
            allocation_vector[j] = allocation_vector[j] + allocation[i][j];//calculates the allocation vector
        }
    }
    
    for(i = 0; i < resources; i++)
    {
    printf("%d\t", allocation_vector[i]);//prints the allocation vector
    }
    printf("\n");
    
    printf("the available vector before calculation is\n");
    for(i = 0 ; i < resources; i++)
    {
        available_vector[i] = claim_vector[i] - allocation_vector[i];//calculates the available vector
    }
    
    for(i = 0; i < resources; i++)
    {
        printf("%d\t", available_vector[i]);//prints the available vector
    }
    printf("\n");
    
    
    while(counter!= 0)
    {
        safe = 0;
      
        for(i = 0; i< process; i++)
        {
         if(running[i])
         {
           exec = 1; //process are running     
           for(j =0; j < resources; j++)
           {
               if(need[i][j] > available_vector[j])
               {
                   exec = 0;
                   break;//if true execution comes out of the loop
               }
           }
           if(exec)
           {
               printf("the processes are executing\n");
               for(j = 0; j < resources; j++)
               {
                   available_vector[j] = available_vector[j] + allocation[i][j];//calculates the available vector from the available matrix(updating the vector)
               }
               counter--;//devrement the counter
               safe = 1;//raise the safe as 1
               running[i] = 0;//this variable makes execution to halt
               break;
           }
            
         }
        }
    
         if(!safe)
         {
             printf("the process is not in safe state\n");
             break;
         }
         else
         {
             printf("the process is in safe state\n");
             printf("th available vector after the calculation is \n");
             for(i = 0; i < resources;i++)
             {
                 printf("%d\t", available_vector[i]);//prints the final value of the available vector
             }
             printf("\n");
         }
        
    } 
    
    return 0;
}

  
  
  
  
  
  
  
