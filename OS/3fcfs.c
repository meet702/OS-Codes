#include <stdio.h>

int main(){
    int n;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++){
        pid[i] = i + 1;
    }
    printf("Enter arrival times: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &at[i]);
    }
    printf("Enter burst times: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }

    // Sorting according to arrival time
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(at[i] > at[j] || (at[i] == at[j] && pid[i] > pid[j])){
                int t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;

                t = at[i];
                at[i] = at[j];
                at[j] = t;

                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }
        }
    }

    int tatSum = 0, wtSum = 0, CT = 0; 

    for(int i = 0; i < n; i++){
        if(CT < at[i]){
            CT = at[i];    // idle condition
        }
        CT += bt[i];
        ct[i] = CT;
        tat[i] = ct[i] - at[i];
        tatSum += tat[i];
        wt[i] = tat[i] - bt[i];
        wtSum += wt[i];
    }

    float avgTat = (float)tatSum / n;
    float avgWt = (float)wtSum / n;

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAvg TAT = %.2f\nAvg WT = %.2f", avgTat, avgWt);
}