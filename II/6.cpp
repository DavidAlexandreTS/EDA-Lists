#include <iostream>

constexpr int MAXN = 100000;

class PilhaMin
{
public:
    int N;
    int elementos[MAXN];
    int A[MAXN];

    void cria()
    {
        this->N = 0;
    }

    int topo()
    {
        return this->elementos[N - 1];
    }

    void empilha(int dado)
    {
        this->elementos[N] = dado;
        this->A[N] = dado;
        this->N++;

        InitMinHeap(A, this->N);
    }

    int desempilha()
    {
        this->N--;

        for(int i = 0; i < this->N; i++)
        {
            A[i] = elementos[i];
        }

        InitMinHeap(A, this->N);
        return elementos[N];
    }

    int ObterMinimo()
    {
        /*for (int i = 0; i < this->N; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");*/
        return A[0];
    }

    void InitMinHeap(int A[MAXN], int m)
    {
        for(int i = m / 2; i >= 0; i--)
        {
            BuildMinHeap(A, m, i);
        }
    }

    void BuildMinHeap(int A[MAXN], int m, int i)
    {
        int e = 2 * i + 1;
        int d = 2 * i + 2;
        int menor = i;

        if(e < m && A[e] < A[menor])
        {
            menor = e;
        }

        if(d < m && A[d] < A[menor])
        {
            menor = d;
        }

        if(menor != i)
        {
            int aux = A[i];
            A[i] = A[menor];
            A[menor] = aux;
            BuildMinHeap(A, m, menor);
        }
    }
};
