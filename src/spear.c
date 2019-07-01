#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int count = 0;
  for(int i = 0;i < n;i++){
    count += A[i] / x;
    if(count >= k) return 1; //作れるとき
  }
  return 0; //作れないとき
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int x = (ub + lb) / 2;
    if(p(x)){
      lb = x;
    }else{
      ub = x;
    }
  }

  printf("%d\n", lb);
  return 0;
}
