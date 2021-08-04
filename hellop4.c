#include <stdio.h>
#define NTURBOPFOR_DAC
#include "vp4.h"
#include "bitutil.h"

#define ROUND_UP(_n_, _a_) (((_n_) + ((_a_)-1)) & ~((_a_)-1))
#define P4NENC_BOUND(n, size) ((n + 127) / 128 + (n + 32) * (size))
#define P4NDEC_BOUND(n, size) (ROUND_UP(n, 32) * (size))


int main(int argc, char* argv[]) {
      printf("Hello TurboPFor\n");
      unsigned elnum = 1000000;
      //int ar[ROUND_UP(elnum,64)];
      uint64_t ar[ROUND_UP(elnum,32)];
      //uint64_t ar[elnum+64];
      for(int i=0;i<elnum;i++) ar[i]=i;
      //uint64_t b=bit64(ar,elnum);
      //unsigned char* compress_buf = (unsigned char *)malloc( ((b+7)/8)*(ROUND_UP(elnum,32))+1);
      unsigned char* compress_buf =  malloc(P4NENC_BOUND(elnum,64));
      //uint64_t *uncompress_buf =  malloc(P4NDEC_BOUND(elnum,64));
  
      size_t compress_size = p4nenc64((uint32_t*)ar, elnum, compress_buf);
      printf("compress size is %lu\n", compress_size);
  
      //size_t uncompress_size = p4ndec64(compress_buf, elnum, (uint64_t*)uncompress_buf);
      //printf("uncompress size is %lu\n", uncompress_size);
}

/*
int main(int argc, char* argv[]) {
      printf("Hello TurboPFor\n");
      unsigned elnum = 10000000;
      //int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      int ar[ROUND_UP(elnum,32)];
      for(int i=0;i<elnum;i++) ar[i]=i;
      
      unsigned char* compress_buf =  malloc(P4NENC_BOUND(elnum,32));
      int *uncompress_buf =  malloc((elnum+32)*sizeof(ar[0]));
  
      size_t compress_size = p4nenc32((uint32_t*)ar, elnum, compress_buf);
      printf("compress size is %lu\n", compress_size);
  
      size_t uncompress_size = p4ndec32(compress_buf, elnum, (uint32_t*)uncompress_buf);
      printf("uncompress size is %lu\n", uncompress_size);
}
*/