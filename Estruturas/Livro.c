#include <stdio.h>

typedef struct TLivro{
    char *titulo;
    char *autor; 
    char *ano_de_publicacao;
    char *Codigo;
    char *Status; 
    char *email_usuario;
}Livro;


Livro CreateLivro(char *titulo, char *autor, char *ano_de_publicacao, char *codigo, char *status, char *email_usuario){
    Livro livro; 
    livro.titulo = titulo; 
    livro.autor = autor; 
    livro.ano_de_publicacao = ano_de_publicacao; 
    livro.Codigo = codigo; 
    livro.Status = status; 
    livro.email_usuario = email_usuario; 
    return livro;
}