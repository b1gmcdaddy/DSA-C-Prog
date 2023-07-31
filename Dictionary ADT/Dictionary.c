#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Dictionary.h"


Name newName(String firstname, String middlename, String lastname) {
    Name name;
    strcpy(name.firstname, firstname);
    strcpy(name.middlename, middlename);
    strcpy(name.lastname, lastname);
    return name;
}

MyDate newDate(int day, int month, int year) {
    MyDate date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

Student newStudent(String studID, Name studName, char sex, MyDate birthdate, String program, int year) {
    Student student;
    strcpy(student.studID, studID);
    student.studName = studName;
    student.sex = sex;
    student.birthdate = birthdate;
    strcpy(student.program, program);
    student.year = year;
    return student;
}

int hash(char c) {      //hash value is firstr letter of lastname
    return c - 'A'; 
}

void initDict(Dictionary *d, int size) {
    int i;
    d->count = 0;
    d->max = size;
    for (i = 0; i < 26; i++) {
        d->studList[i] = NULL;
    }
}

void insertSorted(Dictionary *d, Student s) {
    int index = hash(s.studName.lastname[0]);

    SType *newNode = (SType *)malloc(sizeof(SType));
    newNode->student = s;
    newNode->next = NULL;

    if (d->studList[index] == NULL) {
        d->studList[index] = newNode;
    } else {
        SType *current = d->studList[index];
        SType *prev = NULL;

        while (current != NULL && strcmp(s.studName.lastname, current->student.studName.lastname) > 0) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            newNode->next = d->studList[index];
            d->studList[index] = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
    d->count++;
}


void deleteStud(Dictionary *d, String studID) {
    int i;
    for (i = 0; i < 26; i++) {
        SType *current = d->studList[i];
        SType *prev = NULL;
        
        while (current != NULL) {
            if(strcmp(current->student.studID, studID) == 0) {
                if(prev == NULL){
                    d->studList[i] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                d->count--;
                printf("Student with ID %s deleted.\n\n", studID);
                return;
            }      
            prev = current;
            current = current->next;
        }
    }
    printf("StudID not found.\n\n");
}

void accessStud(Dictionary d, String studID) {
    int i;
    for (i = 0; i < 26; i++) {
        SType *current = d.studList[i];
        
        while (current != NULL) {
            if (strcmp(current->student.studID, studID) == 0) {
                Student s = current->student;
                printf("Student ID: %s\n", s.studID);
                printf("Name: %s %s %s\n", s.studName.firstname, s.studName.middlename, s.studName.lastname);
                printf("Sex: %c\n", s.sex);
                printf("Birthdate: %d-%d-%d\n", s.birthdate.day, s.birthdate.month, s.birthdate.year);
                printf("Program: %s\n", s.program);
                printf("Year: %d\n\n", s.year);
                return;
            }
            current = current->next;
        }
    }
    printf("StudID not found.\n\n");
}

void visualize(Dictionary d) {
    int i;
    printf("----------------------------------\n");
    printf("%-13s %-13s\n", "INDEX", "STUDENT (StudName)");
    printf("----------------------------------\n");

    for (i = 0; i < 13; i++) {
        printf("%-13c ", 'A' + i);

        SType *current = d.studList[i];

        while (current != NULL) {
            Student s = current->student;
            printf("%s, %s\n", s.studName.lastname, s.studName.firstname);
            current = current->next;
        }
        printf("\n");
    }

    for (i = 13; i < 26; i++) {
        printf("%-13c ", 'A' + i);

        SType *current = d.studList[i];

        while (current != NULL) {
            Student s = current->student;
            printf("%s, %s\n", s.studName.lastname, s.studName.firstname);
            current = current->next;
        }
        printf("\n");
    }
}

