#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "funct.c"



int main()
{
    /*
    struct Manager g1;
    printf("Digite o Nome:\n");
    gets(g1.name);
    g1.name[strcspn(g1.name, "\n")] = '\0';

    printf("Digite o CPF:\n");
    gets(g1.cpf);
    g1.cpf[strcspn(g1.cpf, "\n")] = '\0';

    printf("Digite a senha:\n");
    gets(g1.password);*/

    addGerente("Lucas","12345678910" ,"teste123");
    addGerente("Luis","12345678910" ,"teste1234");


    //createTable("gerente_dataBase.db");

    return 0;
}