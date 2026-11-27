#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas/Usuario.c"
#include "Estruturas/Livros.c"

// estrutura ----------------------------------------------

typedef struct TEmprestimo{
    int codigoLivro;
    char emailUsuario[100];
}Emprestimo;


typedef struct TList_Emprestimo{
    Emprestimo info; 
    struct TList_Emprestimo *Next;
}List_Emprestimo;

typedef struct SSent_Emprestimos{
    List_Emprestimo *First;
    int qtd_Emprestimos;
}Sent_Emprestimo;

void iniciar_lista_emprestimos(Sent_Emprestimo *s){
    s->First = NULL; 
    s->qtd_Emprestimos = 0;
}


int Create_e_Insert_emprestimo(int codigoLivro, Sent_Livros *livros, Sent_Usuarios *usuarios, Sent_Emprestimo *emprestimos){
    List_Livros *livro = livros->First;
    while (livro != NULL && livro->info.Codigo != codigoLivro) {
        livro = livro->Next;
    }

    if (livro == NULL) {
        printf("Livro não encontrado.\n");
        return 0;
    }

    if (livro->info.Status != 0) {
        printf("Livro indisponível.\n");
        return 0;
    }

    char email[100];
    printf("Email do usuário: ");
    scanf("%s", email);
   

    List_Usuarios *usuario = usuarios->First;
    while (usuario != NULL && strcmp(usuario->info.email, email) != 0) {
        usuario = usuario->Next;
    }

    if (usuario == NULL) {
        printf("Usuário não encontrado.\n");
        return 0;
    }

    List_Emprestimo *novo = malloc(sizeof *novo);
    
    novo->info.codigoLivro = codigoLivro;
    strcpy(novo->info.emailUsuario, email);
    novo->Next = emprestimos->First;
    emprestimos->First = novo;
    emprestimos->qtd_Emprestimos++;

    livro->info.Status = 1;
    strcpy(livro->info.email_usuario, email);

    printf("Empréstimo registrado para o livro %d.\n", codigoLivro);
    return 1;
}