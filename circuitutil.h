#ifndef _CIRCUITUTIL_H_
#define _CIRCUITUTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

unsigned char* encHlp64(uint64_t* arr, unsigned len, size_t* out_len, int type);
unsigned char* encHlp32(uint32_t* arr, unsigned len, size_t* out_len, int type);
unsigned char* encHlp8(uint8_t* arr, unsigned len, size_t* out_len, int type);
uint64_t* decHlp64(unsigned char* compress_buf, unsigned len, size_t* out_len, int type);
uint32_t* decHlp32(unsigned char* compress_buf, unsigned len, size_t* out_len, int type);
uint8_t* decHlp8(unsigned char* compress_buf, unsigned len, size_t* out_len, int type);

#ifdef __cplusplus
}
#endif

#endif