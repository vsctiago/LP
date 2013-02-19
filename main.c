/* 
 * File:   main.c
 * Author: psycku
 *
 * Created on 2 de Fevereiro de 2013, 0:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "Instructors.h"
#include "students.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int opt, opti, insnr = 0, stdnr = 0;
    Instructor instructors[INS_MAX];
    Student students[STD_MAX];
    
    do{
        menu();
        printf("Option?: ");
        scanf("%d", &opt);
        
        if(opt == 1){
            students[STD_MAX] = readStdFile(students);
            stdMenu();
            printf("Option?: ");
            scanf("%d", &opti);
            if(opti == 1){
                stdnr = stdVerifyPos(students, STD_INIT);
                if(stdnr != EOF){
                    stdAdd(students, stdnr);
                    saveStdFile(students);
                }    
            }else if(opti == 2){
                stdModify(students);
                saveStdFile(students);
            }else if(opti == 3){
                stdList(students);
            }else if(opti == 4){
                stdRemove(students);
                saveStdFile(students);
            }
        }else if(opt == 2){
            instructors[INS_MAX] = readInsFile(instructors);
            insMenu();
            printf("Option?: ");
            scanf("%d", &opti);
            if(opti == 1){
                insnr = insVerifyPos(instructors, INS_INIT);
                if(insnr != EOF){
                    insAdd(instructors, insnr);
                    saveInsFile(instructors);
                }    
            }else if(opti == 2){
                insModify(instructors);
                saveInsFile(instructors);
            }else if(opti == 3){
                insList(instructors);
            }else if(opti == 4){
                insRemove(instructors);
                saveInsFile(instructors);
            }
        }else if(opt == 3){
            
        }
    } while(opt != 4);
    saveInsFile(instructors);
    
    return (EXIT_SUCCESS);
}

