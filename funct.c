#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "structs.h"
#include <string.h>
#include <locale.h>

//PROTOTÍPOS

void refreshBoletim(Student *students);
Boletim getBoletim();

//FUNÇÕES ALUNOS.

Student* get_students()
{
    FILE *alunosFilePtr;
    Student* arrayAlunos = NULL;
    Student* lastStudent = NULL;
    char currentName[100], currentMatricula[10];

    if ((alunosFilePtr = fopen("studentsData.dat", "r")) == NULL)
    {
        printf("Não foi possível acessar os dados dos alunos!\n");
    }
    else
    {
        while (fscanf(alunosFilePtr, "%s %s", currentName, currentMatricula) == 2)
        {
            Student* newStudent = (Student*)malloc(sizeof(Student));
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
    Student* currentStudent = studentsArray;

    if ((alunosfilePtr = fopen("studentsData.dat", "w")) == NULL)
    {
        printf("Não foi possivel acessar os dados dos alunos!\n");
    }
    else
    {
        while (currentStudent != NULL) 
        {
            fprintf(alunosfilePtr,"%s %s\n", currentStudent->name, currentStudent->matricula);
            currentStudent = currentStudent->nextStudent;
        }
        fclose(alunosfilePtr);
    }
    
}

bool checkMatricula(Student *arrayStudent, char matr[])
{
    Student* currentStudent = arrayStudent;

    while (currentStudent != NULL) 
    {
        if(strcmp(currentStudent -> matricula, matr)==0)
            return true;
        currentStudent = currentStudent -> nextStudent;
    }

    return false;
}

Student* addAluno(char novoName[], char newMat[], Student* arrayAlunos)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->nextStudent = NULL;

    strcpy(newStudent->name, novoName);
    strcpy(newStudent->matricula, newMat);
    
    if(arrayAlunos == NULL)
    {
        arrayAlunos = newStudent;
    }
    
    else
    {
        Student *currentStudent = arrayAlunos;
        if(checkMatricula(currentStudent, newMat))
        {
            // printf("Esse aluno ja existe!");
            return false;
            // return arrayAlunos;
        }
        else
        {
            while(currentStudent != NULL)
            {
                if(currentStudent->nextStudent == NULL)
                    {
                        
                        currentStudent -> nextStudent = newStudent;
                        refreshBoletim(arrayAlunos);
                        update_Students(arrayAlunos);
                        return arrayAlunos;
                    }
                    
                currentStudent = currentStudent->nextStudent;
            }
        }
    }    
}

Student* removeAluno(char removeMat[], Student* arrayAlunos)
{
    Student *currentStudent = arrayAlunos;
    Student *proxStudent = arrayAlunos;

    if(arrayAlunos==NULL)
    {
        printf("Nao existem alunos para serem removidos");
        return arrayAlunos;
    }
    else if(currentStudent->nextStudent == NULL)
    {
        if(strcmp(currentStudent->matricula,removeMat) == 0)
        {
            free(currentStudent);
            update_Students(arrayAlunos);
            printf("matricula removida com sucesso!\n");

        }
        return arrayAlunos;
    }
    proxStudent = proxStudent->nextStudent;
    while(proxStudent != NULL)
    {
        if(strcmp(proxStudent->matricula,removeMat) == 0)
            {
                currentStudent -> nextStudent = proxStudent -> nextStudent;
                free(proxStudent);
                update_Students(arrayAlunos);
                printf("matricula removida com sucesso!\n");

                return arrayAlunos;
            }
                
        currentStudent = currentStudent -> nextStudent;
        proxStudent = proxStudent -> nextStudent;
    }
    printf("Nao ha aluno com essa matricula\n");
    return arrayAlunos;
}

/*Student* changeNota(char mat[], float notaNova, Student* arrayAlunos)
{
    Student* currentStudent = arrayAlunos;
    if(arrayAlunos == NULL)
    {
        printf("Nao ha alunos para serem alterados.\n");
        return arrayAlunos;
    }
    else
    {
        while (currentStudent!= NULL) 
        {
            if(strcmp(currentStudent->matricula,mat) == 0)
            {
                currentStudent->nota = notaNova;
                update_Students(arrayAlunos);
                return arrayAlunos;
            }
        currentStudent = currentStudent->nextStudent;
        }
    }
    printf("O aluno nao existe.\n");
    return arrayAlunos;
}*/

//FUNÇÕES DE PROFESSORES

Teacher* get_Teachers()
{
    FILE *teacherFilePtr;
    Teacher *arrayTeacher = NULL;
    Teacher *lastTeacher = NULL;
    char currentCpf[12], currentName[100], currentPassword[50],currentMatter[12];

    if ((teacherFilePtr = fopen("teachers.dat", "r")) == NULL)
    {
        printf("Não foi possível acessar o Banco de Professores!\n");
    }
    else
    {
        while (fscanf(teacherFilePtr, "%s %s %s %s", currentName, currentCpf, currentPassword, currentMatter) == 4)
        {
            Teacher *newTeacher = (Teacher*)malloc(sizeof(Teacher));
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
    Teacher* currentTeacher = teachersArray;

    if((teacherFilePtr = fopen("teachers.dat", "w")) == NULL)
    {
        printf("Não foi possivel acessar os dados dos professores!\n");
    }
    else
    {
        while (currentTeacher != NULL) 
        {
            fprintf(teacherFilePtr,"%s %s %s %s\n", currentTeacher->name, currentTeacher->cpf, currentTeacher->password, currentTeacher->matter);
            currentTeacher = currentTeacher->nextTeacher;
        }
        fclose(teacherFilePtr);
    }
    
}

bool checkCPF(Teacher *arrayTeachers, char cpf[])
{
    char currentCpf[12];
    Teacher* currentTeacher = arrayTeachers;

    while (currentTeacher != NULL) 
    {
        strcpy(currentCpf, currentTeacher->cpf);
        if(strcmp(currentCpf,cpf)==0)
                return true;
        else
            currentTeacher = currentTeacher->nextTeacher;
    }

    return false;
}

Teacher* addTeacher(char name[], char cpf[], char password[],char matter[], Teacher *arrayTeachers)
{
    if (checkCPF(arrayTeachers, cpf) == true)
    {
        printf("RELATORIO DE ERRO:\n");
        printf("    # Esse professor ja esta cadastrado no sistema.\n    FAÇA O LOGIN!\n");
        
        return arrayTeachers; 
    }
    else
    {   
        Teacher *newTeacher = (Teacher*)malloc(sizeof(Teacher));
        newTeacher->nextTeacher = NULL;

        strcpy(newTeacher->name, name);
        strcpy(newTeacher->cpf, cpf);
        strcpy(newTeacher->password, password);
        strcpy(newTeacher->matter, matter);



        if (arrayTeachers == NULL)
        {
           arrayTeachers = newTeacher;
        }
        else
        {
            Teacher *currentTeacher = arrayTeachers;
            while (currentTeacher != NULL)
            {
                if(currentTeacher->nextTeacher == NULL)
                {
                    currentTeacher -> nextTeacher = newTeacher;
                    update_Teachers(arrayTeachers);
                    return arrayTeachers;
                }
                
                currentTeacher = currentTeacher->nextTeacher;
            }
 
        }
    }

}

Teacher getCurrentTeacher(char cpf[],  Teacher *arrayTeacher)
{
    Teacher currentTeacher;
    while (arrayTeacher != NULL)
    {
        if (strcmp(arrayTeacher->cpf,cpf) ==0)
        {
            strcpy(currentTeacher.name,arrayTeacher->name);
            strcpy(currentTeacher.cpf,arrayTeacher->cpf);
            strcpy(currentTeacher.password,arrayTeacher->password);
            strcpy(currentTeacher.matter,arrayTeacher->matter);
            currentTeacher.nextTeacher = NULL;
            // corrigido
            return currentTeacher;
        }
        arrayTeacher = arrayTeacher->nextTeacher;  
    }   
}

bool loginTeacher(char cpf[], char password[], Teacher *arrayTeacher)
{
    Teacher *currentTeacher = arrayTeacher;

    if(arrayTeacher==NULL)
        return NULL;
    while(currentTeacher != NULL)
    {
        if(strcmp(currentTeacher->cpf,cpf) == 0 && strcmp(currentTeacher->password,password) == 0)
                return true;       
        currentTeacher = currentTeacher -> nextTeacher;
    }
    return false;
}

Teacher* removeTeacher(char removeCPF[], Teacher* arrayTeacher)
{
    Teacher *currentTeacher = arrayTeacher;
    Teacher *proxTeacher = arrayTeacher;

    if(arrayTeacher==NULL)
    {
        printf("Nao existem professores para serem removidos");
        return arrayTeacher;
    }
    else if(currentTeacher->nextTeacher == NULL)
    {
        if(strcmp(currentTeacher->cpf,removeCPF) == 0)
        {
            free(currentTeacher);
            update_Teachers(arrayTeacher);
        }
        return arrayTeacher;
    }
    proxTeacher = proxTeacher->nextTeacher;
    while(proxTeacher != NULL)
    {
        if(strcmp(proxTeacher->cpf,removeCPF) == 0)
            {
                currentTeacher -> nextTeacher = proxTeacher -> nextTeacher;
                free(proxTeacher);
                update_Teachers(arrayTeacher);
                return arrayTeacher;
            }
                
        currentTeacher = currentTeacher -> nextTeacher;
        proxTeacher = proxTeacher -> nextTeacher;
    }
    printf("Nao ha professor com esse cpf\n");
    return arrayTeacher;
}

bool validatePassword(char password[])
{
    int has_digit = 0, has_upper = 0, has_lower = 0, has_space = 0;
    for (int i = 0; i < strlen(password); i++)
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
        printf("Senha Inválida!\nTamanho mínimo da senha: 8\n");
        return false;
    }
    else if (has_digit == 0)
    {
        printf("Senha Inválida!\nA senha não possui digitos\n");
        return false;
    }
    else if (has_upper == 0)
    {
        printf("Senha Inválida!\nA senha não possui caracteres maiusculos\n");
        return false;
    }
    else if (has_lower == 0)
    {
        printf("Senha Inválida!\nA senha não possui caracteres minusculos\n");
        return false;
    }
    else if (has_space != 0)
    {
        printf("Senha Inválida!\nA senha não pode possuir espaços\n");
        return false;
    }
    else
        printf("Senha válida\n");
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
        printf("DIGITE UM CPF VÁLIDO, COM 11 DIGITOS!");
        return false;
    }
    else if (notDigit != 0)
    {
        printf("DIGITE UM CPF VÁLIDO, APENAS NÚMEROS!");
        return false;
    }
    return true;
}

//FUNÇÕES DE BOLETIM

/*void createClass(char className[], Student *arrayStudents) {
    FILE *classPtr;
    Student *currentStudent = arrayStudents; 
    int length = strlen(className) + 5;
    char nameFile[length];
    strcpy(nameFile, className);
    strcat(nameFile, ".dat");
    if ((classPtr = fopen(nameFile, "w")) == NULL) 
    {
        printf("Não foi possível acessar esse arquivo\n");
    }
    else
    {
        while (currentStudent != NULL)
        {
            fprintf(classPtr,"%s %s %d\n", currentStudent->name, currentStudent->matricula, 0);
            currentStudent = currentStudent->nextStudent;
        }
        fclose(classPtr);
    }
}*/

void updateBoletim(Boletim *boletim)
{
    FILE *BolFilePtr;
    Boletim* currentBol = boletim;

    if ((BolFilePtr = fopen("boletim.dat", "w")) == NULL)
    {
        printf("Não foi possivel acessar os dados dos professores!\n");
    }
    else
    {
        while (currentBol != NULL) 
        {
            fprintf(BolFilePtr, "%s %.2f %.2f %.2f %.2f\n",currentBol->matricula, currentBol->math, currentBol->cience, currentBol->portuguese ,currentBol->geograph);
            currentBol = currentBol->nextMat;
        }
        fclose(BolFilePtr);
    } 
}

Boletim* addNota(char matricula[], float nota,char matter[], Boletim *arrayBoletim)
{
    Boletim *currentBoletim = arrayBoletim;
    while(currentBoletim != NULL)
    {
        if(strcmp(currentBoletim->matricula, matricula) == 0)
        {
            if (strcmp(matter, "math")==0)
                currentBoletim->math = nota;
            else if (strcmp(matter, "cience")==0)
                currentBoletim->cience = nota;
            else if (strcmp(matter, "portuguese")==0)
                currentBoletim->portuguese = nota;
            else if (strcmp(matter, "geograph")==0)
                currentBoletim->geograph = nota;
        }
             
        currentBoletim = currentBoletim->nextMat;
    }

    updateBoletim(arrayBoletim);
    return (arrayBoletim);

}


void generateBoletim(Student *students) 
{
    FILE *boletimPtr;

    if ((boletimPtr = fopen("boletim.dat", "w")) == NULL) {
        printf("Ocorreu algum problema ao acessar o boletim\n");
        return;
    }

    while (students != NULL) {
        fprintf(boletimPtr, "%s %.2f %.2f %.2f %.2f\n", students->matricula, 0.0, 0.0, 0.0, 0.0);
        students = students->nextStudent;
    }

    fclose(boletimPtr);
}

void refreshBoletim(Student *students) 
{
    FILE *boletimPtr;

    if ((boletimPtr = fopen("boletim.dat", "a")) == NULL) {
        printf("Ocorreu algum problema ao acessar o boletim\n");
        return;
    }

    while (students != NULL) {
        if(students->nextStudent == NULL)
        {
            fprintf(boletimPtr, "%s %.2f %.2f %.2f %.2f\n", students->matricula, 0.0, 0.0, 0.0, 0.0);
        }
        students = students->nextStudent;
    }
    Boletim *newBol = getBoletim();
    updateBoletim(newBol);

    fclose(boletimPtr);
}

Boletim* getBoletim()
{
    FILE *boletimFilePtr;
    Boletim *boletimArray = NULL;
    Boletim *lastBoletim = NULL;
    char currentMatricula[10];
    float currentMath, currentPortuguese, currentGeograph, currentCience;

    if((boletimFilePtr = fopen("boletim.dat", "r"))==NULL)
    {
        printf("Nao foi possivel acessar o boletim\n");
    }
    else
    {
        while ((fscanf(boletimFilePtr, "%s %f %f %f %f", currentMatricula,&currentMath,&currentCience,&currentPortuguese,&currentGeograph) == 5))
        {
            Boletim* newBoletim = (Boletim*)malloc(sizeof(Boletim));
            newBoletim->nextMat = NULL;

            strcpy(newBoletim->matricula, currentMatricula);;
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

Boletim* showBoletim(char matricula[], Boletim *arrayBoletim)
{

    Boletim *currentBoletim = arrayBoletim;
    float notaMath, notaCience, notaPortuguese, notaGeograph;

    while(currentBoletim != NULL)
    {
        if(strcmp(currentBoletim->matricula, matricula) == 0)
        {
            notaMath = currentBoletim->math;
            notaCience = currentBoletim->cience;
            notaPortuguese = currentBoletim->portuguese;
            notaGeograph = currentBoletim->geograph;
            printf("matematica: %.2f\nciencias: %.2f\nportugues: %.2f\ngeografia: %.2f\n",notaMath, notaCience, notaPortuguese, notaGeograph);
        }
        currentBoletim = currentBoletim->nextMat;
    }
}

/*
void update_Students(Student *studentsArray)
{
    FILE *alunosfilePtr;
    Student* currentStudent = studentsArray;

    if ((alunosfilePtr = fopen("studentsData.dat", "w")) == NULL)
    {
        printf("Não foi possivel acessar os dados dos alunos!\n");
    }
    else
    {
        while (currentStudent != NULL) 
        {
            fprintf(alunosfilePtr,"%s %s\n", currentStudent->name, currentStudent->matricula);
            currentStudent = currentStudent->nextStudent;
        }
        fclose(alunosfilePtr);
    }
    
}
*/