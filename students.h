/* 
 * File:   students.h
 * Author: psycku
 *
 * Created on 19 de Fevereiro de 2013, 13:19
 */

#ifndef STUDENTS_H
#define	STUDENTS_H

#ifndef STUDENT_H
#define	STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

#define ID_LENGTH 8
#define STD_MAX 20
#define CAT_LENGTH 1
#define LR_LENGTH 1
#define STUD_MAX 2
#define STUD_INIT 9999

//:TODO: Validacoes e restricoes

typedef enum {
    y = 'y', n = 'n'
} LicenseRev;

//:TODO: VALIDATE ID = 8 NUMBERS -- init= 99999999

typedef struct {
    unsigned char id[ID_LENGTH];
    Person person;
    LicenseRev licenserev;
} Student;

Student getId(Student student) {
    Bool v = FALSE;

    clearInput();
    printf("ID: ");
    fgetsUpd(student.id, ID_LENGTH);
    return student;
}

Student getLicenseRev(Student student) {
    char lr;
    Bool v = FALSE;

    do {
        clearInput();
        printf("Revalidate license?(y or n): ");
        scanf("%c", &lr);
        if (lr == 'y' || lr == 'Y') {
            student.licenserev = y;
            v = TRUE;
        } else if (lr == 'n' || lr == 'N') {
            student.licenserev = n;
            v = TRUE;
        } else {
            printf("Invalid input.");
            printf("%c", NEWLINE);
            printf("Insert a valid category!");
            printf("%c", NEWLINE);
            v = FALSE;
        }
    } while (v == FALSE);
    return student;
}

int studVerifyPos(Student student[], int find) {
    Bool v = FALSE;
    int pos = 0;

    while (v == FALSE && pos < STUD_MAX) {
        if (student[pos].id == find) {
            v = TRUE;
            return pos;
        } else {
            v = FALSE;
            pos++;
        }
    }
    if (v == FALSE && pos == STUD_MAX) {
        printf("File is full.");
        printf("%c", NEWLINE);
        printf("Can't add more.");
        printf("%c", NEWLINE);
    }
    return EOF;
}

int studFind(Student student[], int find) {
    Bool v = FALSE;
    int pos = 0;

    while (v == FALSE && pos < STUD_MAX) {
        if (student[pos].id == find) {
            v = TRUE;
            return pos;
        } else {
            v = FALSE;
            pos++;
        }
    }
    if (v == FALSE && pos == STUD_MAX) {
        printf("Student not found.");
        printf("%c", NEWLINE);
    }
    return EOF;
}

//:TODO: Must do validations for licenserev

Student initStudFile(Student student[]) {
    unsigned short int i;

    for (i = 0; i < STD_MAX; i++) {
        strcpy(student[i++].id, EMPTY_STRING);
    }
    return student[STD_MAX];
}

Student saveStudFile(Student student[]) {
    int frtn;

    FILE *pStudents = fopen("students", "w");
    if (pStudents == (FILE *) NULL) {
        printf("File does not exist.");
    } else {
        frtn = fwrite(student, sizeof (Student), STD_MAX, pStudents);
    }
    return student[STD_MAX];
}

Student readStudFile(Student student[]) {
    int frtn, i;

    FILE *pStudents = fopen("students", "r");
    if (pStudents == (FILE *) NULL) {
        puts("File does not exist.");
        puts("Creating file...");
        saveStudFile(student);
        student[STD_MAX] = initStudFile(student);
        puts("File created.");
        readStudFile(student);
        for (i = 0; i > STD_MAX; i++) {
            printf("%d: %c", i, student[i].id);
        }
    } else {
        fread(student, sizeof (Student), STD_MAX, pStudents);
        fclose(pStudents);
    }

    return student[STD_MAX];
}

int searchStudent(Student student[], unsigned int sn) {
    int pos = 0;

    while ((pos < STD_MAX) && (sn != student[pos].id)) {
        pos++;
    }
    if (pos != STD_MAX) {
        return pos;
    } else {
        return EOF;
    }
}

Student studAdd(Student student[], int studentnr) {
    student[studentnr] = getId(student[studentnr]);
    student[studentnr].person = getName(student[studentnr].person);
    student[studentnr].person = getAddress(student[studentnr].person);
    student[studentnr].person = getPhone(student[studentnr].person);
    student[studentnr].person = getBirthday(student[studentnr].person);
    student[studentnr].person = getCat(student[studentnr].person);
    student[studentnr] = getLicenseRev(student[studentnr]);
    printf("Student added successfully.%c", NEWLINE);

    return student[studentnr];
}

void studList(Student student[]) {
    int i;

    printf("*Instructors List*");
    printf("%c", NEWLINE);
    for (i = 0; i < STUD_MAX; i++) {
        if (student[i].id == STUD_INIT) {
            printf("%hu", student[i].id);
            printf("%c", NEWLINE);
        } else {
            printf("%hu - %s", student[i].id, student[i].person.name);
            printf("%c", NEWLINE);
        }
    }
}

Student studModify(Student student[]) {
    Bool v = FALSE;
    int opt, id, studentnr;

    printf("Which u want to modify?");
    printf("%c", NEWLINE);
    studList(student);
    printf("Instructor number: ");
    scanf("%d", &id);

    while (v == FALSE) {
        studentnr = studFind(student, id);
        if (studentnr == EOF) {
            printf("Insert another: ");
            scanf("%d", &id);
            v = FALSE;
        } else {
            v = TRUE;
        }

    }

    do {
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
        printf("5. Category");
        printf("%c", NEWLINE);
        printf("6. LidenseRev");
        printf("%c", NEWLINE);
        printf("7. Back");
        printf("%c", NEWLINE);
        printf("Opt: ");
        scanf("%d", &opt);
        clearInput();

        switch (opt) {
            case 1:
                student[studentnr].person = getName(student[studentnr].person);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
            case 2:
                student[studentnr].person = getAddress(student[studentnr].person);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
            case 3:
                student[studentnr].person = getPhone(student[studentnr].person);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
            case 4:
                student[studentnr].person = getBirthday(student[studentnr].person);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
            case 5:
                student[studentnr].person = getCat(student[studentnr].person);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
            case 6:
                student[studentnr] = getLicenseRev(student[studentnr]);
                printf("Modified successfully.");
                printf("%c", NEWLINE);
                break;
        }
    } while (opt != 7);

    return student[studentnr];

}

Student studRemove(Student student[]) {
    Bool v = FALSE;
    int studentnr, id;

    printf("Student list:");
    studList(student);
    printf("Which to delete?: ");
    scanf("%d", &id);
    printf("%c", NEWLINE);
    clearInput();

    while (v == FALSE) {
        studentnr = studFind(student, id);
        if (studentnr == EOF) {
            printf("Insert another: ");
            scanf("%d", &id);
            v = FALSE;
        } else {
            student[studentnr].id = STUD_INIT;
            v = TRUE;
        }
    }

    return student[studentnr];


}

int studentMenu(Student student[STD_MAX]) {
    int stdopt, studentnr = 0;



    do {
        student[STUD_MAX] = readStudFile(student);
        do {
            printf("\t\t\t* Manage Student Data *\n\n");
            printf("\t\t\t |------------------|\n");
            printf("\t\t\t | 1-Add |\n");
            printf("\t\t\t | 2-Modify |\n");
            printf("\t\t\t | 3-List |\n");
            printf("\t\t\t | 4-Remove |\n");
            printf("\t\t\t | 5-Back |\n");
            printf("\t\t\t |------------------|\n");
            printf("Select an option: ");
            scanf("%d", &stdopt);
        } while (stdopt > 5 || stdopt < 1);
        printf("Option?: ");
        scanf("%d", &stdopt);
        switch (stdopt) {
            case 1:
                studentnr = studVerifyPos(student);
                if (studentnr != EOF) {
                    studAdd(student, studentnr);
                    saveStudFile(student);
                }
                break;
            case 2:
                studModify(student);
                break;
            case 3:
                studList(student);
                break;
            case 4:
                break;
            case 5:
                break;
        }
    } while (stdopt != 5);

    return stdopt;
}


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STUDENTS_H */

