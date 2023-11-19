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
    Teacher logado;
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

    Student *studentsArray = get_students();
    // Student* currentStudent = studentsArray;

    /*
    studentsArray = addAluno("Eduardo","231080421",studentsArray);
    studentsArray = addAluno("Lucas","222080434",studentsArray);
    studentsArray = addAluno("Luis","231080434",studentsArray);

    while (currentStudent != NULL)
    {
    printf("\nNome: %s\nMatricula: %s\n", currentStudent->name, currentStudent->matricula);
    currentStudent = currentStudent->nextStudent;
    }*/

    Boletim *arrayBoletim = getBoletim();

    /*arrayBoletim = addNota("231080421", 10,"geograph",arrayBoletim);

    Boletim *currentBoletim = arrayBoletim;

    while (currentBoletim != NULL) {
        printf("%s %.2f %.2f %.2f %.2f\n", currentBoletim->matricula, currentBoletim->math, currentBoletim->cience, currentBoletim->portuguese, currentBoletim->geograph);

        // Avança para o próximo boletim na lista
        currentBoletim = currentBoletim->nextMat;
    }*/

    // printf("\nALTERADO:\n");
    // studentsArray = addAluno("ALBERTO", "231040444",10.0, studentsArray);
    // studentsArray = removeAluno("222080434",studentsArray);
    // changeNota("231080434",9.0,studentsArray);

    /*
    if(checkCPF(teachersArray, "10987654321")==true)
        printf("TRUE");
    else
        printf("False");*/

    Teacher professor;
    int decision;

labelInicial:

    printf("====================================================================\n\n");
    printf("OQUE VOCE DESEJA FAZER? \n");
    printf("\n0-SAIR\n1-LOGAR\n2-CADASTRAR\n\n");
    printf("====================================================================\n");
    scanf("%d", &decision);

    if(decision==0){
        system("cls");
        printf("====================================================================\n");
        printf("\nSAINDO DO PROGRAMA\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");
        return 0;
    }
    else if (decision == 1)
    {
    cpfLabel:
        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SEU CPF:\n\n");
        printf("====================================================================\n");
        scanf("%s", professor.cpf);
        professor.cpf[strcspn(professor.cpf, "\n")] = '\0';

        if (validateCpf(professor.cpf) == false)
        {
            sleep(5);
            goto cpfLabel;
        }

        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SUA SENHA:\n\n");
        printf("====================================================================\n");
        scanf("%s", professor.password);

        bool login = loginTeacher(professor.cpf, professor.password, teachersArray);
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
            logado = getCurrentTeacher(professor.cpf, teachersArray);
            
            system("cls");
            printf("====================================================================\n");
            printf("LOGADO COM SUCESSO! \nBEM VINDO!\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto labelLogado;
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

    else if (decision == 2)
    {

        system("cls");
        printf("=========================== CADASTRE-SE ============================\n");
        printf("====================================================================\n");
        printf("\nDIGITE SEU NOME:\n\n");
        printf("====================================================================\n");
        scanf("%s", professor.name);
        professor.name[strcspn(professor.name, "\n")] = '\0';

    cpfLabelCadastro:

        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SEU CPF:\n\n");
        printf("====================================================================\n");
        scanf("%s", professor.cpf);
        professor.cpf[strcspn(professor.cpf, "\n")] = '\0';

        if (validateCpf(professor.cpf) == false)
        {
            sleep(5);
            goto cpfLabelCadastro;
        }

    passwordLabelCadastro:

        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SUA SENHA:\n\n");
        printf("====================================================================\n");
        scanf("%s", professor.password);
        if (validatePassword(professor.password) == false)
        {
            sleep(5);
            goto passwordLabelCadastro;
        }

    matterLabelCadastro:

        system("cls");
        printf("====================================================================\n");
        printf("\nINFORME A DISCIPLINA MINISTRADA:\n\n");
        printf("1-MATEMATICA\n2-CIENCIAS\n3-PORTUGUES\n4-GEOGRAFIA\n");
        printf("====================================================================\n");
        int matterDecision;
        scanf("%d", &matterDecision);
        if (matterDecision == 1)
            strcpy(professor.matter, "math");
        else if (matterDecision == 2)
            strcpy(professor.matter, "cience");
        else if (matterDecision == 3)
            strcpy(professor.matter, "portuguese");
        else if (matterDecision == 4)
            strcpy(professor.matter, "geograph");
        sleep(3);
        system("cls");
        printf("====================================================================\n");
        printf("\nPROFESSOR CADASTRADO COM SUCESSO!\n");
        printf("====================================================================\n");
        sleep(5);
        system("cls");

        system("cls");
        addTeacher(professor.name, professor.cpf, professor.password, professor.matter, teachersArray);
        sleep(3);
        system("cls");
        goto labelInicial;
    }

    else
    {
        system("cls");
        printf("====================================================================\n");
        printf("\nDECISAO INVALIDA\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");
        goto labelInicial;
    }
    int logdecision;

labelLogado:
    printf("====================================================================\n");
    printf("\nO QUE DESEJA FAZER? \n\n");
    printf("====================================================================\n");
    printf("0-DESLOGAR\n1-ADICIONAR ALUNO\n2-REMOVER ALUNO\n3-ADICIONAR NOTA\n");
    printf("====================================================================\n");
    scanf("%d", &logdecision);
    system("cls");

    while (logdecision < 0 || logdecision > 3)
    {
        system("cls");
        printf("====================================================================\n");
        printf("\nDECISAO INVALIDA\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");
        goto labelLogado;
    }

    if (logdecision==0){
        system("cls");
        printf("====================================================================\n");
        printf("DESLOGANDO\n");
        printf("====================================================================\n");
        sleep(2);
        goto labelInicial;
    }
    else if (logdecision == 1)
    {
    Student aluno;
    labelCadAluno:
        system("cls");
        printf("========================= CADASTRAR ALUNO ============================\n");
        printf("====================================================================\n");
        printf("\nDIGITE O NOME DO ALUNO:\n\n");
        printf("====================================================================\n");
        scanf("%s", aluno.name);
        aluno.name[strcspn(aluno.name, "\n")] = '\0';

        system("cls");
        printf("========================= CADASTRAR ALUNO ============================\n");
        printf("====================================================================\n");
        printf("\nDIGITE A MATRICULA DO ALUNO:\n\n");
        printf("====================================================================\n");
        scanf("%s", aluno.matricula);
        aluno.matricula[strcspn(aluno.matricula, "\n")] = '\0';

        studentsArray = addAluno(aluno.name, aluno.matricula, studentsArray, arrayBoletim);

        if (studentsArray == false)
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nESSE ALUNO JA EXISTE! \n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto labelCadAluno;
        }
        else
        {
            sleep(3);
            system("cls");
            printf("====================================================================\n");
            printf("\nALUNO CADASTRADO COM SUCESSO!\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto labelLogado;
        }
    }
    else if (logdecision == 2)
    {
        char matricula[10];
        system("cls");
        printf("=========================== REMOVER ALUNO ==========================\n");
        printf("====================================================================\n");
        printf("\nDIGITE A MATRICULA DO ALUNO:\n\n");
        printf("====================================================================\n");
        scanf("%s", matricula);

        studentsArray = removeAluno(matricula, studentsArray);
    }
    else if (logdecision == 3)
    {
        char matricula[10];
        float newNota;
        system("cls");
        printf("========================== ADICIONAR NOTA ==========================\n");
        printf("====================================================================\n");
        printf("\nDIGITE A MATRICULA DO ALUNO:\n\n");
        printf("====================================================================\n");
        scanf("%s", &matricula);
        sleep(2);
        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE A NOTA DO ALUNO:\n\n");
        printf("====================================================================\n");
        scanf("%f", &newNota);
        sleep(3);
        system("cls");
        addNota(matricula, newNota, logado.matter, arrayBoletim);
        printf("%s\n",logado.matter);
        printf("====================================================================\n");
        printf("\nBOLETIM DO ALUNO:\n\n");
        printf("====================================================================\n");
        showBoletim(matricula, arrayBoletim);
        sleep(10);
        
    }

    goto labelLogado;
    return 0;
}