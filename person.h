/* 
 * File:   person.h
 * Author: psycku
 *
 * Created on 2 de Fevereiro de 2013, 0:27
 */

#ifndef PERSON_H
#define	PERSON_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "utilities.h"

#define NAME_LENGTH 80
#define STREET_LENGTH 60
#define CITY_LENGTH 20
#define POSTAL_CODE 8
#define PHONE_LENGTH 9

typedef struct tm Date;

typedef struct {
    unsigned char street[STREET_LENGTH];
    unsigned short number;
    unsigned char postalcode[POSTAL_CODE];
    unsigned char city[CITY_LENGTH];
} Address;

typedef enum {
    A = 'A', B = 'B', C = 'C', D = 'D'
} Category;

typedef struct {
    unsigned char name[NAME_LENGTH];
    Address address;
    unsigned long phonenr;
    Date date;
    Category category;
} Person;

Person getName(Person person){
    Bool v = FALSE;
    int i;
    
    printf("Full name: ");
    fgetsUpd(person.name, NAME_LENGTH);
    
    while(v == FALSE){
        for(i=0; i < NAME_LENGTH && person.name[i] != '\0' ; i++){
            if(isalpha(person.name[i]) || isspace(person.name[i])){
                v = TRUE;
            }else{
                v = FALSE;
                printf("Enter a valid Full name: ");
                fgetsUpd(person.name, NAME_LENGTH);
                break;
            }
        }//fim do for
    }
    
    return person;
}

Person getAddress(Person person){
    
    printf("*Address*");
    printf("%c", NEWLINE);
    printf("Street: ");
    fgetsUpd(person.address.street, STREET_LENGTH);
    printf("Door number: ");
    scanf("%hu", &person.address.number);
    clearInput();
    printf("PostalCode: ");
    fgetsUpd(person.address.postalcode, POSTAL_CODE);
    clearInput();
    printf("City: ");
    fgetsUpd(person.address.city, CITY_LENGTH);
    return person;
}

Person getPhone(Person person){
    printf("Phone number: ");
    scanf("%lu", &person.phonenr);
    clearInput();
    return person;
}

Person getBirthday(Person person) {
    
    printf("Birthday: ");
    scanf("%d", &person.date.tm_mday);
    clearInput();
    scanf("%d", &person.date.tm_mon);
    clearInput();
    scanf("%d", &person.date.tm_year);
    return person;
}

Person getCat(Person person) {
    char cat;
    Bool v = FALSE;
    
    do {
        clearInput();
        printf("Category: (A, B, C ou D): ");
        scanf("%c", &cat);
        if(cat == 'a' || cat == 'A') {
            person.category = A;
            v = TRUE;
        } else if (cat == 'b' || cat == 'B') {
            person.category = B;
            v = TRUE;
        } else if (cat == 'c' || cat == 'C') {
            person.category = C;
            v = TRUE;
        } else if (cat == 'd' || cat == 'D') {
            person.category = D;
            v = TRUE;
        } else {
            printf("Invalid input.");
            printf("%c", NEWLINE);
            printf("Insert a valid category!");
            printf("%c", NEWLINE);
            v = FALSE;
        }
    } while (v == FALSE);
    return person;
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PERSON_H */

