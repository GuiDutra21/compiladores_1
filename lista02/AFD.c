// #include <stdio.h>
// #include <string.h>

// typedef struct {
//     int *transicoes;
//     char tipo;
// } estado;

// void swap(char (*str1)[100], char (*str2)[100]) {
//     char aux[100];
//     strcpy(aux, *str1);
//     strcpy(*str1, *str2);
//     strcpy(*str2, aux);
// }


// int partition(char vetSimbolos[][100], int l, int r) {
//     int i = l, j = r - 1;
//     while (i < j) {
//         while (strcmp(vetSimbolos[i], vetSimbolos[j]) < 0) i++;
//         while (i < j && strcmp(vetSimbolos[r], vetSimbolos[j]) < 0) j--;
//         if (i < j) swap(&vetSimbolos[i], &vetSimbolos[j]);
//     }

//     swap(&vetSimbolos[i], &vetSimbolos[r]);

//     return i;
// }

// void quickSort(char vetSimbolos[][100], int l, int r) {
//     if (l < r) {
//         // Mediana de tres
//         int meio = (r - l) / 2;
//         if (strcmp(vetSimbolos[r], vetSimbolos[meio]) < 0) swap(&vetSimbolos[r], &vetSimbolos[meio]);
//         if (strcmp(vetSimbolos[meio], vetSimbolos[l]) < 0) swap(&vetSimbolos[l], &vetSimbolos[meio]);
//         if (strcmp(vetSimbolos[meio], vetSimbolos[r]) < 0) swap(&vetSimbolos[meio], &vetSimbolos[r]);
//         int pivo = partition(vetSimbolos, l, r);

//         quickSort(vetSimbolos, l, pivo - 1);
//         quickSort(vetSimbolos, pivo + 1, r);
//     }
// }

// int main() {
//     int numEstados, numSimbolos, i;
//     scanf("%d %d", &numEstados, &numSimbolos);
//     estado vetEstados[numEstados];
//     char vetSimbolos[numSimbolos][100];

//     for (i = 0; i < numSimbolos; i++) {
//         scanf("%s", vetSimbolos[i]);
//     }

//     quickSort(vetSimbolos, 0, numSimbolos - 1);

//     for (i = 0; i < numSimbolos; i++) {
//         printf("%s\n", vetSimbolos[i]);
//     }

//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------------

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct {
//     int *transicoes;
//     char tipo;
// } estado;

// void swap(char **str1, char **str2) {
//     char *aux = *str1;
//     *str1 = *str2;
//     *str2 = aux;
// }

// int partition(char **vetSimbolos, int l, int r) {
    
//     int i = l, j = r - 1;

//     while (i < j)
//     {
//         while (strcmp(vetSimbolos[i], vetSimbolos[j]) < 0) i++;
//         while (i < j && strcmp(vetSimbolos[r], vetSimbolos[j]) < 0) j--;
//         if (i < j) swap(&vetSimbolos[i], &vetSimbolos[j]);
//     }

//     swap(&vetSimbolos[i], &vetSimbolos[r]);

//     return i;
// }

// void quickSort(char **vetSimbolos, int l, int r)
// {
//     if (l < r) {

//         // Mediana de três
//         int meio = (r + l) / 2;
//         if (strcmp(vetSimbolos[r], vetSimbolos[meio]) < 0) swap(&vetSimbolos[r], &vetSimbolos[meio]);
//         if (strcmp(vetSimbolos[meio], vetSimbolos[l]) < 0) swap(&vetSimbolos[l], &vetSimbolos[meio]);
//         if (strcmp(vetSimbolos[meio], vetSimbolos[r]) < 0) swap(&vetSimbolos[meio], &vetSimbolos[r]);

//         int pivo = partition(vetSimbolos, l, r);

//         quickSort(vetSimbolos, l, pivo - 1);
//         quickSort(vetSimbolos, pivo + 1, r);
//     }
// }

// int busca(char **vetSimbolos, char *simbolo, int l, int r)
// {   
//     if(l <= r)
//     {
//         int meio = (r - l)/2;
//         int compara = strcmp(vetSimbolos[meio],simbolo) == 0;
//         if(compara == 0)
//         {
//             return meio;
//         }
//         else if (compara < 0)
//         {
//             return busca(vetSimbolos,simbolo,l, meio - 1);
//         }
//         else
//             return busca(vetSimbolos,simbolo,meio + 1, r);
//     }
//     return -1;
// }

// int main() {
//     int numEstados, numSimbolos, i;
//     scanf("%d %d", &numEstados, &numSimbolos);

//     // Cria o vetor de estados e já aloca os vetores dentro de cada estado
//     estado vetEstados[numEstados];
//     for (i = 0; i < numEstados; i++)
//     {
//         vetEstados[i].transicoes = malloc(numSimbolos * sizeof(int));
//         vetEstados[i].tipo = 'i';
//     }

//     // Aloca memoria para a matriz toda
//     char **vetSimbolos = (char **)malloc(numSimbolos * sizeof(char *));
//     for (i = 0; i < numSimbolos; i++) {
//         vetSimbolos[i] = (char *)malloc(100 * sizeof(char));
//         scanf("%s", vetSimbolos[i]);
//     }

//     // Ordena a tela de simbolos
//     quickSort(vetSimbolos, 0, numSimbolos - 1);

//     // Adiciona as transicoes para cada estado
//     int totalTransicoes = numEstados * numSimbolos;
//     int id, estadoDestino;
//     char simbolo[100];
//     for(i = 0; i < totalTransicoes; i++)
//     {
//         scanf("%d %s %d",&id, simbolo, &estadoDestino); // perigoso, se der erro voltar aqui !
//         int posticao = busca(vetSimbolos,simbolo,0,numSimbolos - 1);
//         vetEstados[id].transicoes[posticao] = estadoDestino;
//     }

//     // Le o estado que comeca
//     int estadoAtual;
//     scanf("%d",&estadoAtual);
    
//     // Reconhece os estados finais
//     int numFinais, finais;
//     scanf("%d",&numFinais);
//     for(i = 0; i < numFinais; i++)
//     {   
//         scanf("%d",&finais);
//         vetEstados[finais].tipo = 'f';
//     }

//     // Le a palavra
//     char caracter;
//     while(scanf(" %c",&caracter) != EOF)
//     {
//         busca(vetSimbolos,caracter,0,numSimbolos - 1);
//     }


    
//     for (i = 0; i < numSimbolos; i++)
//     {
//         printf("%s\n", vetSimbolos[i]);
//         free(vetSimbolos[i]); // Libera a memória alocada para cada string
//     }
//     free(vetSimbolos); // Libera a memória alocada para o array de ponteiros
//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int *transicoes;
    char tipo;
} estado;

void swap(char str1, char str2) {
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

int main()
{
    int numEstados, numSimbolos, i;
    scanf("%d %d", &numEstados,&numSimbolos);

    // Cria o vetor de estados e já aloca os vetores dentro de cada estado
    estado vetEstados[numEstados];
    for (i = 0; i < numEstados; i++)
    {
        vetEstados[i].transicoes = malloc(numSimbolos * sizeof(int));
        vetEstados[i].tipo = 'i';
    }

    char caracter;
    // Aloca memoria para o vetor de simbolos
    char *vetSimbolos = malloc(numSimbolos * sizeof(char));
    for(i = 0; i < numSimbolos; i++)
    {
        scanf("%c",&caracter);
        if(caracter == ' ')
        {
            i--;
            continue;
        }
        else
            vetSimbolos[i] = caracter;
    }

    // Ordena a tela de simbolos
    quickSort(vetSimbolos, 0, numSimbolos - 1);

    // Adiciona as transicoes para cada estado
    int totalTransicoes = numEstados * numSimbolos;
    int id, estadoDestino;
    char simbolo;
    for(i = 0; i < totalTransicoes; i++)
    {
        scanf("%d",&id);
        getchar();
        scanf(" %c %d",&simbolo,&estadoDestino);
        int posticao = busca(vetSimbolos,simbolo,0,numSimbolos - 1);
        vetEstados[id].transicoes[posticao] = estadoDestino;
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

    // Le a palavra
    int indice;
    while(scanf(" %c",&caracter) != EOF)
    {   
        indice = busca(vetSimbolos,caracter,0,numSimbolos - 1);
        if(indice == -1)
        {
            printf("Rejeito\n");
            return 0;
        }
        else
        {   
            estadoAtual = vetEstados[estadoAtual].transicoes[indice];
        }
    }


    if(vetEstados[estadoAtual].tipo == 'f')
        printf("Aceito\n");
    else
        printf("Rejeito\n");
    
    return 0;
}