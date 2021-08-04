#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "circuitutil.h"



using namespace std;

#define ROUND_UP(_n_, _a_) (((_n_) + ((_a_)-1)) & ~((_a_)-1))
#define P4NENC_BOUND(n, size) ((n + 127) / 128 + (n + 32) * (size))
#define P4NDEC_BOUND(n, size) (ROUND_UP(n, 32) * (size))



int main(){
    size_t len=100000000;
    //unsigned char *in;
    // uint64_t* arr = (uint64_t*)malloc(sizeof(uint64_t)*len);
    //uint64_t* arr = malloc(sizeof(arr[0])*ROUND_UP(len,32));
    
    //uint64_t arr[ROUND_UP(len,64)];
    uint64_t* arr = new uint64_t[ROUND_UP(len,64)];

    for(uint64_t i=0;i<len;i++) arr[i]=i;
    size_t ol;
    unsigned char *compress_buf=encHlp64(arr,len,&ol,1);
    delete [] arr;
    uint64_t* out=decHlp64( compress_buf, len,&ol,1);
    free(compress_buf);
    for(int i=0;i<len;i++){
        //cout<<out[i]<<", ";
    }
    free(out);
    cout<<"hello"<<endl;

    return 0;
}