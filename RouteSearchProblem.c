#include <stdio.h>
#include <string.h>

/* 問題 */
static int question[1000][1000];

int create_map(void);

int main(void){
  int grid_size = create_map();
  
  /* 作業用配列 */
  int work[grid_size][grid_size];

  /* 経路 (4×4の場合、7(=4*2-1)箇所のマスを通る）*/
  int route_x[grid_size * 2 - 1];  /* X座標 */
  int route_y[grid_size * 2 - 1];  /* Y座標 */

  /* インデクス */
  int x, y, i;

  /* 作業用配列の作成 */
  /* 左上角 */
  work[0][0] = question[0][0];
  /* 上端のマス */
  for (x = 1; x < grid_size; x++) {
    work[0][x] = work[0][x - 1] + question[0][x];
  }
  /* 左端のマス */
  for (y = 1; y < grid_size; y++) {
    work[y][0] = work[y - 1][0] + question[y][0];
  }
  for (x = 1; x < grid_size; x++) {
    for (y = 1; y < grid_size; y++) {
      if (work[y][x - 1] < work[y - 1][x]) {
        /* 左のマスの値が上のマスの値より大きい */
        work[y][x] = work[y][x - 1] + question[y][x];
      } else {
        /* 上のマスの値が左のマスの値以上 */
        work[y][x] = work[y - 1][x] + question[y][x];
      }
    }
  }

  /* 終点から経路検索開始  経路の配列は最終要素から詰める */
  for (i = grid_size * 2 - 2, x = grid_size - 1, y = grid_size - 1; ; i--) {
    /* 経路を記録 */
    route_x[i] = x;
    route_y[i] = y;
    if (x == 0 && y == 0) {
      /* 始点に到達 */
      break;
    }
    if (y == 0) {
      /* 上端まで到達している ⇒ 左方向にしか戻れない */
      x--;
    } else if (x == 0) {
      /* 左端まで到達している ⇒ 上方向にしか戻れない */
      y--;
    } else if (work[y][x - 1] > work[y - 1][x]) {
      /* 上より左の方が大きい ⇒ 左へ戻る */
      x--;
    } else {
      /* 左より上の方が大きい ⇒ 上へ戻る */
      y--;
    }
  }
    
  /* 結果出力 */
  printf("%d\n", work[grid_size - 1][grid_size - 1]);
}

int create_map(){
  int count1, count2, len;
  char input_string[1000];
    
  len = 1000;
    
  for(count1 = 0; count1 < len; count1++){
    scanf("%s", input_string);
    len = strlen(input_string);
    for(count2 = 0; count2 < len; count2++){
      question[count1][count2] = input_string[count2] - '0';
    }
  }
  return len;
}
