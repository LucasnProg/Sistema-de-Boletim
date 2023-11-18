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

    Teacher *teachersArray = get_Teachers();
    /*teachersArray = addTeacher("Lucas","12345678910","Teste123","math",teachersArray);
    teachersArray = addTeacher("Luis","12345678911","Teste1234","cience",teachersArray);
    teachersArray = addTeacher("Eduardo","12345678912","Teste1235","portuguese",teachersArray);
    teachersArray = addTeacher("Gabriel","12345678913","Teste125","geograph",teachersArray);
    teachersArray = addTeacher("Claudio","12345678914","Teste968","teste",teachersArray);

    Teacher* currentTeacher = teachersArray;

    while (currentTeacher != NULL) {
    printf("\nNome: %s\nCPF: %s\nPASSWORD: %s\n", currentTeacher->name, currentTeacher->cpf, currentTeacher->password);
    currentTeacher = currentTeacher->nextTeacher;
    }*/


    
    printf("ALUNOS:\n");

    Student *studentsArray = get_students();
    //Student* currentStudent = studentsArray;
    
    /*
    studentsArray = addAluno("Eduardo","231080421",studentsArray);
    studentsArray = addAluno("Lucas","222080434",studentsArray);
    studentsArray = addAluno("Luis","231080434",studentsArray);
    
    while (currentStudent != NULL) 
    {
    printf("\nNome: %s\nMatricula: %s\n", currentStudent->name, currentStudent->matricula);
    currentStudent = currentStudent->nextStudent;
    }*/

    generateBoletim(studentsArray);
    Boletim *arrayBoletim = getBoletim();
    showBoletim("231080421", arrayBoletim);

    /*arrayBoletim = addNota("231080421", 10,"geograph",arrayBoletim);

    Boletim *currentBoletim = arrayBoletim;

    while (currentBoletim != NULL) {
        printf("%s %.2f %.2f %.2f %.2f\n", currentBoletim->matricula, currentBoletim->math, currentBoletim->cience, currentBoletim->portuguese, currentBoletim->geograph);

        // Avança para o próximo boletim na lista
        currentBoletim = currentBoletim->nextMat;
    }*/
    
    
    //printf("\nALTERADO:\n");
    //studentsArray = addAluno("ALBERTO", "231040444",10.0, studentsArray);
    //studentsArray = removeAluno("222080434",studentsArray);
    //changeNota("231080434",9.0,studentsArray);
    

    /*
    if(checkCPF(teachersArray, "10987654321")==true)
        printf("TRUE");
    else
        printf("False");*/

    

    Teacher professor;
    int decision;
    
    
    
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
                // goto passwordLabel;
                // Eduardo: tava em loop
            
            bool login = loginTeacher(professor.cpf,professor.password,teachersArray);
            if (login == NULL)
                {
                    system("cls");
                    printf("====================================================================\n");
                    printf("\nHOUVE UM ERRO! IMPOSSÍVEL ACESSAR BANCO DE PROFESSORES\n\n");
                    printf("====================================================================\n");
                    sleep(5);
                    system("cls");
                    goto labelInicial;
                }
            else if (login == true)
                {   
                    Teacher logado = getCurrentTeacher(professor.cpf,teachersArray);
                    system("cls");
                    printf("====================================================================\n");
                    printf("LOGADO COM SUCESSO! \nBEM VINDO!\n");
                    printf("====================================================================\n");
                    sleep(5);
                    //system("cls");
                    //goto labelLogado;
                }
            else if (login == false)
                {
                    system("cls");
                    printf("====================================================================\n");
                    printf("\nCPF OU SENHA INVÁLIDOS\n\n");
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

            matterLabelCadastro:

                system("cls");
                printf("====================================================================\n");
                printf("\nINFORME A DISCIPLINA MINISTRADA:\n\n");
                printf("1-MATEMÁTICA\n2-CIÊNCIAS\n3-PORTUGUÊS\n4-GEOGRAFIA\n");
                printf("====================================================================\n");
                int matterDecision;
                scanf("%d",&matterDecision);
                if(matterDecision == 1)
                    strcpy(professor.matter,"math");
                else if(matterDecision == 2)
                    strcpy(professor.matter,"cience");
                else if(matterDecision == 3)
                    strcpy(professor.matter,"portuguese");
                else if(matterDecision == 4)
                    strcpy(professor.matter,"geograph");
                sleep(3);
                system("cls");
                printf("====================================================================\n");
                printf("\nPROFESSOR CADASTRADO COM SUCESSO!\n");
                printf("====================================================================\n");
                sleep(5);
                system("cls");
            
            system("cls");
            addTeacher(professor.name,professor.cpf,professor.password,professor.matter,teachersArray);
            sleep(5);
            system("cls");
            goto labelInicial;
        }
    else
    {
        system("cls");
        printf("====================================================================\n");
        printf("\nDECISÃO INVÁLIDA\n");
        printf("====================================================================\n");
        system("cls");
        goto labelInicial;
    }

    labelLogado:

        printf("====================================================================\n");
        printf("\n   O QUE DESEJA FAZER? \n \n\n");
        printf("====================================================================\n");
        scanf("%d",&decision);
    
    return 0;
}