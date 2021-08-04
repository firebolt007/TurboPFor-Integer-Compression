#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vp4.h"
#include "vint.h"
#include "vsimple.h"
#include "circuitutil.h"



using namespace std;

#define P4NENC_BOUND(n) ((n+127)/128+(n+64)*sizeof(uint64_t))
#define ROUND_UP(_n_, _a_) (((_n_) + ((_a_)-1)) & ~((_a_)-1))

static void memrcpy(uint64_t *out, uint64_t *in, unsigned n) { int i; for(i = 0; i < n; i++) out[i] = ~in[i]; }

int main(){
    size_t len=30;
    //unsigned char *in;
    // uint64_t* arr = (uint64_t*)malloc(sizeof(uint64_t)*len);
    //uint32_t* arr = malloc(sizeof(arr[0])*ROUND_UP(len,32));
    
    uint64_t arr[ROUND_UP(len,64)];

    for(uint64_t i=0;i<len;i++) arr[i]=i;
    compressUtil(arr,len);
    //memcpy(in,arr,sizeof(unsigned)*len);
    // unsigned char* out = malloc(P4NENC_BOUND(len));
    unsigned char* out = new unsigned char[P4NENC_BOUND(len)];
    // unsigned char out[len*16];
    //cout<<vsenc64(in,len,out)<<endl;
    cout<<"hello"<<endl;

    //unsigned char* num = (unsigned char*)malloc(sizeof(unsigned char)*10);
    //unsigned char* num;
    // uint64_t* cpy = malloc(ROUND_UP(len,64));
    uint64_t* cpy = new uint64_t[ROUND_UP(len,64)];
    // uint64_t cpy[len]={0};
    size_t num;
    num = p4nenc64(arr,len,out);
    // memrcpy(cpy, arr, len);
    num = p4ndec64(out,len,cpy);

    for(int i=0;i<len;i++) {
        cout<<cpy[i]<<", "<<endl;
    }
    cout<<cpy[3]<<endl;
    cout<<endl;
    //int i=0;
    //while(num[i]) cout<<num[i++]<<endl;
    //p4nenc32(in,len,out);
    //unsigned size;
    //memcpy(&size,num,4);
    cout<<num<<endl;
    //free(cpy);
    //free(out);
    delete [] cpy;
    delete [] out;
    //free(num);
    return 0;
}