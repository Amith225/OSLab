#include<stdio.h>

#define MAX 20
#define INF 1<<30

int minII(int* d1, int* d2, int n) {
  int min = d1[0];
  int u = 0;
  for(int i = 1; i < n; i++) {
    if(min > d1[i]) {
      min = d1[i];
      u = i;
    } else if(min == d1[i] && d2[u] > d2[i]) {
      min = d1[i];
      u = i;
    }
  }
  return u;
}

void readData(int* at, int* bt, int* pt, int* n) {
  printf("No Of Processes: "); scanf("%d", n);
  printf("Now Enter AT BT PT:\n");
  for(int i = 0; i < *n; i++) {
    printf("%d -> ", i); scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
  }
}

void main() {
  int at[MAX], bt[MAX], pt[MAX], n;
  readData(at, bt, pt, &n);
  printf("PID\tAT\tBT\tWT\tTT\n");
  int i = minII(at, pt, n);
  int t = at[i], done = 0;
  while(done < n) {
    int wt = t - at[i];
    printf("P%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], wt, wt + bt[i]);
    t = bt[i] + at[i] + wt;
    at[i] = INF;
    bt[i] = INF;
    done++;
    i = minII(at, pt, n);
  }
}

