#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int n;
    float avg;
    printf("Enter total no of proces:");
    scanf("%d",&n);
    int burst_time[n],arrival_time[n],temp,temp1,i,j,completion_time[n],turnaround_time[n],waiting_time[n],process[n],sum=0;
    printf("\n Enter arrival and  burst time for each process:-");
    for(i=0;i<n;i++)
    {   
    	printf("\n arrival time and burst time process  P%d:",i);
        scanf("%d",&arrival_time[i]);
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
            	if(burst_time[i]>burst_time[j])   // arranging the according to SJF 
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
    completion_time[0]=burst_time[0];
    turnaround_time[0]=completion_time[0];
    waiting_time[0]=turnaround_time[0]-burst_time[0];
    for(i=1;i<n;i++)
    {
        completion_time[i]=burst_time[i]+completion_time[i-1]+2;// +2 because of the condition given in question
        turnaround_time[i]=completion_time[i]-arrival_time[i];
        waiting_time[i]=turnaround_time[i]-burst_time[i];
    }
    for(i=0;i<n;i++)
    {
        sum+=waiting_time[i];
    }
    avg=(float)sum/n;
    printf("\n Waiting time for each process:-");
    for(i=0;i<n;i++)
    {
        printf("\n Waiting time for process arrived at %d is %d sec.",arrival_time[i],waiting_time[i]);
        printf("%d %d  %d %d %d",arrival_time[i],burst_time[i],completion_time[i],turnaround_time[i],waiting_time[i]);
    }
    printf("\n Average waiting time is %f sec.",avg);
    getch();
    return 0;
}
