#include <iostream>
#include <stack>
#include <queue>

void inverte(std::stack<char> *p)
{
	std::queue<char> f; // somente essa fila e mais espaço auxiliar constante

    //printf("%d\n", p->empty());
    while(!(p->empty()))
    {
        char aux = p->top();

        p->pop();
        f.push(aux);
    }

    while(!f.empty())
    {
        char aux = f.front();

        f.pop();
        p->push(aux);
    }
}