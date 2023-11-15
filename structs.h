#ifndef STRUCTS_H
#define STRUCTS_H

struct teacher
{
    char name[100];
    char cpf[12];
    char password[50];
    char matter[12];
    struct teacher *nextTeacher;
} ;

typedef struct teacher Teacher;

struct boletim
{
    char matricula[10];
    float math;
    float cience;
    float portuguese;
    float geograph;
    struct boletim *nextMat;
};

typedef struct boletim Boletim;

struct student
{
    char name[100];
    char matricula[10];
    struct student* nextStudent;
};

typedef struct student Student;


#endif