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
#define SCH_LINE 7
#define SCH_COL 10

typedef struct {
    Instructor inssch;
    Student stdsch;
} Schedule;



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SCHEDULE_H */

