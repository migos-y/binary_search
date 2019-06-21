#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){ //mは袋の容量
  int count = 0;
  for(int i = 0; i < n;i++){
    if(A[i] % m == 0){
      count += A[i] / m;
    }else{
      count += A[i] / m + 1;
    }

    if(count > k) return 0;
  }
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)){
      ub = m;
    }else{
      lb = m;
    }
  }
  printf("%d\n", ub);

  return 0;
}
