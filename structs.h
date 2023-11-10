#ifndef STRUCTS_H
#define STRUCTS_H

struct teacher
{
    char name[100];
    char cpf[12];
    char password[50];
    struct teacher *nextTeacher;
} ;

typedef struct teacher Teacher;

/*struct disciplina
{
    char matricula[10];
    float math;
    float cience;
    float portugues;
    float geograph;
    struct disciplina *proxMatricula;
};*/


struct student
{
    char name[100];
    char matricula[10];
    float nota;
    struct student* nextStudent;
    
};

typedef struct student Student;


#endif