#include <iostream>
#include <stack>
#include <queue>

void inverte(std::queue<char> *f)
{
    std::stack<char> p; // somente essa pilha e mais espaço auxiliar constante

    //printf("%d\n", p->empty());
    while(!(f->empty()))
    {
        char aux = f->front();

        f->pop();
        p.push(aux);
    }

    while(!p.empty())
    {
        char aux = p.top();

        p.pop();
        f->push(aux);
    }
}