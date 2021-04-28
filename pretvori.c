//
// Created by Admin on 24. 03. 2021.
//

#include "pretvori.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void reverse(char s[])
{
    int i = 0;
    int j = strlen(s) - 1;
    char temp;
    while( j > i)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
//https://en.wikibooks.org/wiki/C_Programming/stdlib.h/itoa
//https://www.geeksforgeeks.org/implement-itoa
// Ker itoa(), ni del standardne ANSI-C knjižnice, je potrebno ročno implementirati funkcijo.
// Zasluge za implementacijo gredo tema dvema spletnima stranema za odlično in efektivno implementacijo
char* itoa(int val, char* dest, int base) {
    int i = 0;
    while (val != 0) {
        int shift = val % base;
        dest[i++] = (shift > 9) ? (shift - 10) + 'a' : shift + '0';
        val = val / base;
    }
    dest[i] = '\0';
    reverse(dest);
    return dest;
}
int preberiVhod(char* cmd[]){
    char *getCmd = cmd[1];
    char * pEnd;
    long long int li1 = strtol(cmd[1], &pEnd, 16);
    return li1;
}


int pretvoriZnak(int znak){

    char buffer[256];
    char final[256];
    char* null = "0";
    char* twonulls = "10";
    char* threenulls = "110";
    char* fournulls = "1110";
    char* fivenulls = "11110";
    itoa(znak,buffer,2);

    char* meantime = malloc(strlen(null) + strlen(buffer) + 1);
    sprintf(meantime, "%s", buffer);
    int size = strlen(buffer);
    int pos = 0;

    if (size <= 7)
    {
        int difference = 8 - size;
        for (int k=0; k < difference; k++)
        {
            pos += sprintf(&buffer[pos], "%s", null);
        }
        strcat(buffer, meantime);
    }
    else if (size <= 11)
    {
        int difference = 11 - size;
        for (int k=0; k < difference; k++)
        {
            pos += sprintf(&buffer[pos], "%s", null);
        }

        char substring1[6];
        char substring2[7];
        strcat(buffer, meantime);
        memcpy(substring1, &buffer[0],5 );
        substring1[5] = '\0';
        memcpy(substring2, &buffer[5],7 );
        substring2[6] = '\0';

        strcpy(final, threenulls);
        strcat(final, substring1);
        strcat(final, twonulls);
        strcat(final,substring2);

    }
    else if(size <= 16)
    {
        int difference = 16 - size;

        for (int k=0; k < difference; k++)
        {
            pos += sprintf(&buffer[pos], "%s", null);
        }
        strcat(buffer, meantime);

        char substring1[5];
        char substring2[7];
        char substring3[7];
        memcpy(substring1, &buffer[0],4 );
        substring1[4] = '\0';

        memcpy(substring2, &buffer[4],6 );
        substring2[6] = '\0';

        memcpy(substring3, &buffer[10],6 );
        substring3[6] = '\0';

        strcpy(final, fournulls);
        strcat(final, substring1);
        strcat(final, twonulls);
        strcat(final, substring2);
        strcat(final, twonulls);
        strcat(final, substring3);

    }
    else if(size <= 21){
        int difference = 22 - size;

        for (int k=0; k < difference; k++)
        {
            pos += sprintf(&buffer[pos], "%s", null);
        }
        strcat(buffer, meantime);

        char substring1[4];
        char substring2[7];
        char substring3[7];
        char substring4[8];

        memcpy(substring1, &buffer[0],3 );
        substring1[3] = '\0';

        memcpy(substring2, &buffer[4],6 );
        substring2[6] = '\0';

        memcpy(substring3, &buffer[10],6 );
        substring3[6] = '\0';

        memcpy(substring4, &buffer[16],7 );
        substring4[7] = '\0';

        strcpy(final, fivenulls);
        strcat(final, substring1);
        strcat(final, twonulls);
        strcat(final, substring2);
        strcat(final, twonulls);
        strcat(final, substring3);
        strcat(final, twonulls);
        strcat(final, substring4);

    }

    char *a = final;
    long int bin = strtol(final, NULL, 2  );
    sprintf(a, "%lX", bin);
    long long decimal = 0;
    decimal = strtol(a, NULL, 16);

    return decimal;
}

void izpisiZnak(int znak){
    char final[256];
    itoa(znak,final,2);
    long int bin = strtol(final, NULL, 2  );
    printf("UTF-8 binarno: %s  \n", final);
    printf("UTF-8 hex: %lX  \n", bin);
}
