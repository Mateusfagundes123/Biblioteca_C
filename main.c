/* 

gcc -Wall -Wextra -g3 main.c Menu/menus.c -o programa.exe
.\programa.exe

*/

#include <stdio.h>
#include <locale.h>
#include <windows.h> 

#include "Menu/menus.h"

#include "Estruturas/Usuario.c"
#include "Estruturas/Livros.c"
#include "Estruturas/emprestimo.c"



int main(){
    SetConsoleOutputCP(CP_UTF8);  // para imprimir caracteres especiais

    Sent_Usuarios Gerente_usuarios;
    iniciar_lista_usuarios(&Gerente_usuarios);

    Sent_Livros Gerente_Livros;
    iniciar_lista_Livros(&Gerente_Livros);

    Sent_Emprestimo Gerente_emprestimo;
    iniciar_lista_emprestimos(&Gerente_emprestimo);


    int valor_do_menu; 
    do{
        menu_principal();
        scanf("%d",&valor_do_menu);
        
        switch (valor_do_menu){
            case 1:
                menu_cadastro();
                int valor_cadastro;
                scanf("%d", &valor_cadastro);

                if(valor_cadastro == 1){
                    Livro book;
                    book = CreateLivro(&Gerente_Livros);
                    InsertListLivros(&Gerente_Livros, book);
                    printf("Livro %s Cadastrado: Código %d \n\n", book.titulo, book.Codigo);
                    break;
                }
                else if(valor_cadastro == 2){
                    Usuario user;
                    user = CreateUsuario(&Gerente_usuarios);
                    InsertListUsers(&Gerente_usuarios , user);
                    break;
                }
                else if(valor_cadastro == 0){
                    break;
                }
                else{ 
                    printf("Informe um valor valido!");
                    break;
                } 
            case 2: 
                menu_consulta();
                int valor_consulta;
                scanf("%d", &valor_consulta);
                if(valor_consulta == 1){
                    consulta_livro();
                    int valor_consulta_livro;
                    scanf("%d", &valor_consulta_livro);
                    if(valor_consulta_livro == 1){
                        int valor_consulta_codigo;
                        printf("Qual o código do livro: "); 
                        scanf("%d", &valor_consulta_codigo);
                        consulta_livro_codigo(&Gerente_Livros, valor_consulta_codigo);
                    }
                    if(valor_consulta_livro == 2){
                        char autor_informado[100];
                        printf("Qual autor do livro: ");
                        scanf("%s", autor_informado);
                        consulta_livro_autor(&Gerente_Livros, autor_informado);
                    }
                }
                if(valor_consulta == 2){
                    consulta_usuario();
                    int valor_consulta_usuario;
                    scanf("%d", &valor_consulta_usuario);
                    if(valor_consulta_usuario == 1){
                        char valor_consulta_email[100];
                        printf("Qual o email do Usuario: "); 
                        scanf("%s", valor_consulta_email);
                        consulta_usuario_email(&Gerente_usuarios, valor_consulta_email);
                    }
                    if(valor_consulta_usuario == 2){
                        char nome_informado[100];
                        printf("Qual nome do usuario: ");
                        scanf("%s", nome_informado);
                        consulta_usuario_nome(&Gerente_usuarios, nome_informado);
                    }
                }
                break;
            case 3:
                menu_atualizacao();
                break;
            case 4: 
                menu_exclusao();
                int valor_exclusao;
                scanf("%d", &valor_exclusao);
                if(valor_consulta == 1){
                    exclusao_livro();
                    int valor_exclusao_livro;
                    scanf("%d", &valor_exclusao_livro);
                    if(valor_exclusao_livro == 1){
                        int valor_exclusao_codigo;
                        printf("Qual o código do livro: "); 
                        scanf("%d", &valor_exclusao_codigo);
                        exclusao_livro_codigo(&Gerente_Livros, valor_exclusao_codigo);
                    }
                }


                break; 
            case 5: {
                int codigo_livro;
                printf("Qual o código do livro a emprestar: ");
                if (scanf("%d", &codigo_livro) == 1) { // assim garante que a leitura deu certo. 
                    Create_e_Insert_emprestimo(codigo_livro, &Gerente_Livros, &Gerente_usuarios, &Gerente_emprestimo);
                } else {
                    int caractere;
                    printf("Código inválido.\n");
                    while ((caractere = getchar()) != '\n' && caractere != EOF) {
                    }
                }
                break; 
            }

            case 6: {
                int codigo_livro;
                printf("Qual o código do livro a devolver: ");
                if (scanf("%d", &codigo_livro) == 1) {
                    devolver_livro_emprestado(codigo_livro, &Gerente_Livros, &Gerente_emprestimo);
                } else {
                    printf("Código inválido.\n");
                }
                break;
            }

            case 99: 
                Listar_Lista_Usuarios(&Gerente_usuarios);
                break;
            case 98: 
                Listar_Lista_Livros(&Gerente_Livros);
                break;
            case 97: 
                Listar_Lista_Emprestimos(&Gerente_emprestimo);
                break;

        default:
            break;
        }

    } while(valor_do_menu != 0);


    return 0; 
}