#include<stdio.h>
int main()
{
    int at[10], bt[10], len ,sum=0, sum_waiting;
    printf("Enter the no. of task : ");
    scanf("%d", &len);
    printf("Enter the burst time : ");
    for(int i=0;i<len;i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("\n%d", sum);
    for(int i=0;i < len; i++)
    {
        sum += bt[i];
        printf("  P%d  %d", i+1, sum);
        if(i!=len-1)
            sum_waiting += sum;
    }
    printf("\nAverage waiting time : %f", ((float)sum_waiting/len));
}
