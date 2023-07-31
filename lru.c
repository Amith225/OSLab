#include<stdio.h>

#define MAX 25

void printFrame(int* f, int m, int s, int hit) {
  for(int i = 0; i < m; i++) {
    if(f[i] == -1) printf("_ ");
    else printf("%d ", f[i]);
  }
  for(int i = 0; i < m; i++) printf("  ");
  printf("%d\t\t%d\n", s, hit);
}

int maxI(int* d, int m) {
  int max = d[0];
  int u = 0;
  for(int i = 1; i < m; i++) {
    if(d[i] > max) {
      max = d[i];
      u = i;
    }
  }
  return u;
}

void main() {
  int n, m, rs[MAX], lru[MAX];
  printf("No of RS: "); scanf("%d", &n);
  printf("RS: "); for(int i = 0; i < n; i++) scanf("%d", &rs[i]);
  printf("No of Frames: "); scanf("%d", &m);
  
  int f[MAX];
  for(int i = 0; i < m; i++) {
    f[i] = -1;
    lru[i] = 0;
  }
  
  int hit, c = 0, u;
  printf("Frames");
  for(int i = 0; i < m; i++) printf("  ");
  printf("PageNo\tHit\n");
  for(int i = 0; i < n; i++) {
    hit = 0;
    for(int j = 0; j < m; j++) {
      if(f[j] == rs[i]) {
        hit = 1;
        u = j;
        break;
      }
    }
    
    for(int j = 0; j < m; j++) lru[j] += 1;
    if(hit == 0) {
      f[c] = rs[i];
      lru[c] = 0;
    } else lru[u] = 0;
    printFrame(f, m, rs[i], hit);
    c = maxI(lru, m);
  }
}
