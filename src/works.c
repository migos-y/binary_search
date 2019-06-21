#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){//mは仕事量
  int a = 0;
  int count = 0;
  for(int i = 0;i < n;i++){
    if(A[i] > m) return 0;//最大値にならないとき A[i]>mの時明らかに最大値でない

    if(a + A[i] > m){
      a = A[i];
      count++;
    }else{
      a += A[i];
    }
    if(count >= k) return 0;//最大値にならないとき
  }
  return 1;//最大値になるとき
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  ub = 1000000000;
  lb = 0;
  while(ub - lb > 1){
    int m = (ub + lb) / 2;
    if(p(m)){
      ub = m;
    }else{
      lb = m;
    }
  }

  printf("%d\n", ub);
  return 0;
}
