#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
};
int main()
{
		struct process p[10], temp;
    int ct[10],current_time,k,len ,waiting_sum=0, turnaround_sum=0, ready_queue[10]	, pos, j;
    printf("Enter the no. of processes : ");
    scanf("%d", &len);
    for(int i=0;i<len;i++)
    {
			p[i].pid=i+1;
			p[i].ct=0;
			printf("Enter the arrival and burst time of p%d : ", i+1);
			scanf("%d%d", &p[i].at, &p[i].bt);
    }
    for(int i=0;i<len;i++)
    {
    	for(int j=i+1;j<len;j++)
		{
			if(p[i].at > p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
    }
    current_time = p[0].at;
    for(int i=0;i<len;i++)
    {
    	j=i+1;
    	while(p[j].at<=current_time && j<len)
    		j++;
    	for(int k=i; k<j;k++)
    	{
    		for(int l=k+1; l<j;l++)
    		{
    			if(p[l].bt<p[k].bt)
    			{
    				temp=p[k];
					p[k]=p[l];
					p[l]=temp;
    			}
    		}
    	}
    	current_time = current_time + p[i].bt;
   		p[i].ct = current_time;
    }
    printf("\n");
    for(int i=0;i<len;i++)
    {
    	for(int j=i+1;j<len;j++)
			{
				if(p[i].pid > p[j].pid)
				{
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
    }
    for(int i=0;i<len;i++)
    {
        printf("p%d arrival time =%d, burst time=%d, completion time=%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct);
    }
		for(int i=0;i<len;i++)
    {
    	for(int j=i+1;j<len;j++)
			{
				if(p[i].ct > p[j].ct)
				{
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
    }
		printf("\nGantt Chart\n0");
		if(p[0].at != 0)
			printf("##%d", p[0].at);
		for(int i=0;i<len;i++)
    {
        printf(" p%d %d", p[i].pid, p[i].ct);
    }
		printf("\n");
}
