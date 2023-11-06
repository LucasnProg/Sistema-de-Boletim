#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>


bool checkCPF(char cpf[])
{
    FILE *managersPtr;
    char currentCpf[12], currentName[100], currentPassword[50];    
    if ((managersPtr = fopen("gerentes.dat", "r"))==NULL)
    {
        printf("Não foi possivel acessar o Banco de gerentes!");
    }
    else
    {   
        while (!feof(managersPtr))
        {
            fscanf(managersPtr, "%s %s %s\n", &currentName, &currentCpf, &currentPassword);
            if(strcmp(cpf,currentCpf) == 0){
                fclose(managersPtr);
                return true;
            }
        }
        fclose(managersPtr);
        return false;
    }
}

void addGerente(char name[], char cpf[], char password[])
{
    FILE *managersPtr;
    if ((managersPtr = fopen("gerentes.dat", "a"))==NULL)
    {
        printf("Não foi possivel acessar o Banco de gerentes!\n");
    }
    else
    {   
        if (checkCPF(cpf) == true){
            printf("RELATORIO DE ERRO:\n");
            printf("    # Esse Gerente já está cadastrado no sistema.\n    FAÇA O LOGIN!\n");}
        else{
            fprintf(managersPtr,"%s %s %s\n",name,cpf,password);
            printf("Adicionado com sucesso!\n");}
    }
    fclose(managersPtr);
}

bool loginManager(char cpf[], char password[])
{
    FILE *managersPtr;
    char currentCpf[12], currentName[100], currentPassword[50];    
    if ((managersPtr = fopen("gerentes.dat", "r"))==NULL)
    {
        printf("Não foi possivel acessar o Banco de gerentes!");
    }
    else
    {   
        while (!feof(managersPtr))
        {
            fscanf(managersPtr, "%s %s %s\n", &currentName, &currentCpf, &currentPassword);
            if(strcmp(cpf,currentCpf) == 0 && strcmp(password,currentPassword) == 0){
                fclose(managersPtr);
                printf("LOGADO COM SUCESSO! \nBEM VINDO, %s\n", currentName);
                return true;
            }
            else if (strcmp(cpf,currentCpf) == 0 &&  strcmp(password,currentPassword) != 0)
            {
                printf("SENHA INCORRETA! TENTE NOVAMENTE\n");
                sleep(5);
                return false;
            }
            else if (strcmp(cpf,currentCpf) != 1 &&  strcmp(password,currentPassword) == 0)
            {

                return NULL;
            }
            

        }
        fclose(managersPtr);
    }
}

bool validatePassword(char password[])
{
    int has_digit = 0, has_upper =0, has_lower = 0, has_space = 0; 
    for( int i=0; i < strlen(password); i++)
    {
        if (isdigit(password[i])){
            has_digit++;
        }   
        else if(isupper(password[i])){
            has_upper++;    
        }  
        else if(islower(password[i])){
            has_lower++;
        }
        else if(isspace(password[i])){
            has_space++;
        } 
    }
    if(strlen(password)< 8){
            printf("Senha Inválida!\nTamanho mínimo da senha: 8\n");
            return false;
    }   else if(has_digit == 0){
        printf("Senha Inválida!\nA senha não possui digitos\n");
        return false;
    }   else if(has_upper == 0){
        printf("Senha Inválida!\nA senha não possui caracteres maiusculos\n");
        return false;
    }   else if(has_lower == 0){
        printf("Senha Inválida!\nA senha não possui caracteres minusculos\n");
        return false;
    }   else if(has_space != 0){
        printf("Senha Inválida!\nA senha não pode possuir espaços\n");
        return false;
    }   else
            printf("Senha válida\n");
    return true;
}

bool validateCpf(char cpf[])
{
    setlocale(LC_ALL, "");
    int notDigit = 0;
    for( int i=0; i<11; i++){
        if(!isdigit(cpf[i])){
            notDigit ++;
        }
    }
    if(strlen(cpf) != 11){
        printf("DIGITE UM CPF VÁLIDO, COM 11 DIGITOS!");
        return false;
    } else if( notDigit != 0){
        printf("DIGITE UM CPF VÁLIDO, APENAS NÚMEROS!");
        return false;
    }
    printf("DEU CERTO, OTARIO!\n");
    return true;
}