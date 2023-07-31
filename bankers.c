#include<stdio.h>
#include<stdlib.h>

int** findNeed(int** alloc, int** max, int n, int m) {
  int** need = malloc(sizeof(int*) * n);
  for(int i = 0; i < n; i++) {
    need[i] = malloc(sizeof(int) * m);
    for(int j = 0; j < m; j++) need[i][j] = max[i][j] - alloc[i][j];
  }
  return need;
}

int** read2D(int n, int m) {
  int** arr = malloc(sizeof(int*) * n);
  printf("Matrix[%d, %d]:\n", n, m);
  for(int i = 0; i < n; i++) {
    arr[i] = malloc(sizeof(int) * m);
    printf("%d[%d] -> ", i, m);
    for(int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
  }
  return arr;
}

int anyLow(int* avail, int* needed, int m) {
  for(int i = 0; i < m; i++) {
    if(needed[i] > avail[i]) return 1;
  }
}

void add(int* addTo, int* other, int m) {
  for(int i = 0; i < m; i++) {
    addTo[i] += other[i];
  }
}

void main() {
  int n = 5;
  int m = 3;
  
  printf("Allocation "); int** alloc = read2D(n, m);
  printf("Maximum "); int** max = read2D(n, m);
  int* avail = malloc(sizeof(int) * m);
  printf("Available[%d]: ", m);
  for(int i = 0; i < m; i++) scanf("%d", &avail[i]);
  int** need = findNeed(alloc, max, n, m);
  
  short* done = calloc(n, sizeof(short));
  int notFlag;
  printf("Safe Sequence: ");
  while(1) {
    notFlag = 1;
    for(int i = 0; i < n; i++) {
      if(done[i] == 1 || anyLow(avail, need[i], m) == 1) continue;
      printf(" -> P%d", i);
      add(avail, alloc[i], m);
      done[i] = 1;
      notFlag = 0;
    }
    if(notFlag == 1) break;
  }
  printf("\n");
}
