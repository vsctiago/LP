/* 
 * File:   student.h
 * Author: psycku
 *
 * Created on 19 de Fevereiro de 2013, 13:53
 */

#ifndef STUDENT_H
#define	STUDENT_H
#include "person.h"
//:TODO: changed INS_MAX to test easier
#define STD_MAX 2
#define INS_INIT 9999

//:CONFIRM: if unsigned float works.
typedef struct {
    unsigned short license_nr;
    Person person;
    float salary;
} Student;

Student getId(Student student){
    Bool v = FALSE;
    
    printf("License Nr: ");
    scanf("%hu", &student.license_nr);
    clearInput();
    
    while(v == FALSE){
        if(student.license_nr > 1000 && student.license_nr < 9999){
            v = TRUE;
        }else{
            v = FALSE;
            printf("Insert a valid license number:");
            scanf("%hu", &student.license_nr);
            clearInput();
        }
    }
    
    return student;
}

Student getSal(Student instructor){
    Bool v = FALSE;
    
    printf("Salary: ");
    scanf("%f", &instructor.salary);
    
    while(v == FALSE){
        if(instructor.salary >= 500 && instructor.salary <= 5000){
            v = TRUE;
        }else{
            v = FALSE;
            printf("Insert a valid salary(Range 500-5000): ");
            scanf("%hu", &instructor.salary);
            clearInput();
        }
    }
    return instructor;
}

int insVerifyPos(Student instructors[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(instructors[pos].license_nr == find){
            v = TRUE;
            return pos;
        }else{
            v = FALSE;
            pos++;
        }
    }
    if(v == FALSE && pos == STD_MAX){
        printf("File is full.");
        printf("%c", NEWLINE);
        printf("Can't add more.");
        printf("%c", NEWLINE);
    } return EOF;
}

int insFind(Student instructors[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(instructors[pos].license_nr == find){
            v = TRUE;
            return pos;
        }else{
            v = FALSE;
            pos++;
        }
    }
    if(v == FALSE && pos == STD_MAX){
        printf("Instructor not found.");
        printf("%c", NEWLINE);
    } return EOF;
}

Student initInsFile(Student instructors[]) {
    unsigned short int i;
    
    for(i = 0; i < STD_MAX; i++){
        instructors[i].license_nr = INS_INIT;
    }
    return instructors[STD_MAX];
}

Student saveInsFile(Student instructors[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("File does not exist.");
    }else{
        frtn = fwrite(instructors, sizeof(Student), STD_MAX, pIns);
    }
    return instructors[STD_MAX];
}

Student createInsFile(Student instructors[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("Failed to create file");
    }else{
        frtn = fwrite(instructors, sizeof(Student), STD_MAX, pIns);
    }
    return instructors[STD_MAX];
}

Student readInsFile(Student instructors[]){
    int i;
    
    FILE *pIns = fopen("instructors","r");
    if(pIns == (FILE *) NULL){
        puts("File does not exist.");
        puts("Creating file...");
        createInsFile(instructors);
        instructors[STD_MAX] = initInsFile(instructors);
        puts("File created.");
        readInsFile(instructors);
        for(i=0; i > STD_MAX; i++){
            printf("%d: %c", i, instructors[i].license_nr);
        }
    }else{
        fread(instructors, sizeof(Student), STD_MAX, pIns);
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

Student insAdd(Student instructors[], int insnr){

    instructors[insnr] = getLicnr(instructors[insnr]);
    instructors[insnr].person = getName(instructors[insnr].person);
    instructors[insnr].person = getAddress(instructors[insnr].person);
    instructors[insnr].person = getPhone(instructors[insnr].person);
    instructors[insnr].person = getBirthday(instructors[insnr].person);
    instructors[insnr].person = getCat(instructors[insnr].person);
    instructors[insnr] = getSal(instructors[insnr]);
    printf("Instructor added successfully.");
    printf("%c", NEWLINE);
    
    return instructors[insnr];
}

void insList(Student instructors[]){
    int i;
    
    printf("*Instructors List*");
    printf("%c", NEWLINE);
    for(i=0; i < STD_MAX; i++){
        if(instructors[i].license_nr == 9999){
            printf("%hu", instructors[i].license_nr);
            printf("%c", NEWLINE);
        }else{
            printf("%hu - %s", instructors[i].license_nr, instructors[i].person.name);
            printf("%c", NEWLINE);
        }
    }
}

Student insModify(Student instructors[]){
    Bool v = FALSE;
    int opt, lic, insnr;
    
    printf("Which u want to modify?");
    printf("%c", NEWLINE);
    insList(instructors);
    printf("Instructor number: ");
    scanf("%d", &lic);
    
    while(v == FALSE){
        insnr = insFind(instructors, lic);
        if(insnr == EOF){
            printf("Insert another: ");
            scanf("%d", &lic);
            v = FALSE;
        }else{
            v = TRUE;
        }
    }
    if(instructors[insnr].license_nr == 9999){
        printf("Instructor not found.");
        printf("%c", NEWLINE);
    }else{
        printf("What you want to modify?");
        printf("%c", NEWLINE);
        printf("1. Name");
        printf("%c", NEWLINE);
        printf("2. Address");
        printf("%c", NEWLINE);
        printf("3. Phone");
        printf("%c", NEWLINE);
        printf("4. Birthday");
        printf("%c", NEWLINE);
        printf("5. Salary");
        printf("%c", NEWLINE);
        printf("6. back");
        printf("%c", NEWLINE);
        printf("Opt: ");
        scanf("%d", &opt);
        clearInput();

        if(opt == 1){
            instructors[insnr].person = getName(instructors[insnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 2){
            instructors[insnr].person = getAddress(instructors[insnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 3){
            instructors[insnr].person = getPhone(instructors[insnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 4){
            instructors[insnr].person = getBirthday(instructors[insnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 5){
            instructors[insnr] = getSal(instructors[insnr]);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }
    }
    return instructors[insnr];
}

Student insRemove(Student instructors[]){
    Bool v = FALSE;
    int insnr, lic;
    
    printf("Instructor list:");
    insList(instructors);
    printf("Which to delete?: ");
    scanf("%d", &lic);
    printf("%c", NEWLINE);
    clearInput();
    
    while(v == FALSE){
        insnr = insFind(instructors, lic);
        if(insnr == EOF){
            printf("Insert another: ");
            scanf("%d", &lic);
            v = FALSE;
        }else{
            instructors[insnr].license_nr = INS_INIT;
            v = TRUE;
        }
    }
    
    return instructors[insnr];
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENT_H */

