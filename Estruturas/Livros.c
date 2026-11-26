#include <stdio.h>
#include <stdlib.h>

typedef struct TLivro{
    char titulo[50];
    char autor[50]; 
    char ano_de_publicacao[50];
    char Codigo[50];
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
    for(List_Livros *aux = s->First; aux != NULL; aux = aux->Next){
        printf("------- Usuarios -------\nTítulo: %s \nAutor: %s \n", aux->info.titulo, aux->info.autor);
    }

}



Livro CreateLivro(Sent_Livros *s){
    Livro livro; 
    char titulo[100];
    printf("-- Cadastro de Livro --\n");
    printf("| Titulo: ");
    scanf("%s", livro.titulo);

    printf("| Autor: ");
    scanf("%s", livro.autor);

    printf("| Ano de publicação: ");
    scanf("%s", livro.ano_de_publicacao);


    printf("| Código: ");
    scanf("%s" ,livro.Codigo);

    livro.Status = 0;

    printf("| email do usuário: ");
    scanf("%s" ,livro.email_usuario);

    return livro;
}
