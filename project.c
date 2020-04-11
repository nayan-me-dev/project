#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main()
{	
	int burst_time[20],n,arrival_time[20],temp,temp1,i,j,completion_time[20],turnaround_time[20],waiting_time[20],time,sum=0;
	int sum1=0;
    float avg,avg1;
    printf("Enter total no of process:");
    scanf("%d",&n);
    printf("\n Enter arrival and  burst time for each process:-");
    for(i=0;i<n;i++)
    {   
    	printf("\n Enter arrival time of  P%d: ",i);
        scanf("%d",&arrival_time[i]);
        printf("\n Enter burst time of  P%d: ",i);
        scanf("%d",&burst_time[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        { 
            if(arrival_time[i]==0)   //if arrival time =0 code will show error and exits
            {
            	printf("arrival time is 0 ==> ERROR");
            	exit(0);
			}
            else 
            {
            	if(arrival_time[i]>arrival_time[j])   // arranging the according to SJF 
            	{
					temp=arrival_time[i];
               		temp1=burst_time[i];
               		arrival_time[i]=arrival_time[j];
               		arrival_time[j]=temp;
                	burst_time[i]=burst_time[j];
                	burst_time[j]=temp1;
            	}
            }
        }
    }
    time=burst_time[0];
    completion_time[0]=burst_time[0]+arrival_time[0];
    turnaround_time[0]=completion_time[0]-arrival_time[0];
    waiting_time[0]=turnaround_time[0]-burst_time[0];
    for( i=1;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        	{ 
            	if(arrival_time[i]<=time && burst_time[i]>burst_time[j])   // arranging the according to SJF 
            	{
					temp=arrival_time[i];
               		temp1=burst_time[i];
               		arrival_time[i]=arrival_time[j];
               		arrival_time[j]=temp;
                	burst_time[i]=burst_time[j];
                	burst_time[j]=temp1;
                	time=burst_time[j];
            	}
            	
            }
        }
        for(i=1;i<n;i++)
  			{	
        		completion_time[i]=burst_time[i]+completion_time[i-1]+2;// +2 because of the condition given in question
        		turnaround_time[i]=completion_time[i]-arrival_time[i];
        		waiting_time[i]=turnaround_time[i]-burst_time[i];
			}
		for(i=0;i<n;i++)
    		{
        		sum+=waiting_time[i];
        		sum1+=turnaround_time[i];
    		}
    
    avg=(float)sum/n;
    avg1=(float)sum1/n;
    printf("\n arrival_time  burst_time   completion_time  turnaround_time   waiting_time   ");
    for(i=0;i<n;i++)
    {  
        printf(" \n %d               %d                    %d                     %d                    %d",arrival_time[i],burst_time[i],completion_time[i],turnaround_time[i],waiting_time[i]);
    }
    printf("\n Average waiting time is %f sec.",avg);
    printf("\n avg turnaround time is %f sec ",avg1);
    getch();
    return 0;
}
