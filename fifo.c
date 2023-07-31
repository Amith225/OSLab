#include<stdio.h>

#define MAX 10

void printFrame(int* f, int m, int s, int hit) {
  for(int i = 0; i < m; i++) {
    if(f[i] == -1) printf("_ ");
    else printf("%d ", f[i]);
  }
  printf("\t%d\t%d\n", s, hit);
}

void main() {
  int n, m, rs[MAX];
  printf("No of RS: "); scanf("%d", &n);
  printf("RS: "); for(int i = 0; i < n; i++) scanf("%d", &rs[i]);
  printf("No of Frames: "); scanf("%d", &m);
  
  int f[MAX];
  for(int i = 0; i < n; i++) f[i] = -1;
  
  int hit, c = 0;
  printf("Frames");
  for(int i = 0; i < m; i++) printf("  ");
  printf("PageNo\tHit\n");
  for(int i = 0; i < n; i++) {
    hit = 0;
    for(int j = 0; j < m; j++) {
      if(f[j] == rs[i]) {
        hit = 1;
        break;
      }
    }
    
    if(hit == 0) f[c++] = rs[i];
    printFrame(f, m, rs[i], hit);
    c %= m;
  }
}
