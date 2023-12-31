#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "structs.h"
#include <string.h>
#include <locale.h>

// PROTOTÍPOS
Student *get_students();

void update_Students(Student *studentsArray);

bool validateMatricula(char matricula[]);

bool checkMatricula(Student *arrayStudent, char matr[]);

Student *addAluno(char novoName[], char newMat[], Student *arrayAlunos);

Student *removeAluno(char removeMat[], Student *arrayAlunos);

Teacher *get_Teachers();

void update_Teachers(Teacher *teachersArray);

bool checkCPF(Teacher *arrayTeachers, char cpf[]);

Teacher *addTeacher(char name[], char cpf[], char password[], char matter[], Teacher *arrayTeachers);

Teacher getCurrentTeacher(char cpf[], Teacher *arrayTeacher);

bool loginTeacher(char cpf[], char password[], Teacher *arrayTeacher);

Teacher *removeTeacher(char removeCPF[], Teacher *arrayTeacher);

bool validatePassword(char password[]);

bool validateCpf(char cpf[]);

void updateBoletim(Boletim *boletim);

Boletim *addNota(char matricula[], float nota, char matter[], Boletim *arrayBoletim);

bool checkMatriculaBol(Boletim *arrayBol, char matr[]);

Boletim *addAlunoBoletim(char newMat[], Boletim *arrayBoletim);

Boletim *removeAlunoBoletim(char removeMat[], Boletim *arrayBoletim);

void generateBoletim(Student *students);

Boletim *getBoletim();

void showBoletim(char matricula[], Boletim *arrayBoletim);

// FUNÇÕES ALUNOS.

Student *get_students()
{
    FILE *alunosFilePtr;
    Student *arrayAlunos = NULL;
    Student *lastStudent = NULL;
    char currentName[100], currentMatricula[10];

    if ((alunosFilePtr = fopen("studentsData.dat", "r")) == NULL)
    {
        alunosFilePtr = fopen("studentsData.dat", "w");
        return arrayAlunos;
    }
    else
    {
        while (fscanf(alunosFilePtr, "%s %s", currentName, currentMatricula) == 2)
        {
            Student *newStudent = (Student *)malloc(sizeof(Student));
            newStudent->nextStudent = NULL;

            strcpy(newStudent->name, currentName);
            strcpy(newStudent->matricula, currentMatricula);

            if (arrayAlunos == NULL)
            {
                arrayAlunos = newStudent;
                lastStudent = newStudent;
            }
            else
            {
                lastStudent->nextStudent = newStudent;
                lastStudent = newStudent;
            }
        }
        fclose(alunosFilePtr);
    }

    return arrayAlunos;
}

void update_Students(Student *studentsArray)
{
    FILE *alunosfilePtr;
    Student *currentStudent = studentsArray;

    if ((alunosfilePtr = fopen("studentsData.dat", "w")) == NULL)
    {
        printf("Não foi possível acessar os dados dos alunos! Verifique a permissão do arquivo.\n");
    }
    else
    {
        while (currentStudent != NULL)
        {
            fprintf(alunosfilePtr, "%s %s\n", currentStudent->name, currentStudent->matricula);
            currentStudent = currentStudent->nextStudent;
        }
        fclose(alunosfilePtr);
    }
}

bool validateMatricula(char matricula[])
{
    setlocale(LC_ALL, "");
    int notDigit = 0;
    for (int i = 0; i < 9; i++)
    {
        if (!isdigit(matricula[i]))
        {
            notDigit++;
        }
    }
    if (strlen(matricula) != 9)
    {
        return false;
    }
    else if (notDigit != 0)
    {
        return false;
    }
    return true;
}

bool checkMatricula(Student *arrayStudent, char matr[])
{
    Student *currentStudent = arrayStudent;

    while (currentStudent != NULL)
    {
        if (strcmp(currentStudent->matricula, matr) == 0)
            return true;
        currentStudent = currentStudent->nextStudent;
    }

    return false;
}

Student *addAluno(char novoName[], char newMat[], Student *arrayAlunos)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->nextStudent = NULL;

    strcpy(newStudent->name, novoName);
    strcpy(newStudent->matricula, newMat);

    if (arrayAlunos == NULL)
    {
        arrayAlunos = newStudent;
        update_Students(arrayAlunos);
        return arrayAlunos;
    }

    else
    {
        Student *currentStudent = arrayAlunos;
        while (currentStudent != NULL)
        {
            if (currentStudent->nextStudent == NULL)
            {
                currentStudent->nextStudent = newStudent;
                update_Students(arrayAlunos);
                return arrayAlunos;
            }

            currentStudent = currentStudent->nextStudent;
        }
    }
}

Student *removeAluno(char removeMat[], Student *arrayAlunos)
{
    Student *currentStudent = arrayAlunos;
    Student *proxStudent = arrayAlunos;

    if (arrayAlunos == NULL)
    {
        return arrayAlunos;
    }
    else if (currentStudent->nextStudent == NULL)
    {
        if (strcmp(currentStudent->matricula, removeMat) == 0)
        {
            free(currentStudent);
            arrayAlunos = NULL;
            update_Students(arrayAlunos);
            return arrayAlunos;
        }
    }
    else
    {
        proxStudent = proxStudent->nextStudent;

        if (strcmp(currentStudent->matricula, removeMat) == 0)
        {
            arrayAlunos = proxStudent;
            free(currentStudent);
            update_Students(arrayAlunos);
            return arrayAlunos;
        }

        while (proxStudent != NULL)
        {
            if (strcmp(proxStudent->matricula, removeMat) == 0)
            {
                currentStudent->nextStudent = proxStudent->nextStudent;
                free(proxStudent);
                update_Students(arrayAlunos);

                return arrayAlunos;
            }

            currentStudent = currentStudent->nextStudent;
            proxStudent = proxStudent->nextStudent;
        }
    }
    return arrayAlunos;
}

// FUNÇÕES DE PROFESSORES

Teacher *get_Teachers()
{
    FILE *teacherFilePtr;
    Teacher *arrayTeacher = NULL;
    Teacher *lastTeacher = NULL;
    char currentCpf[12], currentName[100], currentPassword[50], currentMatter[12];

    if ((teacherFilePtr = fopen("teachers.dat", "r")) == NULL)
    {
        teacherFilePtr = fopen("teachers.dat", "w");
        return (arrayTeacher);
    }
    else
    {
        while (fscanf(teacherFilePtr, "%s %s %s %s", currentName, currentCpf, currentPassword, currentMatter) == 4)
        {
            Teacher *newTeacher = (Teacher *)malloc(sizeof(Teacher));
            newTeacher->nextTeacher = NULL;

            strcpy(newTeacher->name, currentName);
            strcpy(newTeacher->cpf, currentCpf);
            strcpy(newTeacher->password, currentPassword);
            strcpy(newTeacher->matter, currentMatter);

            if (arrayTeacher == NULL)
            {
                arrayTeacher = newTeacher;
                lastTeacher = newTeacher;
            }
            else
            {
                lastTeacher->nextTeacher = newTeacher;
                lastTeacher = newTeacher;
            }
        }
        fclose(teacherFilePtr);
    }
    return arrayTeacher;
}

void update_Teachers(Teacher *teachersArray)
{
    FILE *teacherFilePtr;
    Teacher *currentTeacher = teachersArray;

    if ((teacherFilePtr = fopen("teachers.dat", "w")) == NULL)
    {

        printf("Não foi possivel acessar os dados dos professores!\n");
    }
    else
    {
        while (currentTeacher != NULL)
        {
            fprintf(teacherFilePtr, "%s %s %s %s\n", currentTeacher->name, currentTeacher->cpf, currentTeacher->password, currentTeacher->matter);
            currentTeacher = currentTeacher->nextTeacher;
        }
        fclose(teacherFilePtr);
    }
}

bool checkCPF(Teacher *arrayTeachers, char cpf[])
{
    char currentCpf[12];
    Teacher *currentTeacher = arrayTeachers;

    while (currentTeacher != NULL)
    {
        strcpy(currentCpf, currentTeacher->cpf);
        if (strcmp(currentCpf, cpf) == 0)
            return true;
        else
            currentTeacher = currentTeacher->nextTeacher;
    }

    return false;
}

Teacher *addTeacher(char name[], char cpf[], char password[], char matter[], Teacher *arrayTeachers)
{
    if (checkCPF(arrayTeachers, cpf) == true)
    {
        system("cls");
        printf("====================================================================\n");
        printf("\nESSE PROFESSOR JA ESTA CADASTRADO NO SISTEMA, FAÇA O LOGIN!\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");

        return arrayTeachers;
    }
    else
    {
        Teacher *newTeacher = (Teacher *)malloc(sizeof(Teacher));
        newTeacher->nextTeacher = NULL;

        strcpy(newTeacher->name, name);
        strcpy(newTeacher->cpf, cpf);
        strcpy(newTeacher->password, password);
        strcpy(newTeacher->matter, matter);

        if (arrayTeachers == NULL)
        {
            arrayTeachers = newTeacher;
            update_Teachers(arrayTeachers);
            return arrayTeachers;
        }
        else
        {
            Teacher *currentTeacher = arrayTeachers;
            while (currentTeacher != NULL)
            {
                if (currentTeacher->nextTeacher == NULL)
                {
                    currentTeacher->nextTeacher = newTeacher;
                    update_Teachers(arrayTeachers);
                    return arrayTeachers;
                }

                currentTeacher = currentTeacher->nextTeacher;
            }
        }
    }
}

Teacher getCurrentTeacher(char cpf[], Teacher *arrayTeacher)
{
    Teacher currentTeacher;
    while (arrayTeacher != NULL)
    {
        if (strcmp(arrayTeacher->cpf, cpf) == 0)
        {
            strcpy(currentTeacher.name, arrayTeacher->name);
            strcpy(currentTeacher.cpf, arrayTeacher->cpf);
            strcpy(currentTeacher.password, arrayTeacher->password);
            strcpy(currentTeacher.matter, arrayTeacher->matter);
            currentTeacher.nextTeacher = NULL;
            return currentTeacher;
        }
        arrayTeacher = arrayTeacher->nextTeacher;
    }
}

bool loginTeacher(char cpf[], char password[], Teacher *arrayTeacher)
{
    Teacher *currentTeacher = arrayTeacher;

    if (arrayTeacher == NULL)
        return NULL;
    while (currentTeacher != NULL)
    {
        if (strcmp(currentTeacher->cpf, cpf) == 0 && strcmp(currentTeacher->password, password) == 0)
            return true;
        currentTeacher = currentTeacher->nextTeacher;
    }
    return false;
}

Teacher *removeTeacher(char removeCPF[], Teacher *arrayTeacher)
{
    Teacher *currentTeacher = arrayTeacher;
    Teacher *proxTeacher = arrayTeacher;

    if (arrayTeacher == NULL)
    {
        system("cls");
        printf("====================================================================\n");
        printf("\nNAO EXISTEM PROFESSORES PARA SEREM REMOVIDOS!\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");
        return arrayTeacher;
    }
    else if (currentTeacher->nextTeacher == NULL)
    {
        if (strcmp(currentTeacher->cpf, removeCPF) == 0)
        {
            free(currentTeacher);
            update_Teachers(arrayTeacher);
        }
        return arrayTeacher;
    }
    proxTeacher = proxTeacher->nextTeacher;
    while (proxTeacher != NULL)
    {
        if (strcmp(proxTeacher->cpf, removeCPF) == 0)
        {
            currentTeacher->nextTeacher = proxTeacher->nextTeacher;
            free(proxTeacher);
            update_Teachers(arrayTeacher);
            return arrayTeacher;
        }

        currentTeacher = currentTeacher->nextTeacher;
        proxTeacher = proxTeacher->nextTeacher;
    }
    system("cls");
    printf("====================================================================\n");
    printf("\nNAO HA PROFESSOR COM ESSE CPF\n\n");
    printf("====================================================================\n");
    sleep(3);
    system("cls");
    return arrayTeacher;
}

bool validatePassword(char password[])
{
    int has_digit = 0, has_upper = 0, has_lower = 0, has_space = 0, length = strlen(password);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            has_digit++;
        }
        else if (isupper(password[i]))
        {
            has_upper++;
        }
        else if (islower(password[i]))
        {
            has_lower++;
        }
        else if (isspace(password[i]))
        {
            has_space++;
        }
    }
    if (strlen(password) < 8)
    {
        return false;
    }
    else if (has_digit == 0)
    {
        return false;
    }
    else if (has_upper == 0)
    {
        return false;
    }
    else if (has_lower == 0)
    {
        return false;
    }
    else if (has_space != 0)
    {
        return false;
    }
    else
        return true;
}

bool validateCpf(char cpf[])
{
    setlocale(LC_ALL, "");
    int notDigit = 0;
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            notDigit++;
        }
    }
    if (strlen(cpf) != 11)
    {
        return false;
    }
    else if (notDigit != 0)
    {
        return false;
    }
    return true;
}

// FUNÇÕES DE BOLETIM

void updateBoletim(Boletim *boletim)
{
    FILE *BolFilePtr;
    Boletim *currentBol = boletim;

    if ((BolFilePtr = fopen("boletim.dat", "w")) == NULL)
    {
        printf("Não foi possivel acessar os dados dos professores!\n");
    }
    else
    {
        while (currentBol != NULL)
        {
            fprintf(BolFilePtr, "%s %.2f %.2f %.2f %.2f\n", currentBol->matricula, currentBol->math, currentBol->cience, currentBol->portuguese, currentBol->geograph);
            currentBol = currentBol->nextMat;
        }
        fclose(BolFilePtr);
    }
}

Boletim *addNota(char matricula[], float nota, char matter[], Boletim *arrayBoletim)
{
    Boletim *currentBoletim = arrayBoletim;
    while (currentBoletim != NULL)
    {
        if (strcmp(currentBoletim->matricula, matricula) == 0)
        {
            if (strcmp(matter, "math") == 0)
                currentBoletim->math = nota;
            else if (strcmp(matter, "cience") == 0)
                currentBoletim->cience = nota;
            else if (strcmp(matter, "portuguese") == 0)
                currentBoletim->portuguese = nota;
            else if (strcmp(matter, "geograph") == 0)
                currentBoletim->geograph = nota;
        }

        currentBoletim = currentBoletim->nextMat;
    }

    updateBoletim(arrayBoletim);
    return (arrayBoletim);
}

bool checkMatriculaBol(Boletim *arrayBol, char matr[])
{
    Boletim *currentBoletim = arrayBol;

    while (currentBoletim != NULL)
    {
        if (strcmp(currentBoletim->matricula, matr) == 0)
            return true;
        currentBoletim = currentBoletim->nextMat;
    }

    return false;
}

Boletim *addAlunoBoletim(char newMat[], Boletim *arrayBoletim)
{
    Boletim *newStudent = (Boletim *)malloc(sizeof(Boletim));
    newStudent->nextMat = NULL;

    strcpy(newStudent->matricula, newMat);
    newStudent->math = 0.0;
    newStudent->cience = 0.0;
    newStudent->portuguese = 0.0;
    newStudent->geograph = 0.0;

    if (arrayBoletim == NULL)
    {
        arrayBoletim = newStudent;
        updateBoletim(arrayBoletim);
        return (arrayBoletim);
    }

    else
    {
        Boletim *currentBol = arrayBoletim;
        while (currentBol != NULL)
        {
            if (currentBol->nextMat == NULL)
            {

                currentBol->nextMat = newStudent;
                updateBoletim(arrayBoletim);
                return arrayBoletim;
            }

            currentBol = currentBol->nextMat;
        }
    }
}

Boletim *removeAlunoBoletim(char removeMat[], Boletim *arrayBoletim)
{
    Boletim *currentBol = arrayBoletim;
    Boletim *proxBol = arrayBoletim;

    if (arrayBoletim == NULL)
    {
        return arrayBoletim;
    }
    else if (currentBol->nextMat == NULL)
    {
        if (strcmp(currentBol->matricula, removeMat) == 0)
        {
            free(currentBol);
            arrayBoletim = NULL;
            updateBoletim(arrayBoletim);
            return arrayBoletim;
        }
    }
    else
    {
        proxBol = proxBol->nextMat;

        if (strcmp(currentBol->matricula, removeMat) == 0)
        {
            arrayBoletim = proxBol;
            free(currentBol);
            updateBoletim(arrayBoletim);
            return arrayBoletim;
        }

        while (proxBol != NULL)
        {
            if (strcmp(proxBol->matricula, removeMat) == 0)
            {
                currentBol->nextMat = proxBol->nextMat;
                free(proxBol);
                updateBoletim(arrayBoletim);

                return arrayBoletim;
            }

            currentBol = currentBol->nextMat;
            proxBol = proxBol->nextMat;
        }
    }
    return arrayBoletim;
}

Boletim *getBoletim()
{
    FILE *boletimFilePtr;
    Boletim *boletimArray = NULL;
    Boletim *lastBoletim = NULL;
    char currentMatricula[10];
    float currentMath, currentPortuguese, currentGeograph, currentCience;

    if ((boletimFilePtr = fopen("boletim.dat", "r")) == NULL)
    {
        boletimFilePtr = fopen("boletim.dat", "w");
        return (boletimArray);
    }
    else
    {
        while ((fscanf(boletimFilePtr, "%s %f %f %f %f", currentMatricula, &currentMath, &currentCience, &currentPortuguese, &currentGeograph) == 5))
        {
            Boletim *newBoletim = (Boletim *)malloc(sizeof(Boletim));
            newBoletim->nextMat = NULL;

            strcpy(newBoletim->matricula, currentMatricula);
            ;
            newBoletim->math = currentMath;
            newBoletim->cience = currentCience;
            newBoletim->portuguese = currentPortuguese;
            newBoletim->geograph = currentGeograph;

            if (boletimArray == NULL)
            {
                boletimArray = newBoletim;
                lastBoletim = newBoletim;
            }
            else
            {
                lastBoletim->nextMat = newBoletim;
                lastBoletim = newBoletim;
            }
        }
        fclose(boletimFilePtr);
    }

    return boletimArray;
}

void showBoletim(char matricula[], Boletim *arrayBoletim)
{

    Boletim *currentBoletim = arrayBoletim;
    float notaMath, notaCience, notaPortuguese, notaGeograph;

    while (currentBoletim != NULL)
    {
        if (strcmp(currentBoletim->matricula, matricula) == 0)
        {
            notaMath = currentBoletim->math;
            notaCience = currentBoletim->cience;
            notaPortuguese = currentBoletim->portuguese;
            notaGeograph = currentBoletim->geograph;
            printf("matematica: %.2f\nciencias: %.2f\nportugues: %.2f\ngeografia: %.2f\n", notaMath, notaCience, notaPortuguese, notaGeograph);
        }
        currentBoletim = currentBoletim->nextMat;
    }
}
