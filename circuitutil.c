#include <stdio.h>
#define NTURBOPFOR_DAC
#include "vp4.h"
#include "bitpack.h"
#include "vint.h"

//#define PRINT

#define ROUND_UP(_n_, _a_) (((_n_) + ((_a_)-1)) & ~((_a_)-1))
#define P4NENC_BOUND(n, size) ((n + 127) / 128 + (n + 32) * (size))
#define P4NDEC_BOUND(n, size) (ROUND_UP(n, 32) * (size))

#define P4 1
#define BP 2
#define VB 3
unsigned char* encHlp64(uint64_t* arr, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
  #endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    unsigned char* compress_buf =  malloc(P4NENC_BOUND(len,64));
    //uint64_t *uncompress_buf =  malloc(ROUND_UP(len,64));

    switch(type){
      case P4: *out_len = p4nenc64(arr, len, compress_buf);
      case BP: *out_len = bitnpack64(arr, len, compress_buf);
      /*
      case VB: {
        unsigned char* out = vbenc64(arr, len, compress_buf);
        *out_len = out-compress_buf;
      }
      */
      default: break;
    }
#ifdef PRINT
    printf("compress size is %u\n", *out_len);
#endif
    //size_t uncompress_size = p4ndec64(compress_buf, len, uncompress_buf);
    //printf("uncompress size is %lu\n", uncompress_size);
      return compress_buf;
}

unsigned char* encHlp32(uint32_t* arr, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
#endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    unsigned char* compress_buf =  malloc(P4NENC_BOUND(len,32));
    //uint64_t *uncompress_buf =  malloc(ROUND_UP(len,64));
  
    switch(type){
      case P4: *out_len = p4nenc32(arr, len, compress_buf);
      case BP: *out_len = bitnpack32(arr, len, compress_buf);
      /*
      case VB: {
        unsigned char* out = vbenc32(arr, len, compress_buf);
        *out_len = out-compress_buf;
      }
      */
      default: break;
    }
#ifdef PRINT
    printf("compress size is %u\n", *out_len);
#endif
    //size_t uncompress_size = p4ndec64(compress_buf, len, uncompress_buf);
    //printf("uncompress size is %lu\n", uncompress_size);
      return compress_buf;
}

unsigned char* encHlp8(uint8_t* arr, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
#endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    unsigned char* compress_buf =  malloc(P4NENC_BOUND(len,8));
    //uint64_t *uncompress_buf =  malloc(ROUND_UP(len,64));
  
    switch(type){
      case P4: *out_len = p4nenc8(arr, len, compress_buf);
      case BP: *out_len = bitnpack8(arr, len, compress_buf);
      default: break;
    }
#ifdef PRINT
    printf("compress size is %u\n", *out_len);
#endif
    //size_t uncompress_size = p4ndec64(compress_buf, len, uncompress_buf);
    //printf("uncompress size is %lu\n", uncompress_size);
      return compress_buf;
}

uint64_t* decHlp64(unsigned char* compress_buf, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
#endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    //unsigned char* compress_buf =  malloc(P4NENC_BOUND(len));
    uint64_t *uncompress_buf =  malloc(P4NDEC_BOUND(len,64));
  
    //size_t compress_size = p4nenc64(inDetails, len, compress_buf);
    //printf("compress size is %lu\n", compress_size);
  
    switch(type){
      case P4: *out_len = p4ndec64(compress_buf, len, uncompress_buf);
      case BP: *out_len = bitnunpack64(compress_buf, len, uncompress_buf);
      /*
      case VB: {
        unsigned char* out = vbdec64(compress_buf, len, uncompress_buf);
        *out_len = out-compress_buf;
      }
      */

      default: break;
    }
#ifdef PRINT
    printf("uncompress size is %u\n", *out_len);
#endif
    return uncompress_buf;
}

uint32_t* decHlp32(unsigned char* compress_buf, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
#endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    //unsigned char* compress_buf =  malloc(P4NENC_BOUND(len));
    uint32_t *uncompress_buf =  malloc(P4NDEC_BOUND(len,32));
  
    //size_t compress_size = p4nenc64(inDetails, len, compress_buf);
    //printf("compress size is %lu\n", compress_size);
  
    switch(type){
      case P4: *out_len = p4ndec32(compress_buf, len, uncompress_buf);
      case BP: *out_len = bitnunpack32(compress_buf, len, uncompress_buf);
      /*
      case VB: {
        unsigned char* out = vbdec32(compress_buf, len, uncompress_buf);
        *out_len = out-compress_buf;
      }
      */
      default: break;
    }
#ifdef PRINT
    printf("uncompress size is %u\n", *out_len);
#endif
      return uncompress_buf;
}

uint8_t* decHlp8(unsigned char* compress_buf, unsigned len, size_t* out_len, int type) {
#ifdef PRINT
    printf("Hello TurboPFor: %u\n",len);
#endif
    // int ar[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    // unsigned elnum = 11;
    //unsigned char* compress_buf =  malloc(P4NENC_BOUND(len));
    uint8_t *uncompress_buf =  malloc(P4NDEC_BOUND(len,8));
  
    //size_t compress_size = p4nenc64(inDetails, len, compress_buf);
    //printf("compress size is %lu\n", compress_size);
  
    switch(type){
      case P4: *out_len = p4ndec8(compress_buf, len, uncompress_buf);
      case BP: *out_len = bitnunpack8(compress_buf, len, uncompress_buf);
      default: break;
    }
#ifdef PRINT
    printf("uncompress size is %u\n", *out_len);
#endif
    return uncompress_buf;
}