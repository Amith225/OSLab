#include<stdio.h>

#define MAX 20
#define INF 1<<30

int minI(int* d, int n) {
  int min = d[0];
  int u = 0;
  for(int i = 1; i < n; i++) {
    if(min > d[i]) {
      min = d[i];
      u = i;
    }
  }
  return u;
}

void readData(int* at, int* bt, int* n) {
  printf("No Of Processes: "); scanf("%d", n);
  printf("Now Enter AT BT:\n");
  for(int i = 0; i < *n; i++) {
    printf("%d -> ", i); scanf("%d %d", &at[i], &bt[i]);
  }
}

void main() {
  int at[MAX], bt[MAX], n;
  readData(at, bt, &n);
  printf("PID\tAT\tBT\tWT\tTT\n");
  int t = 0, done = 0;
  while(done < n) {
    int i = minI(at, n);
    printf("P%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], t, t + bt[i]);
    t += bt[i];
    at[i] = INF;
    done++;
  }
}

