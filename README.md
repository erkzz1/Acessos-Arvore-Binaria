# Caminhamento em Árvores Binárias em C

Este programa em C implementa uma estrutura de dados de árvore binária e fornece funcionalidades para criar, inserir e realizar caminhamentos (pré-ordem, pós-ordem e in-ordem) na árvore. O programa permite que os usuários insiram dez valores de ponto flutuante e, em seguida, escolham um método de caminhamento para visualizar os valores na árvore.

## Índice

- [Descrição](#descrição)
- [Funcionalidades](#funcionalidades)
- [Compilação e Execução](#compilação-e-execução)
- [Uso](#uso)
- [Funções Implementadas](#funções-implementadas)
- [Estrutura de Dados](#estrutura-de-dados)
- [Gerenciamento de Memória](#gerenciamento-de-memória)
- [Opções do Menu](#opções-do-menu)
- [Licença](#licença)

## Descrição

O programa é uma implementação básica de uma árvore binária em C, que suporta a inserção de valores e permite a travessia da árvore em diferentes ordens:
- Pré-ordem (visita raiz, esquerda, direita)
- Pós-ordem (visita esquerda, direita, raiz)
- In-ordem (visita esquerda, raiz, direita)

## Funcionalidades

- **Inserção de Nós**: Insere os nós na árvore de forma ordenada, garantindo que todos os valores menores ou iguais ao valor do nó atual sejam colocados à esquerda, e os maiores à direita.
- **Caminhamentos**: Permite que o usuário escolha entre diferentes métodos de caminhamento da árvore e visualize os valores de acordo com o método selecionado.
- **Gerenciamento de Memória**: Libera toda a memória alocada dinamicamente para a árvore antes de encerrar o programa.

## Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

### Compilação

Use o `gcc` para compilar o código:

```bash
gcc -o arvore_binaria arvore_binaria.c -lm
```

### Execução

Após a compilação, execute o programa:

```bash
./arvore_binaria
```

## Uso

1. **Iniciar o Programa**: Execute o programa após a compilação.
2. **Inserir Valores**: O programa solicitará que você insira 10 valores de ponto flutuante.
3. **Selecionar Caminhamento**: Após a inserção dos valores, o programa exibirá um menu para escolher o tipo de caminhamento desejado.
4. **Visualizar Resultado**: O resultado do caminhamento será exibido no console.

## Funções Implementadas

### `createNode`

Cria um novo nó na árvore com um valor específico.

```c
Node* createNode(float data);
```

- **data**: Valor a ser armazenado no nó.
- **Retorno**: Um ponteiro para o novo nó criado.

### `insertNode`

Insere um novo nó na árvore de forma ordenada.

```c
Node* insertNode(Node *root, float data);
```

- **root**: Ponteiro para a raiz da árvore.
- **data**: Valor a ser inserido.
- **Retorno**: Ponteiro para a raiz atualizada da árvore.

### `printValue`

Imprime o valor armazenado no nó, formatando-o como inteiro ou flutuante conforme necessário.

```c
void printValue(float value);
```

- **value**: Valor a ser impresso.

### `preOrder`

Realiza o caminhamento da árvore em pré-ordem.

```c
void preOrder(Node *root);
```

- **root**: Ponteiro para a raiz da árvore.

### `postOrder`

Realiza o caminhamento da árvore em pós-ordem.

```c
void postOrder(Node *root);
```

- **root**: Ponteiro para a raiz da árvore.

### `inOrder`

Realiza o caminhamento da árvore em in-ordem.

```c
void inOrder(Node *root);
```

- **root**: Ponteiro para a raiz da árvore.

### `freeTree`

Libera a memória alocada para todos os nós da árvore.

```c
void freeTree(Node *root);
```

- **root**: Ponteiro para a raiz da árvore.

### `menu`

Exibe o menu de opções e retorna a escolha do usuário.

```c
int menu();
```

- **Retorno**: A opção escolhida pelo usuário.

## Estrutura de Dados

### `Node`

Estrutura que representa um nó na árvore binária.

```c
typedef struct Node {
    float data;
    struct Node *left;
    struct Node *right;
} Node;
```

- **data**: Valor armazenado no nó (tipo `float`).
- **left**: Ponteiro para o nó à esquerda.
- **right**: Ponteiro para o nó à direita.

## Gerenciamento de Memória

O programa aloca memória dinamicamente para cada nó da árvore usando `malloc`. É essencial liberar essa memória para evitar vazamentos. A função `freeTree` é utilizada para liberar toda a memória alocada para a árvore antes de o programa encerrar.

## Opções do Menu

- **1 – Pré-ordem**: Caminhamento da árvore em pré-ordem.
- **2 – Pós-ordem**: Caminhamento da árvore em pós-ordem.
- **3 – In-ordem**: Caminhamento da árvore em in-ordem.
- **9 – Encerrar**: Finaliza o programa e libera a memória.

## Licença

Este projeto é de código aberto e está disponível sob a licença MIT. Sinta-se à vontade para usar, modificar e distribuir este código conforme necessário.

