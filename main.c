#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"
#include "funct.c"

int main()
{
    setlocale(LC_ALL, "");


    
    /*Teacher *teachersArray = get_Teachers();
    teachersArray = removeTeacher("59135765412",teachersArray);
    Teacher* currentTeacher = teachersArray;

    while (currentTeacher != NULL) {
    printf("\nNome: %s\nCPF: %s\nPASSWORD: %s\n", currentTeacher->name, currentTeacher->cpf, currentTeacher->password);
    currentTeacher = currentTeacher->nextTeacher;
    }*/


    /*
    printf("ALUNOS:\n");

    Student *studentsArray = get_students();
    Student* currentStudent = studentsArray;

    //studentsArray = addAluno("Eduardo","231080421",9.8,studentsArray);
    //studentsArray = addAluno("Lucas","222080434",9.8,studentsArray);
    //studentsArray = addAluno("Luis","231080434",9.8,studentsArray);

    while (currentStudent != NULL) {
    printf("\nNome: %s\nMatricula: %s\nNota: %.2f\n", currentStudent->name, currentStudent->matricula, currentStudent->nota);
    currentStudent = currentStudent->nextStudent;
    }
    
    printf("\nALTERADO:\n");
    //studentsArray = addAluno("ALBERTO", "231040444",10.0, studentsArray);
    //studentsArray = removeAluno("222080434",studentsArray);
    changeNota("231080434",9.0,studentsArray);

    while (currentStudent != NULL) {
    printf("\nNome: %s\nMatricula: %s\nNota: %.2f\n", currentStudent->name, currentStudent->matricula, currentStudent->nota);
    currentStudent = currentStudent->nextStudent;
    }*/

    

    /*
    if(checkCPF(teachersArray, "10987654321")==true)
        printf("TRUE");
    else
        printf("False");*/

    

    //Teacher professor;
    //int decision;
    
    
    /*
    labelInicial:
    
        printf("====================================================================\n");
        printf("\n   VOCE DESEJE LOGAR OU CADASTRAR UM NOVO PROFESSOR? \n   Digite 1 para Logar ou 2 para Cadastrar.\n\n");
        printf("====================================================================\n");
        scanf("%d",&decision);

    if(decision == 1)
        {
            cpfLabel:
                system("cls");
                printf("====================================================================\n");
                printf("\nDIGITE SEU CPF:\n\n");
                printf("====================================================================\n");
                scanf("%s",professor.cpf);
                professor.cpf[strcspn(professor.cpf, "\n")] = '\0';
            
            if(validateCpf(professor.cpf) == false)
                {
                    sleep(5);
                    goto cpfLabel;
                }

            passwordLabel:

                system("cls");
                printf("====================================================================\n");
                printf("\nDIGITE SUA SENHA:\n\n");
                printf("====================================================================\n");
                scanf("%s",professor.password);

            if(validatePassword(professor.password) == false)
                {
                    sleep(5);
                    goto passwordLabel;
                }
            bool login = loginTeacher(professor.cpf,professor.password);
            if (login == NULL)
                {
                    system("cls");
                    printf("====================================================================\n");
                    printf("\nPROFESSOR NÃO CADASTRADO NO SISTEMA\n\n");
                    printf("====================================================================\n");
                    sleep(5);
                    system("cls");
                    goto labelInicial;
                }
            else if (login == true)
                {
                    system("cls");
                    printf("====================================================================\n");
                    printf("LOGADO COM SUCESSO! \nBEM VINDO!\n");
                    printf("====================================================================\n");
                    sleep(5);
                    //system("cls");
                    //goto mainMenu;
                }
            else if (login == false)
                {
                    system("cls");
                    printf("====================================================================\n");
                    printf("\nSENHA INCORRETA, TENTE NOVAMENTE!\n\n");
                    printf("====================================================================\n");
                    sleep(5);
                    system("cls");
                    goto labelInicial;
                }
        }
        
        
    else if(decision == 2)
        {

            system("cls");
            printf("=========================== CADASTRE-SE ============================\n");
            printf("====================================================================\n");
            printf("\nDIGITE SEU NOME:\n\n");
            printf("====================================================================\n");
            scanf("%s",professor.name);
            professor.name[strcspn(professor.name, "\n")] = '\0';

            cpfLabelCadastro:

                system("cls");
                printf("====================================================================\n");
                printf("\nDIGITE SEU CPF:\n\n");
                printf("====================================================================\n");
                scanf("%s",professor.cpf);
                professor.cpf[strcspn(professor.cpf, "\n")] = '\0';

            if(validateCpf(professor.cpf) == false)
                {
                    sleep(5);
                    goto cpfLabelCadastro;
                }

            passwordLabelCadastro:

                system("cls");
                printf("====================================================================\n");
                printf("\nDIGITE SUA SENHA:\n\n");
                printf("====================================================================\n");
                scanf("%s",professor.password);
                if(validatePassword(professor.password) == false)
                    {
                        sleep(5);
                        goto passwordLabelCadastro;
                    }
            
            system("cls");
            addTeacher(professor.name,professor.cpf,professor.password);
            sleep(5);
            system("cls");
            goto labelInicial;
        }*/
    
    return 0;
}