#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"
#include "functions.c"

int main()
{
    setlocale(LC_ALL, "");

    Teacher *teachersArray = get_Teachers();
    Teacher logado;

    Student *studentsArray = get_students();

    Boletim *arrayBoletim = getBoletim();

    Teacher professor;
    int decision;

labelInicial:

    printf("====================================================================\n\n");
    printf("OQUE VOCE DESEJA FAZER? \n");
    printf("\n0-SAIR\n1-LOGAR\n2-CADASTRAR\n\n");
    printf("====================================================================\n");
    scanf("%d", &decision);

    if (decision == 0)
    {
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
            system("cls");
            printf("====================================================================\n");
            printf("\nDIGITE UM CPF VALIDO COM 11 NUMEROS\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
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
            printf("\nHOUVE UM ERRO! IMPOSSIVEL ACESSAR BANCO DE PROFESSORES\n\n");
            printf("====================================================================\n");
            sleep(3);
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
            sleep(3);
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
            system("cls");
            printf("====================================================================\n");
            printf("\nDIGITE UM CPF VALIDO COM 11 NUMEROS\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
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
            system("cls");
            printf("====================================================================\n");
            printf("\nSENHA INVALIDA, PRECISA POSSUIR:\n\t - NO MINIMO 8 DIGITOS\n\t - CARACTERES MAIUSCULOS\n\t - CARACTERES MINUSCULOS\n\t - NAO PODE POSSUIR ESPACOS\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto passwordLabelCadastro;
        }
        else
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nSENHA VALIDA\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
        }

    matterLabelCadastro:

        system("cls");
        printf("====================================================================\n");
        printf("\nINFORME A DISCIPLINA MINISTRADA:\n\n");
        printf("1-MATEMATICA\n2-CIENCIAS\n3-PORTUGUES\n4-GEOGRAFIA\n\n");
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
        else
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nDECISAO INVALIDA!\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto matterLabelCadastro;
        }

        sleep(3);
        system("cls");
        printf("====================================================================\n");
        printf("\nPROFESSOR CADASTRADO COM SUCESSO!\n\n");
        printf("====================================================================\n");
        sleep(3);
        system("cls");

        addTeacher(professor.name, professor.cpf, professor.password, professor.matter, teachersArray);
        teachersArray = get_Teachers();
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
    system("cls");
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

    if (logdecision == 0)
    {
        system("cls");
        printf("====================================================================\n");
        printf("DESLOGANDO...\n");
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

        if (validateMatricula(aluno.matricula) == false)
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nDIGITE UMA MATRICULA VALIDA COM 9 NUMEROS! \n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
            goto labelCadAluno;
        }

        else if (checkMatriculaBol(arrayBoletim, aluno.matricula) == true && checkMatricula(studentsArray, aluno.matricula) == true)
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
            studentsArray = addAluno(aluno.name, aluno.matricula, studentsArray);
            arrayBoletim = addAlunoBoletim(aluno.matricula, arrayBoletim);
            sleep(3);
            system("cls");
            printf("====================================================================\n");
            printf("\nALUNO CADASTRADO COM SUCESSO!\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
        }
    }
    else if (logdecision == 2)
    {
        labelRemoveAluno:
        if (studentsArray == NULL)
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nNÃO EXISTE ALUNOS PARA REMOVER!\n\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
        }
        else
        {
            char matricula[10];
            system("cls");
            printf("=========================== REMOVER ALUNO ==========================\n");
            printf("====================================================================\n");
            printf("\nDIGITE A MATRICULA DO ALUNO:\n\n");
            printf("====================================================================\n");
            scanf("%s", matricula);

            if (checkMatriculaBol(arrayBoletim, matricula) == false && checkMatricula(studentsArray, matricula) == false)
            {
                system("cls");
                printf("====================================================================\n");
                printf("\nESSE ALUNO NÃO EXISTE! \n");
                printf("====================================================================\n");
                sleep(3);
                system("cls");
                goto labelRemoveAluno;
            }

            else
            {
                studentsArray = removeAluno(matricula, studentsArray);
                arrayBoletim = removeAlunoBoletim(matricula, arrayBoletim);
                sleep(3);
                system("cls");
                printf("====================================================================\n");
                printf("\nALUNO REMOVIDO COM SUCESSO!\n");
                printf("====================================================================\n");
                sleep(3);
                system("cls");
            }
        }
    }
    else if (logdecision == 3)
    {
        labelAdicionaNota:
        if (studentsArray == NULL)
        {
            system("cls");
            printf("====================================================================\n");
            printf("\nNÃO EXISTE ALUNOS PARA ADICIONAR NOTA!\n");
            printf("====================================================================\n");
            sleep(3);
            system("cls");
        }
        else
        {
            char matricula[10];
            float newNota;
            system("cls");
            printf("========================== ADICIONAR NOTA ==========================\n");
            printf("====================================================================\n");
            printf("\nDIGITE A MATRICULA DO ALUNO:\n\n");
            printf("====================================================================\n");
            scanf("%s", &matricula);
            if (checkMatriculaBol(arrayBoletim, matricula) == false && checkMatricula(studentsArray, matricula) == false)
            {
                system("cls");
                printf("====================================================================\n");
                printf("\nESSE ALUNO NÃO EXISTE! \n");
                printf("====================================================================\n");
                sleep(3);
                system("cls");
                goto labelAdicionaNota;
            }
            else
            {
                system("cls");
                printf("====================================================================\n");
                printf("\nDIGITE A NOTA DO ALUNO:\n\n");
                printf("====================================================================\n");
                scanf("%f", &newNota);
                sleep(3);
                system("cls");
                addNota(matricula, newNota, logado.matter, arrayBoletim);
                printf("====================================================================\n");
                printf("\nBOLETIM DO ALUNO:\n\n");
                printf("====================================================================\n");
                showBoletim(matricula, arrayBoletim);
                sleep(10);
            }
        }
    }

    goto labelLogado;
    return 0;
}