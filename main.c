/*
 * Daniel Minami <minamid@sheridancollege.ca>
 * Assignment 1
----------------------------------------------------------------------
 */

/* 
 * File:   main.c
 * Author: Daniel Minami <minamid@sheridancollege.ca>
 *
 * Created on June 6, 2020, 8:24 PM
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 30
#define RMN(str) str[strcspn(str,"\n")]=0
#define FLUSH stdin=freopen(NULL,"r",stdin)

unsigned long fn(int);
void removeChars(char*, char*);

int main() {

    char str[MAX_LEN] = "";
    int num=0, k=0;

    printf("Series: ");
    for(int i=0;i<MAX_LEN;i++) {
        num = fn(i);
        if (num < 127 && isalnum(num)) {
            str[k++] = (char)num;
        }
        printf("%lu ", num);
    }
   
    printf("\nString: %s", str);
    
    printf("\nPlease enter characters you want to remove: ");    
    char tmp[MAX_LEN] = "";
    fgets(tmp, MAX_LEN, stdin);
    RMN(str);
    FLUSH;
    
    removeChars(str, tmp);
    printf("New String: %s", str);    
    return (0);
}

unsigned long fn(int n) {
    if (n > 2) {
        return 2*n + fn(n-1) % 60;
    } else {
        return 60;
    }
}

void removeChars(char* st, char* stToRemove) {
    
    size_t i=0, j=0, k=0;
    
    while (stToRemove[k]) {
        while (st[j]) {
            if ((st[j] != stToRemove[k])) {
                if (i!=j) {
                    st[i] = st[j];
                }
                i++;
            }
            j++;
        }
        st[i]=0;
        i=0;
        j=0;
        k++;
    }
          
}