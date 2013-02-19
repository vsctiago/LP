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
#define STD_MAX 5
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

int stdVerifyPos(Student students[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(students[pos].id == find){
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

int stdFind(Student students[], int find){
    Bool v = FALSE;
    int pos = 0;
    
    while(v == FALSE && pos < STD_MAX){
        if(students[pos].id == find){
            v = TRUE;
            return pos;
        }else{
            v = FALSE;
            pos++;
        }
    }
    if(v == FALSE && pos == STD_MAX){
        printf("Student not found.");
        printf("%c", NEWLINE);
    } return EOF;
}

Student initStdFile(Student students[]) {
    unsigned short int i;
    
    for(i = 0; i < STD_MAX; i++){
        students[i].id = STD_INIT;
    }
    return students[STD_MAX];
}

Student saveStdFile(Student students[]){
    int frtn;
    
    FILE *pStd = fopen("students","w");
    if(pStd == (FILE *) NULL){
        printf("File does not exist.");
    }else{
        frtn = fwrite(students, sizeof(Student), STD_MAX, pStd);
    }
    return students[STD_MAX];
}

Student createStdFile(Student students[]){
    int frtn;
    
    FILE *pStd = fopen("students","w");
    if(pStd == (FILE *) NULL){
        printf("Failed to create file");
    }else{
        frtn = fwrite(students, sizeof(Student), STD_MAX, pStd);
    }
    return students[STD_MAX];
}

Student readStdFile(Student students[]){
    int i;
    
    FILE *pStd = fopen("students","r");
    if(pStd == (FILE *) NULL){
        puts("File does not exist.");
        puts("Creating file...");
        createStdFile(students);
        students[STD_MAX] = initStdFile(students);
        puts("File created.");
        readStdFile(students);
        for(i=0; i > STD_MAX; i++){
            printf("%d: %c", i, students[i].id);
        }
    }else{
        fread(students, sizeof(Student), STD_MAX, pStd);
        fclose(pStd);
    }
}

void stdMenu(){
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

Student stdAdd(Student students[], int stdnr){

    students[stdnr] = getId(students[stdnr]);
    students[stdnr].person = getName(students[stdnr].person);
    students[stdnr].person = getAddress(students[stdnr].person);
    students[stdnr].person = getPhone(students[stdnr].person);
    students[stdnr].person = getBirthday(students[stdnr].person);
    students[stdnr].person = getCat(students[stdnr].person);
    students[stdnr] = getRev(students[stdnr]);
    printf("Student added successfully.");
    printf("%c", NEWLINE);
    
    return students[stdnr];
}

void stdList(Student students[]){
    int i;
    
    printf("*Students List*");
    printf("%c", NEWLINE);
    for(i=0; i < STD_MAX; i++){
        if(students[i].id == STD_INIT){
            printf("%lu", students[i].id);
            printf("%c", NEWLINE);
        }else{
            printf("%lu - %s", students[i].id, students[i].person.name);
            printf("%c", NEWLINE);
        }
    }
}

Student stdModify(Student students[]){
    Bool v = FALSE;
    int opt, id, stdnr;
    
    printf("Which u want to modify?");
    printf("%c", NEWLINE);
    stdList(students);
    printf("Student id: ");
    scanf("%d", &id);
    
    while(v == FALSE){
        stdnr = stdFind(students, id);
        if(stdnr == EOF){
            printf("Insert another: ");
            scanf("%d", &id);
            v = FALSE;
        }else{
            v = TRUE;
        }
    }
    if(students[stdnr].id == 99999999){
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
        printf("5. Rev");
        printf("%c", NEWLINE);
        printf("6. back");
        printf("%c", NEWLINE);
        printf("Opt: ");
        scanf("%d", &opt);
        clearInput();

        if(opt == 1){
            students[stdnr].person = getName(students[stdnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 2){
            students[stdnr].person = getAddress(students[stdnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 3){
            students[stdnr].person = getPhone(students[stdnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 4){
            students[stdnr].person = getBirthday(students[stdnr].person);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }else if(opt == 5){
            students[stdnr] = getRev(students[stdnr]);
            printf("Modified successfully.");
            printf("%c", NEWLINE);
        }
    }
    return students[stdnr];
}

Student stdRemove(Student students[]){
    Bool v = FALSE;
    int stdnr, id;
    
    printf("Student list:");
    stdList(students);
    printf("Which to delete?: ");
    scanf("%d", &id);
    printf("%c", NEWLINE);
    clearInput();
    
    while(v == FALSE){
        stdnr = stdFind(students, id);
        if(stdnr == EOF){
            printf("Insert another: ");
            scanf("%d", &id);
            v = FALSE;
        }else{
            students[stdnr].id = STD_INIT;
            v = TRUE;
        }
    }
    
    return students[stdnr];
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENT_H */

