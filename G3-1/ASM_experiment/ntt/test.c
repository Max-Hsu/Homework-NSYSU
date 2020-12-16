#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "bitreverse.h"
#include "ntt.h"
#include "baileys.h"
#include "swap.h"
#include "twiddle.h"


void assert_ordered(uint64_t* arr, int size) {
  for(int i=0;i<size;i++) {
    if(i != arr[i]) {
      goto fail;
    }
  }
  return;
  fail:
  fprintf(stderr, "error: unexpected ordering\n");
}

int main(void) {
  ensure_twiddle(64);

/*
  for(int i = 0 ; i<10;i++){
    for(int j = 0 ; j <1024 ; j++){
      printf("%ld ",twiddles[i][j]);
    }
	printf("\n");
  }
*/
  // Multiplication tests
  {

    #define LEN 8
    uint64_t a[LEN] = {23, 42,0,1,65526};
    uint64_t b[LEN] = {10, 11};
    ntt_forward(a, LEN);
    ntt_forward(b, LEN);
    ntt_pointwise(a, b, LEN);
    ntt_inverse(a, LEN);
    for(size_t i=0;i<8;i++) {
      printf("%ld ",a[i]);
    }
  }
  printf("\n");
}
