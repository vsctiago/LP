/* 
 * File:   Instructor.h
 * Author: psycku
 *
 * Created on 3 de Fevereiro de 2013, 17:15
 */

#ifndef INSTRUCTOR_H
#define	INSTRUCTOR_H
#include <stdio.h>
#include <stdlib.h>
#include "person.h"

#define INS_MAX 5

//:CONFIRM: if unsigned float works.
typedef struct {
    unsigned short license_nr;
    Person person;
    float salary;
} Instructor;

Instructor getLicnr(Instructor instructor){
    printf("License Nr: ");
    scanf("%hu", &instructor.license_nr);
    clearInput();
    return instructor;
}

Instructor getSal(Instructor instructor){
    printf("Salary: ");
    scanf("%f", &instructor.salary);
    return instructor;
}

void insMenu(){
    printf("1. Add");
    printf("%c", NEWLINE);
    printf("2. Change");
    printf("%c", NEWLINE);
    printf("3. List");
    printf("%c", NEWLINE);
    printf("4. Remove");
    printf("%c", NEWLINE);
    printf("5. Back");
    printf("%c", NEWLINE);
}

Instructor insAdd(Instructor instructor[], int insnr){
    instructor[insnr] = getLicnr(instructor[insnr]);
    instructor[insnr].person = getName(instructor[insnr].person);
    instructor[insnr].person = getAddress(instructor[insnr].person);
    instructor[insnr].person = getPhone(instructor[insnr].person);
    instructor[insnr].person = getBirthday(instructor[insnr].person);
    instructor[insnr].person = getCat(instructor[insnr].person);
    instructor[insnr] = getSal(instructor[insnr]);
    printf("Instructor added successfully. %c", NEWLINE);
    
    return instructor[insnr];
}


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* INSTRUCTOR_H */

