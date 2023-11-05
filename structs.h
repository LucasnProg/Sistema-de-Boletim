#ifndef STRUCTS_H
#define STRUCTS_H

struct  Manager
{
    char name[100];
    char cpf[12];
    char password[50];
} ;

struct  Cliente
{
    char name[100];
    char cpf[12];
    char email[100];
    char password[100];
} ;

#endif