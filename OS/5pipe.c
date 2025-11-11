#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAX 20

// int main(){
//     char string[MAX], line[MAX], n;
//     pid_t pid;
//     printf("Enter string: ");
//     fgets(string, MAX, stdin);

//     int filedes[2];
//     if(pipe(filedes) == -1){
//         printf("Pipe creation failed");
//         exit(0);
//     }
//     if((pid=fork()) < 0){
//         printf("Child creation failed");
//         exit(0);
//     }
//     if(pid > 0){
//         close(filedes[0]);
//         write(filedes[1], string, MAX);
//         close(filedes[1]);
//     }
//     if(pid == 0){
//         close(filedes[1]);
//         n = read(filedes[0], line, MAX);
//         line[n] = '\0';
//         printf("Data read by child: %s", line);
//         close(filedes[0]);
//     }
    
// }



int main(){
    char string1[MAX], line1[MAX], string2[MAX], line2[MAX], n, m;
    pid_t pid;
    printf("Enter string for parent: ");
    fgets(string1, MAX, stdin);

    printf("Enter string for child: ");
    fgets(string2, MAX, stdin);

    int filedes1[2], filedes2[2];

    if(pipe(filedes1) == -1 || pipe(filedes2) == -1){
        printf("Pipe creation failed");
        exit(0);
    }
    if((pid=fork()) < 0){
        printf("Child creation failed");
        exit(0);
    }
    if(pid > 0){               // parent write-read
        close(filedes1[0]);
        write(filedes1[1], string1, MAX);
        close(filedes1[1]);

        close(filedes2[1]);
        m = read(filedes2[0], line2, MAX);
        line2[m] = '\0';
        printf("Data read by parent: %s\n", line2);
        close(filedes2[0]);

    }
    if(pid == 0){           // child read-write
        close(filedes1[1]);
        n = read(filedes1[0], line1, MAX);
        line1[n] = '\0';
        printf("Data read by child: %s\n", line1);
        close(filedes1[0]);

        close(filedes2[0]);
        write(filedes2[1], string2, MAX);
        close(filedes2[1]);
    }
    
}