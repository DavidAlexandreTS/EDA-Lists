#include <iostream>
#include <queue>
using namespace std;

void reverse(std::queue<char> *f)
{
    int s = f->size();
    //printf("%d\n", s);

    std::queue<char> f1;//fila auxiliar 1
    std::queue<char> f2;//fila auxiliar 2


    for(int i = 0; i < s; i++)
    {

        // Get the last element to the
        // front of queue

        //printf("%d\n", f->size());
        for(int j = 0; j < f->size() - 1; j++)
        {
            char x = f->front();
            f->pop();
            f->push(x);
        }


        f1.push(f->front());
        f->pop();
    }

    while(!(f1.empty()))
    {
        char y = f1.front();
        f1.pop();
        f2.push(y);
    }

    while(!(f2.empty()))
    {
        char z = f2.front();
        f2.pop();
        f->push(z);
    }
}