#include<stdio.h>
int main()
{
    int p[10], bt[10], len ,sum=0, sum_waiting, pos, temp;
    printf("Enter the no. of task : ");
    scanf("%d", &len);
    printf("Enter the burst time : ");
    for(int i=0;i<len;i++)
    {
        p[i] = i;
        scanf("%d", &bt[i]);
    }
    for(int i=0;i<len;i++)
    {
        pos=i;
        for(int j=i+1;j<len;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    printf("\n%d", sum);
    for(int i=0;i < len; i++)
    {
        sum += bt[i];
        printf("  P%d  %d", p[i]+1, sum);
        if(i!=len-1)
            sum_waiting += sum;
    }
    printf("\nAverage waiting time : %f", ((float)sum_waiting/len));
}
