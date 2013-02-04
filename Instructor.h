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
//:TODO: changed INS_MAX to test easier
#define INS_MAX 2
#define INS_INIT 9999

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

int insVerifyPos(Instructor instructor[]){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < INS_MAX){
        if(instructor[pos].license_nr == 9999){
            v = TRUE;
            return pos;
        }else{
            v = FALSE;
            pos++;
        }
    }
    if(v == FALSE && pos == INS_MAX){
        printf("File is full.");
        printf("%c", NEWLINE);
        printf("Can't add more.");
        printf("%c", NEWLINE);
    } return EOF;
}

Instructor initInsFile(Instructor instructor[]) {
    unsigned short int i;
    
    for(i = 0; i < INS_MAX; i++){
        instructor[i].license_nr = INS_INIT;
    }
    return instructor[INS_MAX];
}

Instructor saveInsFile(Instructor instructor[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("File does not exist.");
    }else{
        frtn = fwrite(instructor, sizeof(Instructor), INS_MAX, pIns);
    }
    return instructor[INS_MAX];
}

Instructor createInsFile(Instructor instructor[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("Failed to create file");
    }else{
        frtn = fwrite(instructor, sizeof(Instructor), INS_MAX, pIns);
    }
    return instructor[INS_MAX];
}

Instructor readInsFile(Instructor instructor[]){
    int i;
    
    FILE *pIns = fopen("instructors","r");
    if(pIns == (FILE *) NULL){
        puts("File does not exist.");
        puts("Creating file...");
        createInsFile(instructor);
        instructor[INS_MAX] = initInsFile(instructor);
        puts("File created.");
        readInsFile(instructor);
        for(i=0; i > INS_MAX; i++){
            printf("%d: %c", i, instructor[i].license_nr);
        }
    }else{
        fread(instructor, sizeof(Instructor), INS_MAX, pIns);
        fclose(pIns);
    }
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
    printf("Instructor added successfully.");
    printf("%c", NEWLINE);
    
    return instructor[insnr];
}

void insList(Instructor instructor[]){
    int i;
    
    printf("*Instructors List*");
    printf("%c", NEWLINE);
    for(i=0; i < INS_MAX; i++){
        printf("%hu", instructor[i].license_nr);
        printf("%c", NEWLINE);
    }
}


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* INSTRUCTOR_H */

