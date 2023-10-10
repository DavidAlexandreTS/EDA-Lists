// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho

#pragma once

// C includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// helpers
#include <fmt/core.h>
#include <scn/scn.h>
// C++ includes
#include <functional>
#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <tuple>  // para exercícios com tupla
// favor não remover exemplos
#include <revisao-c-cpp/exemplo.hpp>
//

using fmt::print;  // NOLINT
using scn::scan;   // NOLINT

// exercício 0
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio0(std::string entrada)
{
    // SOLUCAO: modifique o return 1 para return 0
    return 0;
    // return 0;
}

// resolução exercício 1 (verifique se está correto)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio1(std::string entrada)
{
    std::istringstream iss(entrada);

    int a = 0;
    int b = 0;

    iss >> a;
    iss >> b;

    if (b <= a) return 0;  // ERRO DE LEITURA

    int soma = 0;

    for (int i = a; i <= b; i++) soma += i;

    return soma;
}

// =======================  falta fazer ============================

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio2(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;
    int vote = 0;
    int c1 = 0, c2 = 0, c3 = 0, nulos = 0;

    // printf("Digite o numero total de eleitores: ");
    iss >> n;

    if (n == 0) return 0;

    for (int i = 0; i < n; i++)
    {
        // printf("Digite o voto do eleitor %d: ", i + 1);
        iss >> vote;

        if (vote == 0)
        {
            nulos++;
        }
        else if (vote == 1)
        {
            c1++;
        }
        else if (vote == 2)
        {
            c2++;
        }
        else if (vote == 3)
        {
            c3++;
        }
        else
        {
            nulos++;
        }
    }

    if (c1 >= nulos && c1 >= c2 && c1 >= c3)
    {
        if ((c1 != nulos) && (c1 != c2) && (c1 != c3))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (c2 >= nulos && c2 >= c1 && c2 >= c3)
    {
        if ((c2 != nulos) && (c2 != c1) && (c2 != c3))
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else if (c3 >= nulos && c3 >= c1 && c3 >= c2)
    {
        if ((c3 != nulos) && (c3 != c1) && (c3 != c2))
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if ((c1 != nulos) && (c2 != nulos) && (c3 != nulos))
        {
            return 0;
        }
    }
}

// dica: retorna uma tupla com 4 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
auto exercicio3(std::string entrada)  // this function returns multiple values
{
    std::istringstream iss(entrada);

    int n = 0;
    int flag = -1;
    double num = 0;
    double soma = 0, media = 0, maior = 0, menor = 0, menorcurrent = 0;

    iss >> n;
    //scanf("%d", &n);

    if (n == 0) return std::make_tuple(0.0, 0.0, 0.0, 0.0);

    for (int i = 0; i < n; i++)
    {
        iss >> num;

        if (flag < 0)
        {
            menorcurrent = num;
            flag = 1;
        }

        soma += num;

        if (num > maior) maior = num;

        if (num < menorcurrent)
        {
            menor = num;
            menorcurrent = num;
        }
        else
        {
            menor = menorcurrent;
        }

    }
    media = soma / n;

    return std::make_tuple(soma, media, maior, menor);
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio4(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;
    float* notas;
    char** nomes_dos_alunos;

    // printf("Digite o número de alunos: ");
    //scanf("%d", &n);
    iss >> n;

    notas = (float*)malloc(n * sizeof(float));
    nomes_dos_alunos = (char**)malloc(n * sizeof(char*));

    if (nomes_dos_alunos == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        char nome[20];
        float nota = 0;

        // printf("Digite a nota do aluno %d: ", i + 1);
        //scanf("%f", &notas[i]);
        iss >> nota;

        // printf("Digite o nome do aluno %d: ", i + 1);
        //scanf("%s", nome);
        iss >> nome;

        notas[i] = nota;
        nomes_dos_alunos[i] = (char*)malloc((strlen(nome) + 1) * sizeof(char));

        strcpy(nomes_dos_alunos[i], nome);
    }

    int aluno = 0;

    //scanf("%d", &aluno);
    iss >> aluno;

    if (notas[aluno - 1] >= 6)
        return 1;
    else
        return 0;

    // Libera a memória alocada
    for (int i = 0; i < n; i++)
    {
        free(nomes_dos_alunos[i]);
    }

    free(nomes_dos_alunos);
    free(notas);
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
unsigned long long int fatorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int exercicio5(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;

    iss >> n;
    //scanf("%d", &n);

    unsigned long long int resultado = fatorial(n);

    return resultado;
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
unsigned long long int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int exercicio6(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;

    //scanf("%d", &n);
    iss >> n;

    unsigned long long int resultado = fibonacci(n);

    return resultado;
}

// dica: retorno de 'char', não 'int'
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
char exercicio7(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;
    int countMaria = 0;
    int countJoao = 0;

    char playMaria;
    char playJoao;

    //scanf("%d", &n);
    iss >> n;

    int i = 0;
    while (i < n)
    {
        //scanf(" %c", &playMaria);
        //scanf(" %c", &playJoao);
        iss >> playMaria;
        iss >> playJoao;

        if (playMaria == playJoao)
        {
            // Empate, não conta pontos
        }
        else if ((playMaria == 'p' && playJoao == 'd') ||
            (playMaria == 'd' && playJoao == 't') ||
            (playMaria == 't' && playJoao == 'p'))
        {
            countMaria++;
        }
        else
        {
            countJoao++;
        }

        i++;
    }

    if (countMaria == countJoao)
    {
        return 'X';  // Empate
    }
    else if (countMaria > countJoao)
    {
        return 'M';  // Maria vence
    }
    else
    {
        return 'J';  // João vence
    }
}

// dica: retorna uma tupla com 2 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
auto exercicio8(std::string entrada)
{
    int A;
    int B;

    std::istringstream iss(entrada);

    iss >> A;
    iss >> B;
    //scanf("%d", &A);
    //scanf("%d", &B);
    // printf("%d %d\n", A, B);

    int* aux;

    aux = &A;
    *aux = *aux + B;
    B = *aux - B;
    *aux = *aux - B;

    return std::make_tuple(A, B);
}

// dica: retorno de 'float', não 'int'
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
void trocar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto)
{
    int pivô = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j] <= pivô)
        {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[alto]);

    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pivô = particionar(arr, baixo, alto);

        quickSort(arr, baixo, pivô - 1);
        quickSort(arr, pivô + 1, alto);
    }
}

float exercicio9(std::string entrada)
{
    std::istringstream iss(entrada);

    int n = 0;
    int* nums;

    //scanf("%d", &n);
    iss >> n;

    nums = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &nums[i]);
        iss >> nums[i];
    }

    quickSort(nums, 0, n - 1);

    int prim = 0;
    int ulti = n - 1;
    int meio = prim + (ulti - prim) / 2;

    if (n % 2 == 0)
    {
        float media = (nums[meio] + nums[meio + 1]) / 2.0;

        return media;
    }
    else
    {
        float mediana = nums[meio];

        return mediana;
    }
}