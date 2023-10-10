#include <iostream>
#include <queue>

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

    int produtodosnos(No *no)
    {
        if (no == nullptr)
            return 1;

        if (no->esq == nullptr && no->dir == nullptr)
            return no->chave;
        else
        {
            return produtodosnos(no->esq) * produtodosnos(no->dir);;
        }
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


    int encontraraltura(No* no, int n, int h)
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
        int altura_esquerda = encontraraltura(no->esq, n, h + 1);
        int altura_direita = encontraraltura(no->dir, n, h + 1);

        // Retorna a altura máxima encontrada entre os ramos esquerdo e direito
        return std::max(altura_esquerda, altura_direita);
    }

    int fatordebalanceamento(No *no)
    {
        if(no == nullptr)
            return 0;

        int subarvoreesquerda = calcularaltura(no->esq);
        int subarvoredireita = calcularaltura(no->dir);

        return subarvoreesquerda - subarvoredireita;
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

    int SomadasFolhas()
    {
        return somadasfolhas(raiz);
    }

    int ProdutodosNos()
    {
        return produtodosnos(raiz);
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
        return encontraraltura(raiz, n, 1);
    }

    int CalcularFatordeBalanceamento()
    {
        return fatordebalanceamento(raiz);
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
    int hal = arvore.CalcularAltura(1);
    std::cout << "Altura: " << hal << std::endl;
    int bala = arvore.CalcularFatordeBalanceamento();
    std::cout << "Altura: " << bala << std::endl;
    arvore.PrintPorNivel();
    //std::cout << "Produto: " << preordem(no) << std::endl;

    // Lembre-se de liberar a memória alocada para a árvore se necessário
    // (aqui não foi feita a liberação para manter o exemplo simples)

    return 0;
}