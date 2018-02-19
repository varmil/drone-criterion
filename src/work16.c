#include <string.h>

#include "common_work.h"

int calcSubjectAverage(Student *students, int num, Subject subject)
{
	int ave = 0.0;

#ifdef _ANSWER_
	int i;
	int sum = 0;
	for(i=0 ; i<num ; i++){
		sum += students[i].grade.subjects[subject];
	}
	ave = (int)( sum / num);
#endif
	return ave;	
}

int calcAllAverage(Student *students, int num)
{
	int ave = 0.0;

#ifdef _ANSWER_
	int i, j;
	int sum = 0;
	for(i=0 ; i<num ; i++){
		Grade *pGrade = &students[i].grade;
		for(j=0 ; j<SUBJECT_MAX ; j++){
			sum += pGrade->subjects[j];
		}
	}
	ave = (int)(sum / (num * SUBJECT_MAX));
#endif
	return ave;
}

Grade *getGrade(Student *students, int num, char *studentName)
{
	Grade *grade = NULL;

#ifdef _ANSWER_
	int i;

	for(i=0 ; i<num ; i++){
		if(strcmp(students->name, studentName) == 0){
			grade = &students->grade;
		}
		else{
			students++;
		}
	}	
#endif
	return grade;
}