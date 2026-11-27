#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura ----------------------------------------------

typedef struct TLivro{
    char titulo[50];
    char autor[50]; 
    int ano_de_publicacao;
    int Codigo;
    int Status; 
    char email_usuario[100];
}Livro;

typedef struct TList_Livros{
    Livro info; 
    struct TList_Livros *Next;
}List_Livros;

typedef struct SSent_Livros{
    List_Livros *First;
    int qtd_Livros;
}Sent_Livros;

void iniciar_lista_Livros(Sent_Livros *s){
    s->First = NULL; 
    s->qtd_Livros = 0;
}

// CRUD --------------------------------

// create
int gerador_id_livro(Sent_Livros *s){
    int id;
    if(s->First == NULL)
        return 1; 
    List_Livros *aux = s->First; 
    while(aux->Next != NULL)
        aux = aux->Next;
    id = aux->info.Codigo + 1;
    return id;
}

Livro CreateLivro(Sent_Livros *s){
    Livro livro; 
    printf("-- Cadastro de Livro --\n");
    printf("| Titulo: ");
    scanf("%49s", livro.titulo);

    printf("| Autor: ");
    scanf("%49s", livro.autor);

    printf("| Ano de publicação: ");
    scanf("%d", &livro.ano_de_publicacao);

    livro.Codigo = gerador_id_livro(s);
    livro.Status = 0;

    livro.email_usuario[0] = '\0';

    return livro;
}

// read ---------------------------------------------------

void Listar_Lista_Livros(Sent_Livros *s){
    if(s->First == NULL){
        printf("Lista Vazia! ");
        return;
    }
    printf("------- Livros -------\n");

    for (List_Livros *aux = s->First; aux != NULL; aux = aux->Next) {
        printf("Título: %s\nAutor: %s\nAno de publicação: %d\nCódigo: %d\nStatus: %d\nE-mail do usuário: %s\n\n", aux->info.titulo, aux->info.autor, aux->info.ano_de_publicacao, aux->info.Codigo, aux->info.Status, aux->info.email_usuario);
    }
}

void consulta_livro_codigo(Sent_Livros *s, int codigo){
    if(s->First == NULL){
        printf("Lista Vazia! ");
        return;
    }
    for (List_Livros *aux = s->First; aux != NULL; aux = aux->Next) {
        if(aux->info.Codigo == codigo){
            printf("Título: %s\nAutor: %s\nAno de publicação: %d\nCódigo: %d\nStatus: %d\nE-mail do usuário: %s\n\n", aux->info.titulo, aux->info.autor, aux->info.ano_de_publicacao, aux->info.Codigo, aux->info.Status, aux->info.email_usuario);
            return;
        }
    }
    printf("Livro não encontrado");
    return;
}

void consulta_livro_autor(Sent_Livros *s, char *autor_informado){
    int cont = 0;
    if(s->First == NULL){
        printf("Lista Vazia! ");
        return;
    }
    List_Livros *aux = s->First;
    while(aux != NULL){
        if (strcmp(aux->info.autor, autor_informado) == 0) { // usado ia para entender como funciona o strcmp
            printf("Título: %s\nAutor: %s\nAno de publicação: %d\nCódigo: %d\nStatus: %d\nE-mail do usuário: %s\n\n", aux->info.titulo, aux->info.autor, aux->info.ano_de_publicacao, aux->info.Codigo, aux->info.Status, aux->info.email_usuario);
            cont++;
        }
        aux = aux->Next;
    }
    if(cont == 0)
        printf("Livro não encontrado");
    return;
}



// delete  --------------------------------------------


void exclusao_livro_codigo(Sent_Livros *s, int codigo) {
    List_Livros *anterior = NULL;
    List_Livros *atual = s->First;

    while (atual != NULL && atual->info.Codigo != codigo) {
        anterior = atual;
        atual = atual->Next;
    }

    if (atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (atual->info.Status != 0) {
        printf("Lvro está emprestado.\n");
        return;
    }

    if (anterior == NULL) {
        s->First = atual->Next;     
    } else {
        anterior->Next = atual->Next; 
    }

    free(atual);
    s->qtd_Livros--;
    printf("Livro excluído.\n");
}







void InsertListLivros(Sent_Livros *s, Livro livro){
    List_Livros *ls; 
    ls = (List_Livros *)malloc(sizeof(List_Livros));
    ls->info = livro;
    ls->Next = NULL;

    if(s->First == NULL){
        s->First = ls; 
        s->qtd_Livros++;
        return;
    }

    List_Livros *aux = s->First;
    while(aux->Next != NULL){
        aux = aux->Next;
    } 

    ls->Next = aux->Next;
    aux->Next = ls; 
    s->qtd_Livros++;
}
