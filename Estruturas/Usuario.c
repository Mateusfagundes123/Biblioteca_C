#include <stdio.h>

typedef struct TUsuario{
    char *email; 
    char *nome; 
}Usuario;


Usuario CreateUsuario(char *nome, char *email){
    Usuario usuario; 
    usuario.email = email; 
    usuario.nome = nome; 
    return usuario;
}