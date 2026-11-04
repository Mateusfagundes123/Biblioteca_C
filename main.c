/* 

gcc -Wall -Wextra -g3 main.c Menu/menus.c -o programa.exe
.\programa.exe

*/

#include <stdio.h>
#include <locale.h>
#include <windows.h> 

#include "Menu/menus.h"

#include "Estruturas/Usuario.c"
#include "Estruturas/Livro.c"


int main(){
    SetConsoleOutputCP(CP_UTF8);  // para imprimir caracteres especiais

    Sent_Usuarios Gerente_usuarios;
    iniciar_lista(&Gerente_usuarios);


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
                    break;
                }
                else if(valor_cadastro == 2){
                    Usuario user;
                    user = CreateUsuario();
                    InsertList(&Gerente_usuarios , user);
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
                break; 
        default:
            break;
        }

    } while(valor_do_menu != 0);


    return 0; 
}