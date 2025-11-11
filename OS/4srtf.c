#include <stdio.h>

int main(){
    int n;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int id[n], at[n], bt[n], ct[n], rt[n], tat[n], wt[n];
    int completedCount = 0;
    printf("Enter arrival times: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &at[i]);
        id[i] = i + 1;
    }
    printf("Enter burst times: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    int time = 0, wtSum = 0, tatSum = 0;
    while(completedCount < n){
        int idx = -1;
        int minRT = 9999;
        for(int i = 0; i < n; i++){
            if(at[i] <= time && rt[i] > 0){
                if(rt[i] < minRT || (rt[i] == minRT && at[i] < at[idx])){
                    minRT = rt[i];
                    idx = i;
                }
            }
        }
        if(idx == -1){
            time++;
            continue;
        }
        rt[idx]--;
        time++;
        if(rt[idx] == 0){
            completedCount++;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            tatSum += tat[idx];
            wtSum += wt[idx];
        }

    }

    float avgTat = (float)tatSum / n;
    float avgWt = (float)wtSum / n;

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAvg TAT = %.2f\nAvg WT = %.2f", avgTat, avgWt);
}



