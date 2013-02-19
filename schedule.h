/* 
 * File:   schedule.h
 * Author: psycku
 *
 * Created on 8 de Fevereiro de 2013, 20:14
 */

#ifndef SCHEDULE_H
#define	SCHEDULE_H
#include <stdio.h>
#include <stdlib.h>
#include "Instructors.h"
#include "students.h"
#define SCH_LINE 10
#define SCH_COL 7
#define SCH_TIMLINE 1
#define SCH_TIMCOL 0


typedef struct {
    Instructor inssch;
    Student stdsch;
} Schedule;


/**
 * Function not working properly.
 * 
Schedule schInit(Schedule schedule){
    int x, y, n = 9;
    
    schedule[0][0] = "Início\nFim";
    
    for(y=0; y==SCH_TIMCOL; y++){
        for(x=1; x<SCH_LINE; x++){
            schedule[x][y] = "%d:00\n%d:00",n,n+1;
        }
    }
    
    for(x=0; x==SCH_TIMCOL; x++){
        for(y=1; y<SCH_COL; y++){
            if(x==0 && y==1){
                schedule[x][y] = "Segunda";
            }else if(x==0 && y==2){
                schedule[x][y] = "Terca";
            }else if(x==0 && y==3){
                schedule[x][y] = "Quarta";
            }else if(x==0 && y==4){
                schedule[x][y] = "Quinta";
            }else if(x==0 && y==5){
                schedule[x][y] = "Sexta";
            }else if(x==0 && y==6){
                schedule[x][y] = "Sabado";
            }
        }
    }
    
    for(x=1; x<SCH_LINE; x++){
        for(y=1; y<SCH_COL; y++){
            schedule[x][y] = 'x';
        }
    }
}
*/
void schMenu(){
    printf("1. Add class");
    printf("%c", NEWLINE);
    printf("2. Remove class");
    printf("%c", NEWLINE);
    printf("3. back");
    printf("%c", NEWLINE);
}

void showSchedule(Schedule schedule){
    int i,j, n=9;
    
    for(i=0; i<1; i++){
        for(j=0; j<SCH_COL; j++){
            printf("%d:00\n%d:00",n,n+1);
            n++;
        }
    }
}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SCHEDULE_H */

