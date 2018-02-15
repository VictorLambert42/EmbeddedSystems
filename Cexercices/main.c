

#include <stdio.h>
#include <stdlib.h>

int checksum(int* CK_A, int* CK_B,int datas[]){
    int tmp1 = 0;
    int tmp2 = 0;
    for(int I=0;I < (int)sizeof(datas);I++){
        tmp1 = tmp1 + datas[I];
        tmp2 = tmp2 + tmp1;
    }
    printf(tmp1, tmp2);
}

int main(){
    FILE* ubx = fopen("../dataset/16040118.ubx", "rb");
    if(!ubx){
        printf("Failed to open ubx file.");
        return 1;
    }

    FILE* csv = fopen("datas.csv", "w+");
    fprintf(csv, "iTOW,tAcc,nano,year,month,day,hour,min,sec\n");

    unsigned char buffer;
    unsigned int size = 0;
    unsigned int class, id, LElength;
    int CK_A = 0, CK_B = 0;
    while(fread(&buffer, sizeof(char), 1, ubx)){
        if(buffer == 0xb5){
            fread(&buffer, sizeof(char), 1, ubx);
            if(buffer == 0x62){
                printf("New message\n");
                fread(&buffer, sizeof(char), 1, ubx);
                if(buffer == 0x01){
                    class = 0x01;

                    fread(&buffer, sizeof(char), 1, ubx);
                    if(buffer == 0x21){
                        id = 0x21;
                        printf("New time message\n");
                        unsigned char length[2];
                        fread(&length, sizeof(char), 2, ubx);
                        size = length[0] + length[1];

                        LElength = (length[1] << 8) | length[0]; // Little Endian Length for check

                        int datas[size + 3];// datas for checksum
                        datas[0] = class;
                        datas[1] = id;
                        datas[2] = LElength;
                        unsigned char payload[size];
                        fread(&payload, sizeof(char), size, ubx);

                        unsigned int y = (payload[13] << 8) | payload[12];
                        unsigned int m = payload[14];
                        unsigned int d = payload[15];
                        unsigned int hour = payload[16];
                        unsigned int min = payload[17];
                        unsigned int sec = payload[18];
                        unsigned int iTOW = (payload[3] << 24) | (payload[2] << 16) | (payload[1] << 8) | payload[0];
                        unsigned int tAcc = (payload[7] << 24) | (payload[6] << 16) | (payload[5] << 8) | payload[4];
                        int nano = (payload[11] << 24) | (payload[10] << 16) | (payload[9] << 8) | payload[8];
                        
                        datas[3] = iTOW;
                        datas[4] = tAcc;
                        datas[5] = nano;
                        datas[6] = y;
                        datas[7] = m;
                        datas[8] = d;
                        datas[9] = hour;
                        datas[10] = min;
                        datas[11] = sec;

                        checksum(&CK_A, &CK_B, datas);
                        
                        fprintf(csv, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n",iTOW,tAcc,nano,y,m,d,hour,min,sec);
                        
                    }
                }
            }
        }
    }

    int z = (0x07 << 24) | (0xe0 << 16) | (0x04 << 8) | 0x01;

    int y = z >> 16;
    int m = (z >> 8) & 0xff;
    int d = z & 0xff;

    // printf("m = %d\n",m);
    // printf("d = %d\n",d);
    // printf("y = %d\n",y);

    fclose(ubx);
    fclose(csv);
    return 0;
}