#include <stdio.h>

int main(){
    int numPages, numFrames;
    printf("Enter reference string length and no. of frames: ");
    scanf("%d%d", &numPages, &numFrames);

    int pages[numPages], frames[numFrames];
    printf("Enter the reference string: ");
    for(int i = 0; i < numPages; i++){
        scanf("%d", &pages[i]);
    }

    for(int i = 0; i < numFrames; i++){
        frames[i] = -1;
    }

    int flag;
    int hit = 0, fault = 0, k = 0;
    for(int i = 0; i < numPages; i++){
        flag = 0;
        for(int j = 0; j < numFrames; j++){
            if(frames[j] == pages[i]){
                flag = 1;
                hit++;
                break;
            }
        }
        if(flag == 0){
            frames[k] = pages[i];
            k = (k + 1) % numFrames;
            fault++;
        }

        printf("Page %d: ", pages[i]);
        for(int j = 0; j < numFrames; j++){
            if(frames[j] == -1){
                printf("-- ");
            }
            else{
                printf("%d ", frames[j]);
            }
        }
        if(flag == 0) printf("   (Page Fault)\n");
        else printf("   (Page Hit)\n");
    }

    float hitRatio = (float)hit / numPages;
    float faultRatio = (float)fault / numPages;
    printf("Page faults: %d\nPage Hits: %d\n", fault, hit);
    printf("Hit Ratio: %.2f\nFault Ratio: %.2f", hitRatio, faultRatio);
}