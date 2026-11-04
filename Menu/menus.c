#include <stdio.h>
#include "menus.h"

void menu_principal(){
    printf("--- Biblioteca ---\n");
    printf("| 1 - Cadastro    |\n");
    printf("| 2 - Consulta    |\n");
    printf("| 3 - Atualização |\n");
    printf("| 4 - Exclusão    |\n");
    printf("| 5 - Empréstimo  |\n");
    printf("| 6 - Devolução   |\n");
    printf("| 0 - Sair        |\n");
    printf("-------------------\n");
}

void menu_cadastro(){
    printf("--- cadastro ---\n");
    printf("| 1 - Livros   |\n");
    printf("| 2 - Usuarios |\n");
    printf("| 0 - Voltar   |\n");
    printf("----------------\n");
}

void menu_consulta(){
    printf("---- consulta ----\n");
    printf("| 1 - Livro      |\n");
    printf("| 2 - Usuario    |\n");
    printf("| 3 - Empréstimo |\n");
    printf("| 0 - Voltar     |\n");
    printf("-------------------\n");
}

void menu_atualizacao(){
    printf("-- atualizar ---\n");
    printf("| 1 - Livro    |\n");
    printf("| 2 - Usuario  |\n");
    printf("| 0 - Voltar   |\n");
    printf("----------------\n");
}

void menu_exclusao(){
    printf("--  exclusão  --\n");
    printf("| 1 - Livro    |\n");
    printf("| 2 - Usuario  |\n");
    printf("| 0 - Voltar   |\n");
    printf("----------------\n");
}

