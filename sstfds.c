//Shortest seek time first disk scheduling 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int n, head, i, j;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int req[n], visited[n];
    printf("Enter the request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);
    int current = head;
    int total_seek = 0;
    FILE *data = fopen("sstf.dat", "w");
    if (data == NULL) {
        printf("Error creating data file!\n");
        return 1;
    }
    fprintf(data, "0 %d\n", current);
    printf("\nSeek Sequence: %d", current);
    for(i = 0; i < n; i++) {
        int min = 100000, index = -1;
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(current - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        total_seek += min;
        current = req[index];
        printf(" -> %d", current);
        fprintf(data, "%d %d\n", i+1, current);
    }
    fclose(data);
    printf("\nTotal Seek Time = %d\n", total_seek);
    FILE *gp = fopen("plot.gp", "w");
    if (gp == NULL) {
        printf("Error creating plot file!\n");
   return 1;
    }
    fprintf(gp, "set terminal wxt\n");
    fprintf(gp, "set title 'SSTF Disk Scheduling'\n");
    fprintf(gp, "set xlabel 'Step Number'\n");
    fprintf(gp, "set ylabel 'Track Number'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "plot 'sstf.dat' using 1:2 with linespoints lw 2 pt 7\n");
    fprintf(gp, "pause -1\n");
    fclose(gp);
    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot.gp");
    return 0;
}
