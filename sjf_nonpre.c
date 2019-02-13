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
    int ct[10],current_time,min,k,b_t,len ,sum=0,ready_queue[10], rqlen,completed, sum_waiting, pos, j;
    printf("Enter the no. of processe : ");
    scanf("%d", &len);
    for(int i=0;i<len;i++)
    {
    	p[i].pid=i+1;
    	p[i].ct=0;
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
    rqlen = 0;
    completed=0;
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
        printf(" pid=%d at=%d bt=%d ct=%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct);
    }
    
}
