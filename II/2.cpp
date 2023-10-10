#include <iostream>
#include<queue> // Fila genérica em C++

class Pilha2F
{
public:
    std::queue<char> f1; // Fila para armazenar os elementos
    std::queue<char> f2; // Fila auxiliar

    // Verifica se a pilha está vazia
    bool empty()
    {
        return f1.empty();
    }

    // Push (empilhar) um elemento na pilha
    void empilha(char dado)
    {
        // Mova todos os elementos de f1 para f2
        while(!f1.empty())
        {
            f2.push(f1.front());
            f1.pop();
        }

        // Insira o novo elemento em f1
        f1.push(dado);

        // Mova os elementos de f2 de volta para f1
        while(!f2.empty())
        {
            f1.push(f2.front());
            f2.pop();
        }
    }

    // Pop (desempilhar) um elemento da pilha
    char desempilha()
    {
        if(!empty())
        {
            char top = f1.front();
            f1.pop();

            return top;
        }
        // Lide com o caso em que a pilha está vazia
        return '\0'; // Ou escolha outro valor padrão apropriado
    }

    char topo()
    {
        return f1.front();
    }
};