#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
  int rt;
};
void sort_arr(struct process p[], int a, int b)
{
    struct process temp;
    for(int i=a;i<b;i++)
    {
    	for(int j=i+1;j<b;j++)
  		{
  			if(p[i].at > p[j].at)
  			{
  				temp=p[i];
  				p[i]=p[j];
  				p[j]=temp;
  			}
            else if (p[i].at == p[j].at)
            {
                if(p[i].bt > p[j].bt)
      			{
      				temp=p[i];
      				p[i]=p[j];
      				p[j]=temp;
      			}
            }
  		}
    }
}
void sort_rem(struct process p[], int a, int b)
{
    struct process temp;
    for(int i=a;i<b;i++)
    {
    	for(int j=i+1;j<b;j++)
  		{
  			if(p[i].rt > p[j].rt)
  			{
  				temp=p[i];
  				p[i]=p[j];
  				p[j]=temp;
  			}
            else if (p[i].rt == p[j].rt)
            {
                if(p[i].at > p[j].at)
      			{
      				temp=p[i];
      				p[i]=p[j];
      				p[j]=temp;
      			}
            }
  		}
    }
}
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
      p[i].rt = p[i].bt;
    }
    // initial sorting
    sort_arr(p, 0, len);
    for(int i=0;i<len;i++)
        printf("p%d ", p[i].pid);
    printf("\nnow\n");
    current_time = p[0].at;
    // printf("%d ", current_time);
    for(int i=0;i<len;)
    {
        printf("current = %d", current_time);
        if (current_time <= p[len-1].at)
        {
            j=i+1;
            while(p[j].at<=current_time && j<len)
        		j++;
            current_time = current_time + p[j].at - p[i].at;
            p[i].rt = p[i].rt - (p[i+1].at - p[i].at);
            if(p[i].rt == 0)
            {
                p[i].ct = current_time;
                i++;
            }

            sort_rem(p, i, j);
        }
        else
        {
            current_time = current_time + p[i].rt;
            p[i].rt = 0;
            p[i].ct = current_time;
            i++;
            sort_rem(p, i, len);
        }
        for(int nw=0;nw<len;nw++)
        {
            if(nw == i)
                printf("c");
            printf("p%d %d ", p[nw].pid, p[nw].rt);
        }
        printf("\n");

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
