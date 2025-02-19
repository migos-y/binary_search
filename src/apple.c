#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){ //mは袋の容量
  int count = 0;
  for(int i = 0; i < n;i++){
      count += (A[i] + m - 1) / m;
    

    if(count > k) return 0;//袋の大きさが足りないとき
  }
  return 1;//袋の大きさが足りているとき
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
