#include <stdio.h>
#include <stdbool.h>

int main(){
    int m, n;
    printf("Enter no. of processes and resource types: ");
    scanf("%d%d", &n, &m);
    int allocation[n][m], max[n][m], need[n][m], available[m];
    printf("Enter allocation data: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter max data: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int work[m], count = 0, safeSeq[n];
    bool finish[n];
    printf("Enter available data: ");
    for(int i = 0; i < m; i++){
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    for(int i = 0; i < n; i++){
        finish[i] = false;
    }

    while(count < n){
        bool found = false;
        for(int i = 0; i < n; i++){
            if(!finish[i]){
                bool canAllocate = true;
                for(int j = 0; j < m; j++){
                    if(need[i][j] > work[j]){
                        canAllocate = false;
                        break;
                    }
                }
                if(canAllocate){
                    for(int j = 0; j < m; j++){
                        work[j] += allocation[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(!found){
            printf("No safe sequence generated. Hence no safe state\n");
        }
    }
    printf("Safe seq: ");
    for(int i = 0; i < n; i++){
        printf("P%d ", safeSeq[i]);
    }

    



}