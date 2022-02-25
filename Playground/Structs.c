//
// Created by Agastya Asthana on 2/22/22.
//

// Structs - composite data type
#include <stdio.h>

struct STUDENT {
    char *name; //All pointers are 8 bytes
    int id; //4 bytes for ints
};

typedef struct STUDENT STUDENT;
typedef struct EMPLOYEE {char *name; int id;} EMPLOYEE;

void Print_Student(struct STUDENT s){
    printf("By value funcstion\n");
    // Does not use call by reference
    // Makes an entirely new copy of the data
    printf("Student: %s\nStudent ID: %d\n", s.name, s.id);
    printf("Address of s = %p\n", &s);
    printf("Address of s.name = %p & address of s.id = %p\n", &s.name, &s.id);
    return;
}

void Print_Student_Reference(struct STUDENT *s){
    printf("By reference function\n");
    s->id = 277272;
    // Does not use call by reference
    // Makes an entirely new copy of the data
    printf("Student: %s\nStudent ID: %d\n", s->name, s->id);
    printf("Address of s = %p\n", &s);
    printf("Address of s.name = %p & address of s.id = %p\n", &s->name, &s->id);
    return;
}

int main(){
    struct STUDENT s;   //creates an instance of this new type
    STUDENT  s2;
    EMPLOYEE e1;
    s.name = "Ligma";
    s.id = 87736;
    Print_Student(s);
    Print_Student_Reference(&s);
    return 0;
}