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

const char EMPTY_STRING[] = "\0";

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

void clearInput() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void menu(){
    printf("1. Students");
    printf("%c", NEWLINE);
    printf("2. Instructors");
    printf("%c", NEWLINE);
    printf("3. Schedule Class");
    printf("%c", NEWLINE);
    printf("4. Exit");
    printf("%c", NEWLINE);
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UTILITIES_H */

