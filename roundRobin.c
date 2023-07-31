#include<stdio.h>

#define MAX 20

int minD(int* d, int n) {
  int min = d[0];
  for(int i = 1; i < n; i++) min = min < d[i] ? min : d[i];
  return min;
}

void readData(int* at, int* bt, int* temp, int* n, int* tq) {
  printf("No Of Processes: "); scanf("%d", n);
  printf("Now Enter AT BT:\n");
  for(int i = 0; i < *n; i++) {
    printf("%d -> ", i); scanf("%d %d", &at[i], &bt[i]);
    temp[i] = bt[i];
  }
  printf("Time Quantum: "); scanf("%d", tq);
}

void main() {
  int at[MAX], bt[MAX], temp[MAX], n, tq;
  readData(at, bt, temp, &n, &tq);
  printf("PID\tAT\tBT\tWT\tTT\n");
  int t = minD(at, n), done = 0;
  while(done < n) {
    for(int i = 0; i < n; i++) {
      if(temp[i] > 0 && t >= at[i]) {
        temp[i] -= tq;
        t += tq;
      }
      else continue;
      if(temp[i] <= 0) {
        int tt = t + temp[i] - at[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], tt - bt[i], tt);
        done++;
      }
    }
  }
}
