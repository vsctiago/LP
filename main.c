/* 
 * File:   main.c
 * Author: psycku
 *
 * Created on 2 de Fevereiro de 2013, 0:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "Instructor.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int opt, opti, insnr = 0;
    Instructor instructor[INS_MAX];
    
    do{
        menu();
        printf("Option?: ");
        scanf("%d", &opt);
        if(opt == 1){
            
        }else if(opt == 2){
            instructor[INS_MAX] = readInsFile(instructor);
            insMenu();
            printf("Option?: ");
            scanf("%d", &opti);
            if(opti == 1){
                insAdd(instructor, insnr);
                saveInsFile(instructor);
            }else if(opti == 2){
                
            }else if(opti == 3){
                insList(instructor);
            }else if(opti == 4){
                
            }
        }else if(opt == 3){
            
        }
    } while(opt != 4);
    
    return (EXIT_SUCCESS);
}

