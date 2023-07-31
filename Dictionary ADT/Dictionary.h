#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef char String[30];

typedef struct{
	String firstname, middlename, lastname;
} Name;

typedef struct{
	int day, month, year;
} MyDate;

typedef struct{
	String studID;
	Name studName;
	char sex;
	MyDate birthdate;
	String program;
	int year;	
} Student;

typedef struct node{
	Student student;
	struct node* next;
} SType;

typedef struct{
	SType *studList[26];
	int count;
	int max;           
} Dictionary;

Name newName(String firstname, String middlename, String lastname);
MyDate newDate(int day, int month, int year);
Student newStudent(String studID, Name studName, char sex, MyDate birthdate, String program, int year);
void initDict(Dictionary *d, int size);
int hash(char c);
void insertSorted(Dictionary *d, Student s);
void deleteStud(Dictionary *d, String studID);
void accessStud(Dictionary d, String studID);
void visualize(Dictionary d);

#endif
