#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "circuitutil.h"



using namespace std;

#define ROUND_UP(_n_, _a_) (((_n_) + ((_a_)-1)) & ~((_a_)-1))
#define P4NENC_BOUND(n, size) ((n + 127) / 128 + (n + 32) * (size))
#define P4NDEC_BOUND(n, size) (ROUND_UP(n, 32) * (size))

#define TH 40

int main(){
    chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    size_t len=100000000;
    //unsigned char *in;
    // uint64_t* arr = (uint64_t*)malloc(sizeof(uint64_t)*len);
    //uint64_t* arr = malloc(sizeof(arr[0])*ROUND_UP(len,32));
    
    //uint64_t arr[ROUND_UP(len,64)];
    uint64_t* arr = new uint64_t[ROUND_UP(len,64)];

    for(uint64_t i=0;i<len;i++) arr[i]=i;
    //size_t ol;
    //unsigned char *compress_buf=encHlp64(arr,len,&ol,1);
    //delete [] arr;
    size_t seg=ROUND_UP(len,TH)/TH;
    size_t ll=len;
    vector<thread> threads;
    for(int i=0;i<TH;i++){
        size_t l=ll>seg?seg:ll;
        threads.push_back( thread( [arr, i, seg, l](){
                                                        size_t ol;
                                                        unsigned char *compress_buf=encHlp64(arr+i*seg,l,&ol,1);
                                                        } ) );
        ll-=seg;
    }
    for(auto& th:threads) th.join();
    delete [] arr;
    end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout<<"finished write, elapsed seconds:"<<elapsed_seconds.count()*1000<<endl;

    //uint64_t* out=decHlp64( compress_buf, len,&ol,1);
    //free(compress_buf);
    for(int i=0;i<len;i++){
        //cout<<out[i]<<", ";
    }
    //free(out);
    cout<<"hello"<<endl;

    return 0;
}