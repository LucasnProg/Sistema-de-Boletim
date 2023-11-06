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
    
    struct Manager gerente;
    int decision;

    labelInicial:
    printf("====================================================================\n");
    printf("\n   VOCE DESEJE LOGAR OU CADASTRAR UM NOVO GERENTE? \n   Digite 1 para Logar ou 2 para Cadastrar.\n\n");
    printf("====================================================================\n");
    scanf("%d",&decision);

    if(decision == 1){
        do
        {
            cpfLabel:
            system("cls");
            printf("====================================================================\n");
            printf("\nDIGITE SEU CPF:\n\n");
            printf("====================================================================\n");
            scanf("%s",gerente.cpf);
            gerente.cpf[strcspn(gerente.cpf, "\n")] = '\0';
            
            if(validateCpf(gerente.cpf) == false){
                sleep(5);
                goto cpfLabel;
            }
            passwordLabel:
            system("cls");
            printf("====================================================================\n");
            printf("\nDIGITE SUA SENHA:\n\n");
            printf("====================================================================\n");
            scanf("%s",gerente.password);
            if(validatePassword(gerente.password) == false){
                sleep(5);
                goto passwordLabel;
            }
            bool login = loginManager(gerente.cpf,gerente.password);
            if (login == NULL)
            {
                system("cls");
                printf("====================================================================\n");
                printf("\nGERENTE NÃO CADASTRADO NO SISTEMA\n\n");
                printf("====================================================================\n");
                sleep(5);
                system("cls");
                goto labelInicial;
            }
            
        } while (loginManager(gerente.cpf,gerente.password)==false);
        
        
    }
    else if(decision == 2){

        system("cls");
        printf("=========================== CADASTRE-SE ============================\n");
        printf("====================================================================\n");
        printf("\nDIGITE SEU NOME:\n\n");
        printf("====================================================================\n");
        scanf("%s",gerente.name);
        gerente.name[strcspn(gerente.name, "\n")] = '\0';
        cpfLabelCadastro:
        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SEU CPF:\n\n");
        printf("====================================================================\n");
        scanf("%s",gerente.cpf);
        gerente.cpf[strcspn(gerente.cpf, "\n")] = '\0';

        if(validateCpf(gerente.cpf) == false){
                sleep(5);
                goto cpfLabelCadastro;
            }
        passwordLabelCadastro:
        system("cls");
        printf("====================================================================\n");
        printf("\nDIGITE SUA SENHA:\n\n");
        printf("====================================================================\n");
        scanf("%s",gerente.password);
        if(validatePassword(gerente.password) == false){
                sleep(5);
                goto passwordLabelCadastro;
            }
        
        system("cls");
        addGerente(gerente.name,gerente.cpf,gerente.password);
        sleep(5);
        system("cls");
        goto labelInicial;

    }
    
    return 0;
}