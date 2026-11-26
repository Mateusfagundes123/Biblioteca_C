#include <stdio.h>
#include <stdlib.h>

typedef struct TLivro{
    char titulo[50];
    char autor[50]; 
    int ano_de_publicacao;
    int Codigo;
    int Status; 
    char email_usuario[50];
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

    printf("| email do usuário: ");
    scanf("%49s", livro.email_usuario);

    return livro;
}
