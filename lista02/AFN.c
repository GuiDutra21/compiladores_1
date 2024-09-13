// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct transicoes {
//     int tam;
//     int *destinos;
// } transicoes;

// typedef struct estado {
//     transicoes *transicoes;
//     char tipo;
// } estado;

// typedef struct fila {
//     int *vetor;
//     int i, f, tam;
// } fila;

// // Lembrando que f sempre representa a primeira posicao livre
// void inserir(fila *fila, int estado) {
//     // Se estiver cheia dobra o tamanho
//     if (fila->f == fila->tam) {
//         fila->vetor = realloc(fila->vetor, 2 * fila->tam * sizeof(int));
//         fila->tam = 2 * fila->tam;
//     }
//     fila->vetor[fila->f] = estado;
//     fila->f++;
// }

// int remover(fila *fila) {
//     return fila->vetor[fila->i++];
// }

// void swap(char *str1, char *str2) {
//     char aux = *str1;
//     *str1 = *str2;
//     *str2 = aux;
// }

// int partition(char *vetSimbolos, int l, int r) {
//     int i = l, j = r - 1;

//     while (i < j) {
//         while (vetSimbolos[i] < vetSimbolos[r]) i++;
//         while (i < j && vetSimbolos[r] < vetSimbolos[j]) j--;
//         if (i < j) swap(&vetSimbolos[i], &vetSimbolos[j]);
//     }

//     swap(&vetSimbolos[i], &vetSimbolos[r]);

//     return i;
// }

// void quickSort(char *vetSimbolos, int l, int r) {
//     if (l < r) {
//         // Mediana de três
//         int meio = (r + l) / 2;
//         if (vetSimbolos[r] < vetSimbolos[meio]) swap(&vetSimbolos[r], &vetSimbolos[meio]);
//         if (vetSimbolos[meio] < vetSimbolos[l]) swap(&vetSimbolos[l], &vetSimbolos[meio]);
//         if (vetSimbolos[r] < vetSimbolos[meio]) swap(&vetSimbolos[meio], &vetSimbolos[r]);

//         int pivo = partition(vetSimbolos, l, r);

//         quickSort(vetSimbolos, l, pivo - 1);
//         quickSort(vetSimbolos, pivo + 1, r);
//     }
// }

// int busca(char *vetSimbolos, char simbolo, int l, int r) {
//     if (l <= r) {
//         int meio = l + (r - l) / 2;
//         if (vetSimbolos[meio] == simbolo) {
//             return meio;
//         } else if (vetSimbolos[meio] > simbolo) {
//             return busca(vetSimbolos, simbolo, l, meio - 1);
//         } else {
//             return busca(vetSimbolos, simbolo, meio + 1, r);
//         }
//     }
//     return -1;
// }

// void printEstados(estado *vetEstados, int numEstados, int numSimbolos, char *vetSimbolos) {
//     for (int i = 0; i < numEstados; i++) {
//         printf("Estado %d, Tipo: %c\n", i, vetEstados[i].tipo);
//         for (int j = 0; j < numSimbolos; j++) {
//             printf("  Símbolo: %c, Transições: ", vetSimbolos[j]);
//             if (vetEstados[i].transicoes[j].tam > 0) {
//                 for (int k = 0; k < vetEstados[i].transicoes[j].tam; k++) {
//                     printf("%d ", vetEstados[i].transicoes[j].destinos[k]);
//                 }
//             } else {
//                 printf("Nenhuma");
//             }
//             printf("\n");
//         }
//     }
// }

// void verifica(estado *vetEstados, int numSimbolos, char *vetSimbolos, fila *fila) {
//     char caracter;
//     int qtdRemove, indice, estadoAtual;
//     while (scanf(" %c", &caracter) != EOF) {
//         qtdRemove = fila->f - fila->i;
//         indice = busca(vetSimbolos, caracter, 0, numSimbolos - 1);
//         for (int i = 0; i < qtdRemove; i++) {
//             estadoAtual = remover(fila);
//             int qtdDestinos = vetEstados[estadoAtual].transicoes[indice].tam;
//             for (int j = 0; j < qtdDestinos; j++) {
//                 inserir(fila, vetEstados[estadoAtual].transicoes[indice].destinos[j]);
//             }
//         }
//     }
// }

// int main() {
//     int numEstados, numSimbolos, i, j;
//     scanf("%d %d", &numEstados, &numSimbolos);

//     // Cria o vetor de estados e já aloca dinamicamente os vetores dentro de cada estado
//     estado vetEstados[numEstados];
//     for (i = 0; i < numEstados; i++) {
//         vetEstados[i].transicoes = calloc(numSimbolos, sizeof(transicoes));
//         vetEstados[i].tipo = 'i';
//     }

//     // Aloca memoria para o vetor de símbolos
//     char *vetSimbolos = malloc(numSimbolos * sizeof(char));

//     // Lê os símbolos
//     for (i = 0; i < numSimbolos; i++) {
//         scanf(" %c", &vetSimbolos[i]);
//     }

//     // Ordena a tela de símbolos
//     quickSort(vetSimbolos, 0, numSimbolos - 1);

//     // Adiciona as transições para cada estado
//     int totalTransicoes = numEstados * numSimbolos;
//     int id, qtdTransicoes, estadoDestino;
//     char simbolo;
//     for (i = 0; i < totalTransicoes; i++) {
//         scanf("%d %c %d", &id, &simbolo, &qtdTransicoes);
//         int posicao = busca(vetSimbolos, simbolo, 0, numSimbolos - 1);

//         if (qtdTransicoes > 0) {
//             vetEstados[id].transicoes[posicao].destinos = malloc(qtdTransicoes * sizeof(int));
//             vetEstados[id].transicoes[posicao].tam = qtdTransicoes;
//             for (j = 0; j < qtdTransicoes; j++) {
//                 scanf("%d", &estadoDestino);
//                 vetEstados[id].transicoes[posicao].destinos[j] = estadoDestino;
//             }
//         } else {
//             vetEstados[id].transicoes[posicao].destinos = NULL;
//             vetEstados[id].transicoes[posicao].tam = 0;
//         }
//     }

//     // Le o estado que comeca
//     int estadoAtual;
//     scanf("%d", &estadoAtual);

//     // Reconhece os estados finais
//     int numFinais, finais;
//     scanf("%d", &numFinais);
//     for (i = 0; i < numFinais; i++) {
//         scanf("%d", &finais);
//         vetEstados[finais].tipo = 'f';
//     }

//     // Le a palavra
//     fila fila;
//     fila.vetor = malloc(1000 * sizeof(int));
//     fila.i = 0;
//     fila.f = 1;
//     fila.vetor[0] = estadoAtual;
//     fila.tam = 1000;
//     verifica(vetEstados, numSimbolos, vetSimbolos, &fila);

//     // Verifica se alcançou algum estado final
//     for (i = fila.i; i < fila.f; i++) {
//         if (vetEstados[fila.vetor[i]].tipo == 'f') {
//             printf("Aceito\n");
//             return 0;
//         }
//     }

//        printf("Rejeito\n");

//     for (i = 0; i < numEstados; i++) {
//         for (j = 0; j < numSimbolos; j++) {
//             free(vetEstados[i].transicoes[j].destinos);
//         }
//         free(vetEstados[i].transicoes);
//     }
//     free(vetSimbolos);
//     free(fila.vetor);

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct transicoes
{
    int tam;
    int *destinos;
}transicoes;

typedef struct estado
{
    transicoes *transicoes;
    char tipo;
} estado;

typedef struct fila
{
    int *vetor;
    int i,f,tam;
}fila;

// Lembrando que f sempre representa a primeira posicao livre
void inserir(fila *fila, int estado)
{   
    // Se estiver cheia dobra o tamanho
    if(fila -> f == fila -> tam)
    {
        fila ->vetor = realloc(fila -> vetor, 2*fila -> tam);
        fila->tam = 2*fila->tam;
    }
    fila -> vetor[fila -> f] = estado;
    fila -> f++;
}

int remover(fila *fila)
{
    return fila -> vetor[fila -> i++]; 
}

void swap(char str1, char str2)
{
    char aux = str1;
    str1 = str2;
    str2 = aux;
}

int partition(char *vetSimbolos, int l, int r) {
    
    int i = l, j = r - 1;

    while (i < j)
    {
        while (vetSimbolos[i] < vetSimbolos[j]) i++;
        while (i < j && vetSimbolos[r] < vetSimbolos[j]) j--;
        if (i < j) swap(vetSimbolos[i], vetSimbolos[j]);
    }

    swap(vetSimbolos[i], vetSimbolos[r]);

    return i;
}

void quickSort(char *vetSimbolos, int l, int r)
{
    if (l < r) {

        // Mediana de três
        int meio = (r + l) / 2;
        if (vetSimbolos[r] < vetSimbolos[meio]) swap(vetSimbolos[r], vetSimbolos[meio]);
        if (vetSimbolos[meio] < vetSimbolos[l]) swap(vetSimbolos[l], vetSimbolos[meio]);
        if (vetSimbolos[meio] < vetSimbolos[r]) swap(vetSimbolos[meio], vetSimbolos[r]);

        int pivo = partition(vetSimbolos, l, r);

        quickSort(vetSimbolos, l, pivo - 1);
        quickSort(vetSimbolos, pivo + 1, r);
    }
}

int busca(char *vetSimbolos, char simbolo, int l, int r)
{   
    if(l <= r)
    {
        int meio = l + (r - l)/2;
        if(vetSimbolos[meio] == simbolo)
        {
            return meio;
        }
        else if (vetSimbolos[meio] > simbolo)
        {
            return busca(vetSimbolos,simbolo,l, meio - 1);
        }
        else
            return busca(vetSimbolos,simbolo,meio + 1, r);
    }
    return -1;
}


void printEstados(estado *vetEstados, int numEstados, int numSimbolos, char *vetSimbolos) {
    for (int i = 0; i < numEstados; i++) {
        printf("Estado %d, Tipo: %c\n", i, vetEstados[i].tipo);
        for (int j = 0; j < numSimbolos; j++) {
            printf("  Símbolo: %c, Transições: ", vetSimbolos[j]);
            if (vetEstados[i].transicoes[j].tam > 0) {
                for (int k = 0; k < vetEstados[i].transicoes[j].tam; k++) {
                    printf("%d ", vetEstados[i].transicoes[j].destinos[k]);
                }
            } else {
                printf("Nenhuma");
            }
            printf("\n");
        }
    }
}

void verifica(estado *vetEstados, int numSimbolos, char *vetSimbolos, fila *fila)
{   
    char caracter;
    int qtdRemove, indice, estadoAtual;
    while(scanf(" %c",&caracter) != EOF)
    {   
        qtdRemove = fila->f - fila->i;
        indice = busca(vetSimbolos,caracter,0,numSimbolos - 1);
        for(int i = 0; i < qtdRemove; i++)
        {   
            estadoAtual = remover(fila);
            int qtdDestinos = vetEstados[estadoAtual].transicoes[indice].tam;
            for(int j = 0; j < qtdDestinos; j++)
            {   
                inserir(fila, vetEstados[estadoAtual].transicoes[indice].destinos[j]);
            }
        }
    }
}

int main()
{
    int numEstados, numSimbolos, i,j;
    scanf("%d %d", &numEstados,&numSimbolos);

    // Cria o vetor de estados e já aloca dinamicamente os vetores dentro de cada estado
    estado vetEstados[numEstados];
    for (i = 0; i < numEstados; i++)
    {   
        vetEstados[i].transicoes = calloc(numSimbolos, sizeof(transicoes));
        vetEstados[i].tipo = 'i';
    }

    char caracter;
    // Aloca memoria para o vetor de símbolos
    char *vetSimbolos = malloc(numSimbolos * sizeof(char));

    // Lê os símbolos
    for(i = 0; i < numSimbolos; i++)
    {
        scanf(" %c",&caracter);
        if(caracter == ' ')
        {
            i--;
            continue;
        }
        else
            vetSimbolos[i] = caracter;
    }

    // Ordena a tela de símbolos
    quickSort(vetSimbolos, 0, numSimbolos - 1);

    // Adiciona as transições para cada estado
    int totalTransicoes = numEstados * numSimbolos;
    int id, qtdTransicoes,estadoDestino;
    char simbolo;
    for(i = 0; i < totalTransicoes; i++ )
    {
        scanf("%d",&id);
        getchar();
        scanf(" %c",&simbolo);
        scanf("%d",&qtdTransicoes);
        int posticao = busca(vetSimbolos,simbolo,0,numSimbolos - 1);

        if(qtdTransicoes)
        {
            vetEstados[id].transicoes[posticao].destinos = malloc(qtdTransicoes * sizeof(int));
            vetEstados[id].transicoes[posticao].tam = qtdTransicoes;
            j = 0;
            while(qtdTransicoes)
            {
                scanf("%d",&estadoDestino);
                vetEstados[id].transicoes[posticao].destinos[j] = estadoDestino;
                qtdTransicoes--;
                j++;
            }
            
        }
        else
        {
            vetEstados[id].transicoes[posticao].destinos = malloc(sizeof(int));
            vetEstados[id].transicoes[posticao].tam = qtdTransicoes;
        }
    }

    // Le o estado que comeca
    int estadoAtual;
    scanf("%d",&estadoAtual);

    // Reconhece os estados finais
    int numFinais, finais;
    scanf("%d",&numFinais);
    for(i = 0; i < numFinais; i++)
    {   
        scanf("%d",&finais);
        vetEstados[finais].tipo = 'f';
    }

    // printEstados(vetEstados, numEstados, numSimbolos, vetSimbolos);

    // Le a palavra
    fila fila;
    fila.vetor = malloc(1000 * sizeof(int));
    fila.i = 0;
    fila.f = 1;
    fila.vetor[0] = estadoAtual;
    fila.tam = 1000;
    verifica(vetEstados,numSimbolos,vetSimbolos,&fila);

    // Print para debug
    // for(i = fila.i; i < fila.f; i++)
    // {
    //     printf("%c ",vetEstados[fila.vetor[i]].tipo);
    // }

    // Verifica se alcançou algum estado final
    for(i = fila.i; i < fila.f; i++)
    {
        if(vetEstados[fila.vetor[i]].tipo == 'f')
        {
            printf("Aceito\n");
            return 0;
        }
    }

    printf("Rejeito\n");
    return 0;

    for (i = 0; i < numEstados; i++) {
        for (j = 0; j < numSimbolos; j++) {
            if (vetEstados[i].transicoes[j].tam > 0) {
                free(vetEstados[i].transicoes[j].destinos);
            }
        }
        free(vetEstados[i].transicoes);
    }
    free(vetSimbolos);

}