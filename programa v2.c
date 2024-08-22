#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defini��o da estrutura do n� da �rvore bin�ria
typedef struct Node {
    float data;
    struct Node *left;
    struct Node *right;
} Node;

// Fun��o para criar um novo n� com aloca��o din�mica de mem�ria
Node* createNode(float data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na aloca��o de mem�ria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir um n� na �rvore de forma ordenada
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

// Fun��o para imprimir o valor
void printValue(float value) {
    if (floor(value) == value) {
        printf("%.0f ", value); // Imprime como inteiro
    } else {
        printf("%.2f ", value); // Imprime com duas casas decimais
    }
}

// Fun��o para realizar o caminhamento em Pr�-ordem
void preOrder(Node *root) {
    if (root != NULL) {
        printValue(root->data); // Acessa a raiz
        preOrder(root->left);   // Sub�rvore esquerda
        preOrder(root->right);  // Sub�rvore direita
    }
}

// Fun��o para realizar o caminhamento em P�s-ordem
void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);   // Sub�rvore esquerda
        postOrder(root->right);  // Sub�rvore direita
        printValue(root->data);  // Acessa a raiz
    }
}

// Fun��o para realizar o caminhamento em Intraordem
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);     // Sub�rvore esquerda
        printValue(root->data);  // Acessa a raiz
        inOrder(root->right);    // Sub�rvore direita
    }
}

// Fun��o para liberar a mem�ria alocada para a �rvore
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Fun��o para exibir o menu e obter a escolha do usu�rio
int menu() {
    int choice;
    printf("\nMenu de Op��es\n");
    printf("1 ? Pr�-ordem\n");
    printf("2 ? P�s-ordem\n");
    printf("3 ? Intraordem\n");
    printf("9 ? Encerrar a aplica��o\n");
    printf("Escolha uma op��o: ");
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
                printf("Entrada inv�lida. Por favor, insira um n�mero.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }
        root = insertNode(root, values[i]);
    }

    // Exibi��o do menu e execu��o das op��es escolhidas
    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Caminhamento Pr�-ordem: ");
                preOrder(root);
                printf("\n");
                break;
            case 2:
                printf("Caminhamento P�s-ordem: ");
                postOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Caminhamento Intraordem: ");
                inOrder(root);
                printf("\n");
                break;
            case 9:
                printf("Encerrando a aplica��o...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (choice != 9);

    // Libera a mem�ria alocada para a �rvore
    freeTree(root);
    
    return 0;
}
