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
#define PC_DASH 4
#define PC_ADASH 5

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
    //Name validation.
    while(v == FALSE){
        for(i=0; i < NAME_LENGTH && person.name[i] != '\0'; i++){
            if(isalpha(person.name[i]) || isspace(person.name[i])){
                v = TRUE;
            }else{
                v = FALSE;
                printf("Enter a valid Full name: ");
                fgetsUpd(person.name, NAME_LENGTH);
                break;
            }//if ends.
        }//for ends.
    }//while ends.
    
    return person;
}

Person getAddress(Person person){
    Bool v = FALSE;
    int i;
    
    printf("*Address*");
    printf("%c", NEWLINE);
    printf("Street: ");
    fgetsUpd(person.address.street, STREET_LENGTH);
    //Address street validation.
    while(v == FALSE){
        for(i=0; i<STREET_LENGTH && person.address.street[i] != '\0'; i++){
            if(isalpha(person.address.street[i]) || isspace(person.address.street[i])){
                v = TRUE;
            }else{
                v = FALSE;
                printf("Enter a valid street name:");
                fgetsUpd(person.address.street, STREET_LENGTH);
                break;
            }//if ends.
        }//for ends.
    }//while ends.
    printf("Door number: ");
    scanf("%hu", &person.address.number);
    clearInput();
    //Address number validation.
    v = FALSE;
    while(v == FALSE){
        if(person.address.number > 0 && person.address.number < 1000){
            v = TRUE;
        }else{
            v = FALSE;
            printf("Enter a valid number: ");
            scanf("%hu", &person.address.number);
        }//if ends.
    }//while ends.
    printf("PostalCode: ");
    fgetsUpd(person.address.postalcode, POSTAL_CODE);
    clearInput();
    //Postalcode validations.
    v = FALSE;
    while(v == FALSE){
        if(person.address.postalcode[4] != '-'){
            v = FALSE;
            printf("Enter a valid postalcode: ");
            fgetsUpd(person.address.postalcode, POSTAL_CODE);
            clearInput();
        }else{
            for(i=0; i<PC_DASH; i++){
                if(isdigit(person.address.postalcode[i])){
                    v = TRUE;
                }else{
                    v = FALSE;
                    printf("Enter a valid postalcode: ");
                    fgetsUpd(person.address.postalcode, POSTAL_CODE);
                    clearInput();
                    break;
                }//if ends.
            }//for ends.
            if(v == FALSE){
                for(i=PC_ADASH; i<POSTAL_CODE; i++){
                    if(isdigit(person.address.postalcode[i])){
                        v = TRUE;
                    }else{
                        v = FALSE;
                        printf("Enter a valid postalcode: ");
                        fgetsUpd(person.address.postalcode, POSTAL_CODE);
                        clearInput();
                        break;
                    }//Second if/else for postalcode ends.
                }//After '-' for ends.
            }//Postalcode if ends.
        }//First if ends.
    }//while ends.
    printf("City: ");
    fgetsUpd(person.address.city, CITY_LENGTH);
    //City validation.
    v = FALSE;
    while(v == FALSE){
        for(i=0; i<CITY_LENGTH && person.address.city != '\0'; i++){
            if(isalpha(person.address.city[i]) || isspace(person.address.city[i])){
                v = TRUE;
            }else{
                v = FALSE;
                printf("Enter a valid city name:");
                fgetsUpd(person.address.city, CITY_LENGTH);
                break;
            }//if ends.
        }//for ends.
    }//while ends.
    
    return person;
}

Person getPhone(Person person){
    Bool v = FALSE;
    
    printf("Phone number: ");
    scanf("%lu", &person.phonenr);
    clearInput();
    
    while(v == FALSE){
        if(person.phonenr > 0 && person.phonenr < 970000000){
            if(person.phonenr > 210000000 && person.phonenr < 299999999){
                v = TRUE;
            }else if(person.phonenr > 910000000 && person.phonenr < 919999999){
                v = TRUE;
            }else if(person.phonenr > 920000000 && person.phonenr < 929999999){
                v = TRUE;
            }else if(person.phonenr > 930000000 && person.phonenr < 939999999){
                v = TRUE;
            }else if(person.phonenr > 960000000 && person.phonenr < 969999999){
                v = TRUE;  
            }else{
                v = FALSE;
                printf("Insert a valid phone number: ");
                scanf("%lu", &person.phonenr);
                clearInput();
            }
        }else{
            v = FALSE;
            printf("Insert a valid phone number: ");
            scanf("%lu", &person.phonenr);
            clearInput();
        }
    }
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

