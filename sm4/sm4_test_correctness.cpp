//
//  main.c
//  SM4
//
//  Created by Christine  Lin on 07/01/2022.
//  Copyright © 2022 Christine  Lin. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "sm4.h"
//#define sm4_AVX2 1
void test_sm4(void (*sm4_enc) (const uint8_t*, uint8_t*, const sm4_key_t*,size_t blocks));
void printLineItem(unsigned char* addr,int len,int colSize)
{
    if(len)
    {
        int col=len>=colSize?colSize:len;
        
        for(int i=0;i<col;i++)
            printf("%02x ",*((unsigned char*)addr+i));
 
        for(int i=0;i<(colSize-col);i++)
            printf("   ");
        
        printf("\n");
        
        printLineItem(addr+col,len-col,colSize);
    }
    
}
int main(int argc, const char * argv[]) {
    printf("------  sm4_basic_test: \n ------");
    test_sm4(sm4_basic_encrypt_block);
    printf("\n--------  sm4_T_test: \n --------");
    test_sm4(sm4_T_encrypt_block);
    printf("\n------  sm4_avx2_test: \n ------");
    test_sm4(sm4_avx2_encrypt_block);
    printf("\n------  sm4_aesni_test: \n ------");
    test_sm4(sm4_ni_encrypt_block);
    printf("\n------  sm4_avx2ni_test: \n ------");
    test_sm4(sm4_avx2ni_encrypt_block);
}


// void sm4_avx2_ecb_encrypt_blocks(const unsigned char *in,
//     unsigned char *out, size_t blocks, const sm4_key_t *key);
// void sm4_ni_ecb_encrypt_blocks(const unsigned char *in, unsigned char *out,
//     size_t blocks, const sm4_key_t *key);

void test_sm4(void (*sm4_enc) (const uint8_t*, uint8_t*, const sm4_key_t*,size_t blocks)){
     int i;
     unsigned char user_key[16] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
    0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
    };
    unsigned char plaintext[] = {
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10
    };
    unsigned char buf[32*4];
    memset(buf,0,sizeof(buf));
    unsigned char ciphertext[] = {
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46,
         0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
         0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46
    };
    uint32_t rk[32] = {
         0xf12186f9, 0x41662b61, 0x5a6ab19a, 0x7ba92077,
         0x367360f4, 0x776a0c61, 0xb6bb89b3, 0x24763151,
         0xa520307c, 0xb7584dbd, 0xc30753ed, 0x7ee55b57,
         0x6988608c, 0x30d895b7, 0x44ba14af, 0x104495a1,
         0xd120b428, 0x73b55fa3, 0xcc874966, 0x92244439,
         0xe89e641f, 0x98ca015a, 0xc7159060, 0x99e1fd2e,
         0xb79bd80c, 0x1d2115b0, 0x0e228aeb, 0xf1780c81,
         0x428d3654, 0x62293496, 0x01cf72e5, 0x9124a012,
     };
    sm4_key_t key;
     sm4_set_key(user_key,&key);
     printf("BLOCK nums:%lu\n",sizeof(plaintext)/SM4_BLOCK_SIZE);
     if (memcmp(key.rk, rk, sizeof(rk)) != 0) {
         printf("sm4 key scheduling not passed!\n");
     }else printf("sm4 key scheduling passed!\n");
    
    size_t blocks = sizeof(plaintext)/SM4_BLOCK_SIZE;
    (*sm4_enc)(plaintext, buf, &key,blocks);
     if (memcmp(buf, ciphertext, sizeof(ciphertext)) != 0) {
         printf("sm4 encrypt not pass!\n");
     }else{
        printf("sm4 encrypt pass!\n");
    }
    //printLineItem(buf,32,16);

}





 


