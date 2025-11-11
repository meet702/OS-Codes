#include <stdio.h>

int main(){
    int numPages, numFrames;
    printf("Enter ref string length and no. of frames: ");
    scanf("%d%d", &numPages, &numFrames);

    int pages[numPages], frames[numFrames], temp[numFrames];
    int counter = 0, flag1, flag2, hit = 0, fault = 0, least, pos;

    printf("Enter ref string: ");
    for(int i = 0; i < numPages; i++){
        scanf("%d", &pages[i]);
    }

    for(int i = 0; i < numFrames; i++){
        frames[i] = -1;
    }

    for(int i = 0; i < numPages; i++){
        flag1 = flag2 = 0;
        for(int j = 0; j < numFrames; j++){
            if(pages[i] == frames[j]){ // page hit
                flag1 = flag2 = 1;
                counter++;
                temp[j] = counter;
                hit++;
                break;
            }
        }
        if(flag1 == 0){    // page fault in empty frame
            for(int j = 0; j < numFrames; j++){
                if(frames[j] == -1){
                    frames[j] = pages[i];
                    flag2 = 1;
                    counter++;
                    temp[j] = counter;
                    fault++;
                    break;
                }
            }
        }
        if(flag2 == 0){     // page fault - lru replacement
            least = temp[0];
            pos = 0;
            for(int j = 1; j < numFrames; j++){
                if(temp[j] < least){
                    least = temp[j];
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            counter++;
            temp[pos] = counter;
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
        if(flag1 == 0) printf("   (Page Fault)\n");
        else printf("   (Page Hit)\n");
    }

    float hitRatio = (float)hit / numPages;
    float faultRatio = (float)fault / numPages;
    printf("Page faults: %d\nPage Hits: %d\n", fault, hit);
    printf("Hit Ratio: %.2f\nFault Ratio: %.2f", hitRatio, faultRatio);

}