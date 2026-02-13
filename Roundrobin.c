#include <stdio.h>
int main() {
    int n, tq, i, time = 0, remain;
    float avgWT=0, avgTAT=0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int AT[n], BT[n], RT[n], WT[n], TAT[n], CT[n];
    for(i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d%d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    remain = n;
    while(remain > 0) {
        int executed = 0;
        for(i = 0; i < n; i++) {
            if(RT[i] > 0 && AT[i] <= time) {
                executed = 1;
                if(RT[i] > tq) {
                    time += tq;
                    RT[i] -= tq;
                } else {
                    time += RT[i];
                    CT[i] = time;
                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];
                    RT[i] = 0;
                    remain--;
                }
            }
        }
        if(!executed) time++;
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
        avgWT += WT[i];
        avgTAT += TAT[i];
    }
    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaround Time = %.2f", avgTAT/n);
    return 0;
}
