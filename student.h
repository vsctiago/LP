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
#define STD_INIT 99999999

//:CONFIRM: if unsigned float works.

typedef enum {
    Y = 'Y', N = 'N'
} Rev;

typedef struct {
    unsigned long id;
    Person person;
    Rev rev;
} Student;

Student getId(Student student){
    Bool v = FALSE;
    
    printf("Student ID: ");
    scanf("%lu", &student.id);
    clearInput();
    
    while(v == FALSE){
        if(student.id > 10000000 && student.id < 99999999){
            v = TRUE;
        }else{
            v = FALSE;
            printf("Insert a valid ID:");
            scanf("%lu", &student.id);
            clearInput();
        }
    }
    
    return student;
}

Student getRev(Student student){
    Bool v = FALSE;
    char rev;
    
    printf("Salary: ");
    scanf("%f", &student.rev);
    
    do {
        clearInput();
        printf("Revalidate driver license?(Y,N): ");
        scanf("%c", &rev);
        if(rev == 'y' || rev == 'Y') {
            student.rev = Y;
            v = TRUE;
        } else if (rev == 'n' || rev == 'N') {
            student.rev = N;
            v = TRUE;
        } else {
            printf("Invalid input.");
            printf("%c", NEWLINE);
            printf("Insert a valid answer(Y,N)!");
            printf("%c", NEWLINE);
            v = FALSE;
        }
    } while (v == FALSE);
    return student;
}

int insVerifyPos(Student instructors[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(instructors[pos].id == find){
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

int insFind(Instructor instructors[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(instructors[pos].id == find){
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

Instructor initInsFile(Instructor instructors[]) {
    unsigned short int i;
    
    for(i = 0; i < STD_MAX; i++){
        instructors[i].id = INS_INIT;
    }
    return instructors[STD_MAX];
}

Instructor saveInsFile(Instructor instructors[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("File does not exist.");
    }else{
        frtn = fwrite(instructors, sizeof(Instructor), STD_MAX, pIns);
    }
    return instructors[STD_MAX];
}

Instructor createInsFile(Instructor instructors[]){
    int frtn;
    
    FILE *pIns = fopen("instructors","w");
    if(pIns == (FILE *) NULL){
        printf("Failed to create file");
    }else{
        frtn = fwrite(instructors, sizeof(Instructor), STD_MAX, pIns);
    }
    return instructors[STD_MAX];
}

Instructor readInsFile(Instructor instructors[]){
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
            printf("%d: %c", i, instructors[i].id);
        }
    }else{
        fread(instructors, sizeof(Instructor), STD_MAX, pIns);
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

Student insAdd(Student students[], int stdnr){

    students[stdnr] = getId(students[stdnr]);
    students[stdnr].person = getName(students[stdnr].person);
    students[stdnr].person = getAddress(students[stdnr].person);
    students[stdnr].person = getPhone(students[stdnr].person);
    students[stdnr].person = getBirthday(students[stdnr].person);
    students[stdnr].person = getCat(students[stdnr].person);
    students[stdnr] = getRev(students[stdnr]);
    printf("Instructor added successfully.");
    printf("%c", NEWLINE);
    
    return students[stdnr];
}

void insList(Student students[]){
    int i;
    
    printf("*Instructors List*");
    printf("%c", NEWLINE);
    for(i=0; i < STD_MAX; i++){
        if(students[i].id == 99999999){
            printf("%hu", students[i].id);
            printf("%c", NEWLINE);
        }else{
            printf("%hu - %s", students[i].id, students[i].person.name);
            printf("%c", NEWLINE);
        }
    }
}

Instructor insModify(Instructor instructors[]){
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
    if(instructors[insnr].id == 9999){
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

Instructor insRemove(Instructor instructors[]){
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
            instructors[insnr].id = INS_INIT;
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

