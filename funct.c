#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
        while((fscanf(managersPtr,"%99s|%11s|%49s",currentName,currentCpf,currentPassword))==3)
        {
            if(strcmp(cpf,currentCpf) == 0)
                {
                fclose(managersPtr);                
                return true;
                }
        }
    }
    fclose(managersPtr);
    return false;
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
        if (checkCPF(name,cpf,password) == true)
            printf("Esse Gerente já está cadastrado no sistema");
        else
            fprintf(managersPtr,"%s|%s|%s\n",name,cpf,password);
            printf("Adicionado com sucesso!");
    }
    fclose(managersPtr);
}