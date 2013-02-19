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
//Size of the string named "name"
#define NAME_LENGTH 80
//Size of the string named "street"
#define STREET_LENGTH 60
//Size of the string named "city"
#define CITY_LENGTH 30
//Size of the string named "postalcode"
#define POSTAL_CODE 8
//Position for the '-' for validation purposes
#define PC_DASH 4
//Position after the '-' for validation purposes
#define PC_ADASH 5
//Data structure used to create and change instructors & students
typedef struct tm Date;
//Address structure used to create and change instructors & students
typedef struct {
    unsigned char street[STREET_LENGTH];
    unsigned short number;
    unsigned char postalcode[POSTAL_CODE];
    unsigned char city[CITY_LENGTH];
} Address;
//Enum used for the creating and changing of instructors & students
typedef enum {
    A = 'A', B = 'B', C = 'C', D = 'D'
} Category;
/**
 * Person structure used to create and change instructors & students
 * Contains Address and Date structs aswell as Category enum
 */
typedef struct {
    unsigned char name[NAME_LENGTH];
    Address address;
    unsigned long phonenr;
    Date date;
    Category category;
} Person;
/**
 * Function used to get the name for the instructor or student.
 * 
 * @param person - recieves either one instructor or student.
 * @return - returns the same instructor or student with the new data.
 */
Person getName(Person person){
    Bool v = FALSE;
    int i;
    
    printf("Full name: ");
    fgetsUpd(person.name, NAME_LENGTH);
    //Name validation.
    while(v == FALSE){
        //for goes through the entire array or until it reaches the end('\0')
        for(i=0; i < NAME_LENGTH && person.name[i] != '\0'; i++){
            //verifies if the positions contain either a character or space
            if(isalpha(person.name[i]) || isspace(person.name[i])){
                v = TRUE;
            }else{
                /* if one position isn't either a character or space
                 * asks for another name and breaks the for.
                 */
                v = FALSE;
                printf("Enter a valid Full name: ");
                fgetsUpd(person.name, NAME_LENGTH);
                break;
            }//if ends.
        }//for ends.
    }//while ends.
    
    return person;
}
/**
 * Function used to get the name for the instructor or student.
 * 
 * @param person - recieves either one instructor or student.
 * @return - return the same instructor or student with the new data.
 */
Person getAddress(Person person){
    Bool v = FALSE;
    int i;
    
    printf("*Address*");
    printf("%c", NEWLINE);
    printf("Street: ");
    fgetsUpd(person.address.street, STREET_LENGTH);
    //Address street validation.
    while(v == FALSE){
        //for goes through the entire array or until it reaches the end('\0')
        for(i=0; i<STREET_LENGTH && person.address.street[i] != '\0'; i++){
            //verifies if the positions contain either a character or space
            if(isalpha(person.address.street[i]) || isspace(person.address.street[i])){
                v = TRUE;
            }else{
                /* if one position isn't either a character or space
                 * asks for another name and breaks the for.
                 */
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
            /* if the number isnt > 0 and < 1000 it asks to enter the 
             * number again.
             */
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
        /* verifies if 4th position of the array is a '-', if not the
         * input isnt valid.
         */
        if(person.address.postalcode[4] != '-'){
            v = FALSE;
            printf("Enter a valid postalcode: ");
            fgetsUpd(person.address.postalcode, POSTAL_CODE);
            clearInput();
        }else{
            /* for runs throught the array while if checks if the number in
             * the position is a number.
             * This only checks before the '-'.
             */
            for(i=0; i<PC_DASH; i++){
                if(isdigit(person.address.postalcode[i])){
                    v = TRUE;
                }else{
                    /* if any position doesnt contain a digit it asks for 
                     * a new postalcode.
                     */
                    v = FALSE;
                    printf("Enter a valid postalcode: ");
                    fgetsUpd(person.address.postalcode, POSTAL_CODE);
                    clearInput();
                    break;
                }//if ends.
            }//for ends.
            if(v == FALSE){
                /* Does the same thing as the other one but this one does it
                 * after the '-'
                 */ 
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
        for(i=0; i<CITY_LENGTH && person.address.city[i] != '\0'; i++){
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
/**
 * 
 * @param person
 * @return 
 */
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

