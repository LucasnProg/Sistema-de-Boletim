#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>

void createTable(const char *manager_database) {
    sqlite3 *dbPtr;
    char *error_msg = 0;

    int connect = sqlite3_open(manager_database, &dbPtr);
    if (connect) {
        fprintf(stderr, "Não é possível abrir o banco de dados: %s\n", sqlite3_errmsg(dbPtr));
        sqlite3_close(dbPtr);
        return;
    }
    char *sql = "CREATE TABLE IF NOT EXISTS gerentes ("
                    "cpf VARCHAR(11) PRIMARY KEY ,"
                    "nome TEXT NOT NULL,"
                    "password TEXT NOT NULL);";

    connect = sqlite3_exec(dbPtr, sql, 0, 0, &error_msg);
    if (connect != SQLITE_OK) {
        fprintf(stderr, "Erro ao criar a tabela: %s\n", error_msg);
        sqlite3_free(error_msg);
    } else {
        printf("Tabela 'gerentes' criada com sucesso!\n");
    }

    sqlite3_close(dbPtr);
}

void adiciona_Gerente(const char *database, const char *name, const char *cpf,const char *password) {
    sqlite3 *dbPtr;
    char *error_msg = 0;

    int connect = sqlite3_open(database, &dbPtr);
    if (connect) {
        fprintf(stderr, "Não é possível abrir o banco de dados: %s\n", sqlite3_errmsg(dbPtr));
        sqlite3_close(dbPtr);
        return;
    }

    const char *sql = "INSERT INTO gerentes (cpf, nome, password) VALUES (?, ?, ?);";
    sqlite3_stmt *stmtPtr;

    connect = sqlite3_prepare_v2(dbPtr, sql, -1, &stmtPtr, 0);
    if (connect == SQLITE_OK) {
        sqlite3_bind_text(stmtPtr, 1, cpf, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmtPtr, 1, name, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmtPtr, 3, password, -1, SQLITE_STATIC);

        connect = sqlite3_step(stmtPtr);
        /* CONFERE SE DEU CERTO
        if (connect == SQLITE_DONE) {
            printf("Pessoa adicionada com sucesso!\n");
        } else {
            fprintf(stderr, "Erro ao inserir pessoa: %s\n", sqlite3_errmsg(dbPtr));
        }
        sqlite3_finalize(stmtPtr);*/
    } else {
        fprintf(stderr, "Erro na consulta SQL: %s\n", sqlite3_errmsg(dbPtr));
    }

    sqlite3_close(dbPtr);
}

int main() {
    return 0;
}
