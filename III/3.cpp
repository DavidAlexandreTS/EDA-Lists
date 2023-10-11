#include <iostream>
#include <queue>
int produto = 1;
class No
{
public:
	No *dir;
	No *esq;
	int chave;

    No(int v) : chave(v), esq(nullptr), dir(nullptr) {}
};

class Arvore
{
public:
	No *raiz;

    Arvore() : raiz(nullptr) {}

	int somadasfolhas(No *no)
	{
		if(no == nullptr)
			return 0;

		if(no->esq == nullptr && no->dir == nullptr)
			return no->chave;

		int soma_esquerda = somadasfolhas(no->esq);
		int soma_direita = somadasfolhas(no->dir);

		return soma_esquerda + soma_direita;
	}

    void preordem(No *no)
    {
        //printf("Hi\n");
        //printf("%d ", no->chave);
        //printf("%d ", no->esq->chave);

        if(no == nullptr)
            return;
        
        printf("%d ", no->chave);

        preordem(no->esq);
        preordem(no->dir);
        //printf("\n");
    }

    void emordem(No *no)
    {
        if(no == nullptr)
        {
           // printf("%d ", no->chave);
            return;
        }

        emordem(no->esq);

        printf("%d ", no->chave);

        emordem(no->dir);
    }

    void posordem(No *no)
    {
        if(no == nullptr)
        {
            return;
        }
        //printf("Entrei aqui\n");
        if(no->esq == nullptr && no->dir == nullptr)
        {
            printf("%d ", no->chave);
            return;
        }

        posordem(no->esq);
        //printf("%d ", no->chave);
        posordem(no->dir);

        printf("%d ", no->chave);
    }

    int calcularaltura(No* no)
    {
        if(no == nullptr)
            return 0;

        int altura_esquerda = calcularaltura(no->esq);
        int altura_direita = calcularaltura(no->dir);

        // A altura do nó é o máximo entre a altura da subárvore esquerda e a da subárvore direita,
        // mais 1 para contar o próprio nó.
        return 1 + std::max(altura_esquerda, altura_direita);
    }


    int encontraraltura(No* no, int n)
    {
        if(no == nullptr)
            return 0;

        if(no->chave == n)
        {
            //printf("Sou o 1: %d", no->chave);
            return calcularaltura(no);
        }

        //encontraraltura(no->esq, n, h + 1);
        //encontraraltura(no->dir, n, h + 1); 
        //printf("Cheeguei aqui\n");
        int altura_esquerda = encontraraltura(no->esq, n);
        int altura_direita = encontraraltura(no->dir, n);

        //printf("Sou a altura esq: %d\n", altura_esquerda);
        //printf("Sou a altura dir: %d\n", altura_direita);
        // Retorna a altura máxima encontrada entre os ramos esquerdo e direito
        return std::max(altura_esquerda, altura_direita);
    }

    int calcularbalanceamento(No* no)
    {
        if (no == nullptr)
            return 0;

        int altura_esquerda = calcularaltura(no->esq);
        int altura_direita = calcularaltura(no->dir);

        // A altura do nó é o máximo entre a altura da subárvore esquerda e a da subárvore direita,
        // mais 1 para contar o próprio nó.
        return (1 + altura_esquerda) - (1 + altura_direita);
    }

    int fatordebalanceamento(No *no, int n)
    {
        if(no == nullptr)
            return 0;

        if (no->chave == n)
            return calcularbalanceamento(no);

        int subarvoreesquerda = fatordebalanceamento(no->esq, n);
        int subarvoredireita = fatordebalanceamento(no->dir, n);

        //printf("Sou a subarvoreesquerda rsrs: %d\n", subarvoreesquerda);
        //printf("Sou a subarvoredireita rsrs: %d\n", subarvoredireita);

        if(subarvoreesquerda == 0 && subarvoredireita == 0)
            return 0;
        else
            return (subarvoreesquerda != 0) ? subarvoreesquerda : subarvoredireita;
    }

    void PrintPorNivel()
    {
        if(raiz == nullptr)
            return;

        std::queue<No*> fila;
        fila.push(raiz);

        while(!fila.empty())
        {
            No *no = fila.front();
            fila.pop();

            std::cout << no->chave << " ";

            if(no->esq != nullptr)
                fila.push(no->esq);

            if(no->dir != nullptr)
                fila.push(no->dir);
        }
    }

    int produtodosnos(No* no)
    {
        if(no == nullptr)
            return 1;
        else
            return no->chave*produtodosnos(no->esq)*produtodosnos(no->dir);
    }



    int SomadasFolhas()
    {
        return somadasfolhas(raiz);
    }

    void PrintPreOrdem()
    {
        preordem(raiz);
    }

    void PrintEmOrdem()
    {
        emordem(raiz);
    }

    void PrintPosOrdem()
    {
        posordem(raiz);
    }

    int CalcularAltura(int n)
    {
        return encontraraltura(raiz, n);
    }

    int CalcularFatordeBalanceamento(int n)
    {
        return fatordebalanceamento(raiz, n);
    }

    int ProdutodosNos()
    {
        return produtodosnos(raiz);
    }
};

int main()
{
    Arvore arvore;

    // Construa sua árvore aqui
    // Exemplo de árvore:
    //       5
    //      / \
    //     3   8
    //    / \   \
    //   1   4   10

    arvore.raiz = new No(5);
    arvore.raiz->esq = new No(3);
    arvore.raiz->dir = new No(8);
    arvore.raiz->esq->esq = new No(1);
    arvore.raiz->esq->dir = new No(4);
    arvore.raiz->dir->dir = new No(10);

    int soma = arvore.SomadasFolhas();
    int some = arvore.ProdutodosNos();
    std::cout << "Soma das folhas da árvore: " << soma << std::endl;
    std::cout << "Produto: " << some << std::endl;
    arvore.PrintPreOrdem();
    printf("\n");
    arvore.PrintEmOrdem();
    printf("\n");
    arvore.PrintPosOrdem();
    printf("\n");
    int hal = arvore.CalcularAltura(8);
    std::cout << "Altura: " << hal << std::endl;
    int bala = arvore.CalcularFatordeBalanceamento(3);
    std::cout << "Bala: " << bala << std::endl;
    arvore.PrintPorNivel();
    //std::cout << "Produto: " << preordem(no) << std::endl;

    // Lembre-se de liberar a memória alocada para a árvore se necessário
    // (aqui não foi feita a liberação para manter o exemplo simples)

    return 0;
}