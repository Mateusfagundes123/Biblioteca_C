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


int main(){
    SetConsoleOutputCP(CP_UTF8);  // para imprimir caracteres especiais

    Sent_Usuarios Gerente_usuarios;
    iniciar_lista_usuarios(&Gerente_usuarios);

    Sent_Livros Gerente_Livros;
    iniciar_lista_Livros(&Gerente_Livros);


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



                break;
            case 3:
                menu_atualizacao();
                break;
            case 4: 
                menu_exclusao();
                break; 
            case 5:
                Listar_Lista_Usuarios(&Gerente_usuarios);
                break; 
            case 6:
                Listar_Lista_Livros(&Gerente_Livros);
                break; 
        default:
            break;
        }

    } while(valor_do_menu != 0);


    return 0; 
}