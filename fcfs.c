#include <stdio.h>
int main() {
    int n, i, t = 0;
    float avgWT = 0, avgTAT = 0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int AT[n], BT[n], CT[n], TAT[n], WT[n];
    for(i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d%d", &AT[i], &BT[i]);
    }
    for(i = 0; i < n; i++) {
        if(t < AT[i]) t = AT[i];
        CT[i] = t + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        avgWT += WT[i];
        avgTAT += TAT[i];
        t = CT[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    printf("Average Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);
}
