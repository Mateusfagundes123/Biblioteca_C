#include <stdio.h>

typedef struct TUsuario{
    char email[100]; 
    char nome[100]; 
}Usuario;

typedef struct TList_Usuarios{
    Usuario info; 
    struct TList_Usuarios *Next;
}List_Usuarios;

typedef struct SSent{
    List_Usuarios *First;
    int qtd_Usuarios;
}Sent_Usuarios;

void iniciar_lista(Sent_Usuarios *s){
    s->First = NULL; 
    s->qtd_Usuarios = 0;
}

void InsertList(Sent_Usuarios *s, Usuario usuario){
    List_Usuarios *ls; 
    ls = (List_Usuarios *)malloc(sizeof(List_Usuarios));
    ls->info = usuario;
    ls->Next = NULL;

    if(s->First == NULL){
        s->First = ls; 
        s->qtd_Usuarios++;
        return;
    }

    List_Usuarios *aux = s->First;
    while(aux->Next != NULL){
        aux = aux->Next;
    } 

    ls->Next = aux->Next;
    aux->Next = ls; 
    s->qtd_Usuarios++;
}

void Listar_Lista_Usuarios(Sent_Usuarios *s){
    if(s->First == NULL){
        printf("Lista Vazia! ");
        return;
    }
    for(List_Usuarios *aux = s->First; aux != NULL; aux = aux->Next){
        printf("------- Usuarios -------\nEmail: %s \nNome: %s \n", aux->info.email, aux->info.nome);
    }

}


Usuario CreateUsuario(Sent_Usuarios *s){
    Usuario usuario; 
    char email[100];
    printf("-- Cadastro de Usuario --\n");
    while (1) {
        printf("| Email: ");
        if (scanf("%s", usuario.email) != 1){
            return usuario;
        }

        List_Usuarios *aux;
        for (aux = s->First; aux != NULL; aux = aux->Next) {
            if (strcmp(aux->info.email, usuario.email) == 0) {
                break;
            }
        }

        if (aux == NULL) {
            break;
        }

        printf("Email ja cadastrado. Digite outro.\n");
    }

    printf("\n| Nome: ");
    scanf("%s", usuario.nome);
    return usuario;
}
