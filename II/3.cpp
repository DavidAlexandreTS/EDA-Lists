#include <iostream>
#include<stack> // Pilha genérica em C++

class Fila2P
{
public:
    std::stack<char> p1; // Pilha para armazenar os elementos
    std::stack<char> p2; // Pilha auxiliar

    // Verifica se a pilha está vazia
    bool empty()
    {
        return p1.empty();
    }

    //enfileirar um elemento na fila
    void enfileira(char dado)
    {
        // Mova todos os elementos de f1 para f2
        while(!p1.empty())
        {
            p2.push(p1.top());
            p1.pop();
        }

        // Insira o novo elemento em f1
        p1.push(dado);

        // Mova os elementos de f2 de volta para f1
        while(!p2.empty())
        {
            p1.push(p2.top());
            p2.pop();
        }
    }

    // Pop (desenfileirar) um elemento da pilha
    char desenfileira()
    {
        if(!empty())
        {
            char front = p1.top();
            p1.pop();

            return front;
        }
        // Lide com o caso em que a pilha está vazia
        return '\0'; // Ou escolha outro valor padrão apropriado
    }

    char frente()
    {
        return p1.top();
    }
};