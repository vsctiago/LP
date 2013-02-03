/* 
 * File:   utilities.h
 * Author: psycku
 *
 * Created on 2 de Fevereiro de 2013, 0:28
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#define NEWLINE '\n'

typedef enum {
    FALSE, TRUE
} Bool;

Bool fgetsUpd(char * const sentence, const unsigned int size) {
    unsigned int sSiz;

    if (fgets(sentence, size, stdin) != NULL) {    
        sSiz = strlen(sentence) - 1;
        if (sentence[sSiz] == NEWLINE) {
            sentence[sSiz] = '\0';
        } else {
            return TRUE;
        }
    }else {
        return FALSE;
    }
}

void menu(){
    int opt;
    
    do{
    printf("1. Students");
    printf("2. Instructors");
    printf("3. Schedule Class");
    printf("4. Exit");
    } while (opt != 4);
    
    return opt;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */

