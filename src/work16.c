#include "common_work.h"

#include <stdio.h>
#include <string.h>

int CalcSubjectAverage(Student *students, int num, Subject subject)
{
	int ave = 0.0;

#ifdef _ANSWER_
	int i;
	int sum = 0;
	for( i=0 ; i<num ; i++ ){
		sum += students[i].grade.subjects[subject];
	}
	ave = (int)( sum / num);
#endif
	return ave;	
}

int CalcAllAverage(Student *students, int num)
{
	int ave = 0.0;

#ifdef _ANSWER_
	int i, j;
	int sum = 0;
	for( i=0 ; i<num ; i++ ){
		Grade *pGrade = &students[i].grade;
		for( j=0 ; j<SUBJECT_MAX ; j++ ){
			sum += pGrade->subjects[j];
		}
	}
	ave = (int)( sum / ( num * SUBJECT_MAX ));
#endif
	return ave;
}

Grade *GetGrade(Student *students, int num, char *studentName)
{
#ifdef _ANSWER_
	Grade *grade = NULL;
	int i;

	for( i=0 ; i<num ; i++ ){
		if( strcmp( students->name, studentName ) == 0 ){
			grade = &students->grade;
		}
		else{
			students++;
		}
	}	

	return grade;
#else
	return NULL;
#endif
}