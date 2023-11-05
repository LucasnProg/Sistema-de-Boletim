#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structs.h"
#include "database.c"

bool checkCPF(char name[], char cpf[], char password[])
{
    FILE *managersPtr;
    char currentCpf[12], currentName[strlen(name)], currentPassword[strlen(password)];    
    if ((managersPtr = fopen("gerentes.txt", "r"))==NULL)
    {
        printf("Não foi possivel acessar o Banco de gerentes!");
    }
    else
    {     
        while((fscanf(managersPtr,"%s|%s|%s",currentName,currentCpf,currentPassword))==3)
        {
            if(strcmp(cpf,currentCpf) == 0)
                {
                fclose(managersPtr);                
                return 0;
                }
        }
    }
    fclose(managersPtr);
    return 1;
}

void addGerente(char name[], char cpf[], char password[])
{
    FILE *managersPtr;
    if ((managersPtr = fopen("gerentes.txt", "a"))==NULL)
    {
        printf("Não foi possivel acessar o Banco de gerentes!");
    }
    else
    {   
        if (checkCPF(name,cpf,password) == false)
            printf("Esse Gerente já está cadastrado no sistema");
        else
            fprintf(managersPtr,"%s|%s|%s\n",name,cpf,password);
    }
    fclose(managersPtr);
}

int main()
{

    struct Manager g1;
    printf("Digite o Nome:\n");
    gets(g1.name);
    g1.name[strcspn(g1.name, "\n")] = '\0';

    printf("Digite o CPF:\n");
    gets(g1.cpf);
    g1.cpf[strcspn(g1.cpf, "\n")] = '\0';

    printf("Digite a senha:\n");
    gets(g1.password);

    addGerente(g1.name,g1.cpf ,g1.password);


    //createTable("gerente_dataBase.db");

    return 0;
}