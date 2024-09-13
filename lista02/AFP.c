#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    char simbolo;
    struct pilha *prox;
}pilha;

void empilha(pilha *cabeca, char simbolo)
{
    pilha *novo = malloc(sizeof(pilha));
    novo -> simbolo = simbolo;
    novo -> prox = cabeca -> prox;
    cabeca -> prox = novo;
}

void desempilha(pilha *cabeca)
{
    pilha *aux = cabeca -> prox;
    cabeca -> prox = aux -> prox;
    free(aux);
}

char espia(pilha *cabeca)
{   
    return cabeca -> prox -> simbolo;
}

void print(pilha *cabeca)
{
    if(cabeca -> prox != NULL)
    {
        print(cabeca -> prox);
    }
    
    printf("%c",cabeca -> simbolo);
    return;
}

void estado1(pilha *cabeca)
{
    if(cabeca -> prox == NULL)
    {
        empilha(cabeca,'A');
    }
    else if(espia(cabeca) == 'A')
    {
        empilha(cabeca, 'A');
    }
    else
        desempilha(cabeca);

    if(cabeca -> prox == NULL)
        printf("nil\n");
    else
    {
        print(cabeca);
    }
}

void estado2(pilha *cabeca)
{
    if(cabeca -> prox == NULL)
    {
        empilha(cabeca,'B');
    }
    else if(espia(cabeca) == 'B')
    {
        empilha(cabeca, 'B');
    }
    else
        desempilha(cabeca);
    
    if(cabeca -> prox == NULL)
        printf("nil\n");
    else
    {
        print(cabeca);
    }
}

int main()
{
    char palavra[100];

    // Leitura de cada palavra
    while(scanf("%s",palavra) != EOF)
    {   
        pilha *cabeca = malloc(sizeof(pilha));
        cabeca -> prox = NULL;
        cabeca -> simbolo = '\n';
        int i = 0;
        while(palavra[i] != '\0')
        {
            if( palavra[i] == 'a')
                estado1(cabeca);
            else
                estado2(cabeca);
             i++;
        }
        if(cabeca -> prox == NULL)
            printf("Aceito\n");
        else
            printf("Rejeito\n");
        printf("\n");
        free(cabeca);
    }
    return 0;
}