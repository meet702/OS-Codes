// #include <stdio.h>
// #include <semaphore.h>
// #include <pthread.h>

// sem_t wrt, mutex;
//     pthread_t readers[5], writers[5];
//     int readerCount = 0, sharedVar = 99;
    
//     void reader(){
//         sem_wait(&mutex);
//         readerCount++;
//         if(readerCount == 1)
//             sem_wait(&wrt);
//         sem_post(&mutex);
        
//         printf("Reader is in CS\n");
//         printf("%d reader is reading the value of shared variable = %d\n", readerCount, sharedVar);
        
//         sem_wait(&mutex);
//         readerCount--;
//         if(readerCount == 0)
//             sem_post(&wrt);
//         sem_post(&mutex);
//     }
    
//     void writer(){
//         printf("Writer is trying to enter CS\n");
//         sem_wait(&wrt);
//         printf("Writer has entered CS\n");
//         sharedVar++;
//         printf("Writer has updated the value of sharedVar = %d\n", sharedVar);
//         sem_post(&wrt);
//         printf("Writer is out of CS\n");
//     }
    
//     int main(){
//         int n;
//         printf("Enter the number of readers and writers: ");
//         scanf("%d", &n);
        
//         sem_init(&mutex, 0, 1);
//         sem_init(&wrt, 0, 1);
        
//         for(int i = 0; i < n ; i++){
//             pthread_create(&readers[i], NULL, (void*)reader, NULL);
//             pthread_create(&writers[i], NULL, (void*)writer, NULL);
//         }
//         for(int i = 0; i < n; i++){
//             pthread_join(readers[i], NULL);
//             pthread_join(writers[i], NULL);
//         }
//     }

