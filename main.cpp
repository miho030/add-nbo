#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t readInt(char argv[]){
    uint8_t buffer[4] = {};
    FILE *fp = fopen(argv, "rb");
    fread(buffer, sizeof(uint8_t), 4, fp);
    if (fp == NULL) {
        printf("[!] File Open Error");
        return -1;
    }
    /*
    for (int i = 0; i < 4; i++){
        printf("testing : %x\n", buffer[i]);
    }
    */
    fclose(fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buffer);

    uint32_t tf;
    tf = ntohl(*p);
    //printf("test : 0x%x\n",tf);
    return tf;
}


void res(uint32_t thousand, uint32_t five, uint32_t sum){
    printf("%d(0x%x)  +  %d(0x%x)  =  %d(0x%x)", thousand, thousand, five, five, sum, sum);
}


int main(int argc, char **argv){
    int f1, f2;
    if (argc != 3){
        fprintf(stderr, "Usage: add-nbo <file1> <file2>");
        return 1;
    }
    else if (argc == 3){
        f1 =readInt(argv[1]);
        f2 =readInt(argv[2]);
    }
    u_int32_t sum_res = f1 + f2;
    res(f1, f2, sum_res);
}
