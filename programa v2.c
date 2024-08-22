#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição da estrutura do nó da árvore binária
typedef struct Node {
    float data;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó com alocação dinâmica de memória
Node* createNode(float data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore de forma ordenada
Node* insertNode(Node *root, float data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Função para imprimir o valor
void printValue(float value) {
    if (floor(value) == value) {
        printf("%.0f ", value); // Imprime como inteiro
    } else {
        printf("%.2f ", value); // Imprime com duas casas decimais
    }
}

// Função para realizar o caminhamento em Pré-ordem
void preOrder(Node *root) {
    if (root != NULL) {
        printValue(root->data); // Acessa a raiz
        preOrder(root->left);   // Subárvore esquerda
        preOrder(root->right);  // Subárvore direita
    }
}

// Função para realizar o caminhamento em Pós-ordem
void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);   // Subárvore esquerda
        postOrder(root->right);  // Subárvore direita
        printValue(root->data);  // Acessa a raiz
    }
}

// Função para realizar o caminhamento em Intraordem
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);     // Subárvore esquerda
        printValue(root->data);  // Acessa a raiz
        inOrder(root->right);    // Subárvore direita
    }
}

// Função para liberar a memória alocada para a árvore
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função para exibir o menu e obter a escolha do usuário
int menu() {
    int choice;
    printf("\nMenu de Opções\n");
    printf("1 ? Pré-ordem\n");
    printf("2 ? Pós-ordem\n");
    printf("3 ? Intraordem\n");
    printf("9 ? Encerrar a aplicação\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Node *root = NULL;
    float values[10];
    int choice;
    
    // Entrada dos valores
    printf("Digite 10 valores \n");
    for (int i = 0; i < 10; i++) {
        while (1) {
            printf("Valor %d: ", i + 1);
            if (scanf("%f", &values[i]) == 1) {
                break;
            } else {
                printf("Entrada inválida. Por favor, insira um número.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }
        root = insertNode(root, values[i]);
    }

    // Exibição do menu e execução das opções escolhidas
    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Caminhamento Pré-ordem: ");
                preOrder(root);
                printf("\n");
                break;
            case 2:
                printf("Caminhamento Pós-ordem: ");
                postOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Caminhamento Intraordem: ");
                inOrder(root);
                printf("\n");
                break;
            case 9:
                printf("Encerrando a aplicação...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 9);

    // Libera a memória alocada para a árvore
    freeTree(root);
    
    return 0;
}
