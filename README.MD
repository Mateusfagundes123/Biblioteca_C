# Sistema de Controle de Biblioteca

Trabalho final do CCR **Estrutura de Dados I**, referente ao semestre **2026-2**.

## Sobre o projeto

Desenvolvimento de um sistema de controle de biblioteca em C, executado pelo terminal, para cadastrar e gerenciar livros, usuários, empréstimos e devoluções.

O projeto tem como objetivo aplicar os conceitos de estruturas de dados, ponteiros, alocação dinâmica de memória e organização do código em funções.

## Funcionalidades previstas

- Cadastro de livros com código único, título, autor e ano de publicação.
- Cadastro de usuários com email único e nome.
- Consulta de livros por código ou autor.
- Consulta de usuários por email ou nome.
- Consulta dos livros emprestados a um usuário.
- Atualização dos dados de livros e usuários.
- Exclusão de livros e usuários.
- Empréstimo de livros disponíveis para usuários cadastrados.
- Devolução de livros, atualizando sua disponibilidade.
- Liberação da memória alocada ao encerrar o programa.

## Regras do sistema

- Não permitir livros com códigos duplicados.
- Não permitir usuários com emails duplicados.
- Cadastrar novos livros com status disponível.
- Manter os livros ordenados por código ou título.
- Registrar o email do usuário responsável pelo empréstimo.
- Na devolução, marcar o livro como disponível e limpar o email associado.

## Estruturas de dados

O sistema deverá utilizar alocação dinâmica de memória. A escolha das
estruturas será feita conforme as necessidades de cada funcionalidade,
considerando os conceitos estudados na disciplina:

- Lista simplesmente encadeada.
- Lista duplamente encadeada.
- Fila.
- Pilha.
- Árvore binária de busca.

As estruturas efetivamente utilizadas e suas finalidades serão
documentadas ao longo do desenvolvimento.


## Autor

- Mateus Tomczak Fagundes
