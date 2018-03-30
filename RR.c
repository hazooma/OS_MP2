#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 1024 

void wait(int wait){
                    int stop = wait;
                    int msec = 0;
                    clock_t before = clock();
                    do {
                        clock_t difference = clock() - before;
                        msec = difference * 1000 / CLOCKS_PER_SEC;
                    } while (msec <stop);
}



int main() 
{ 
    char buffer[BUFFER_SIZE];
    char *record, *line;
    int i = 0, j = 0;
    FILE *fstream = fopen("Input2.in", "r");
     FILE *f = fopen("RROUT.txt", "w");

    if (fstream == NULL)
    {
        fprintf(f,"\n file opening failed ");
        return -1;
    }
    int time_quantum = atoi(fgets(buffer, sizeof(buffer), fstream));
    int totalTickets = atoi(fgets(buffer, sizeof(buffer), fstream));
   // fprintf(f,"%d\n%d\n",quantum,totalTickets);

    int count,n,time,remain,flag=0; 
  int wait_time=0,turnaround_time=0,at[50],bt[50],rt[50]; 
 
  int idx = 0;
    while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
    {
        record = strtok(line, ",");
        int i;
        int pid;
        int arrivalTime;
        int burstTime;
        int tickets;
        for (i = 0; record != NULL; ++i)
        {
            if (i == 0)
                pid = atoi(record);
            if (i == 1)
                arrivalTime = atoi(record);
            if (i == 2)
                burstTime = atoi(record);
            if (i == 3)
                tickets = atoi(record);

            record = strtok(NULL, ",");
        }

    at[idx]=arrivalTime;
    bt[idx]=burstTime;
    rt[idx]=bt[idx];
    idx++;



    }
    n=idx;
    remain=n; 






 

  int prev = 0 ; 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      prev= time;
      wait(rt[count]);  
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    {
      fprintf(f,"Time %d : P %d Entering quantum\n", time,count+1);

      rt[count]-=time_quantum; 
      wait(time_quantum);
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
           fprintf(f,"Time %d : P %d Entering quantum\n", prev,count+1);

      fprintf(f,"Time %d : P %d Done Turn around : %d Waiting time : %d\n",time,count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  fprintf(f,"\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  fprintf(f,"Avg Turnaround Time = %f\n",turnaround_time*1.0/n); 
  
  return 0; 
}

