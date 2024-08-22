# Caminhamento em Árvores Binárias em C

Este programa em C implementa uma estrutura de dados de árvore binária e fornece funcionalidades para criação, inserção e caminhamento (ou travessia) da árvore. O programa permite que os usuários insiram dez valores de ponto flutuante na árvore e, em seguida, realizem diferentes tipos de caminhamentos (pré-ordem, pós-ordem e in-ordem).

## Índice
- [Visão Geral do Projeto](#visão-geral-do-projeto)
- [Funcionalidades](#funcionalidades)
- [Instalação](#instalação)
- [Uso](#uso)
- [Funções](#funções)
  - [createNode](#createnode)
  - [insertNode](#insertnode)
  - [printValue](#printvalue)
  - [preOrder](#preorder)
  - [postOrder](#postorder)
  - [inOrder](#inorder)
  - [freeTree](#freetree)
  - [menu](#menu)
- [Métodos de Caminhamento](#métodos-de-caminhamento)
- [Gerenciamento de Memória](#gerenciamento-de-memória)
- [Opções do Menu](#opções-do-menu)
- [Licença](#licença)

## Visão Geral do Projeto

Este projeto envolve a criação de uma simples estrutura de árvore binária em C, permitindo que os usuários caminhem pela árvore utilizando três métodos diferentes:
- Caminhamento em pré-ordem
- Caminhamento em pós-ordem
- Caminhamento in-ordem

Os usuários podem inserir 10 números de ponto flutuante, que são então inseridos na árvore. O programa oferece uma interface de menu onde os usuários podem selecionar qual método de caminhamento desejam executar. O programa também garante o gerenciamento adequado da memória, liberando a memória alocada antes de encerrar.

## Funcionalidades

- Alocação dinâmica de memória para os nós.
- Inserção de nós de forma ordenada com base na entrada do usuário.
- Caminhamento da árvore em pré-ordem, pós-ordem e in-ordem.
- Um menu amigável para selecionar as opções de caminhamento.
- Tratamento adequado de erros de alocação de memória.
- Validação da entrada do usuário para garantir o tipo de dado correto.
- Gerenciamento eficiente da memória, liberando toda a memória alocada.

## Instalação

Para compilar e executar este programa, você precisará de um compilador C. Se você estiver em um sistema Linux ou macOS, pode usar o `gcc`, que geralmente vem pré-instalado. No Windows, pode ser necessário instalar um compilador C como o MinGW.

### Compilando o Programa

```bash
gcc -o arvore_binaria arvore_binaria.c -lm
