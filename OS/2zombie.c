#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// zombie

// int main(){
//     pid_t pid;
//     if((pid = fork()) < 0){
//         printf("Fork error\n");
//     }
//     else if(pid == 0){
//          printf("Child process id is %d\n", getpid());        
//     }
//     else{
//         sleep(10);
//         printf("-------------Parent-------------\n");
//         system("ps -axj | tail");
//     }
//     return 0;
// }

// orphan

// int main(){
//     pid_t pid = fork();
//     if(pid > 0){
//         printf("Parent process id: %d\n", getpid());
//         printf("Child process id: %d\n", pid);
//     }
//     else if(pid == 0){
//         sleep(10);
//         printf("Child process id: %d\n", getpid());
//         printf("Parent process id: %d\n", getppid());
//     }
// }

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter array element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    if(pid > 0){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[i] > arr[j]){
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = arr[i];
                }
            }
        }
        printf("Sorted array in asc order\n");
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if(pid == 0){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[i] < arr[j]){
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = arr[i];
                }
            }
        }
        printf("Sorted array in desc order\n");
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}