#include <iostream>
#include <stack>
using namespace std;

void transfer(std::stack<char> &s1, std::stack<char> &s2, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = s1.top();

        s1.pop();
        
        s2.push(temp);
    }
}

void inverte(std::stack<char>* p)
{
    std::stack<char> p1;//pilha auxiliar

    int n = p->size();

    for(int i = 0; i < n; i++)
    {
        int x = p->top();

        p->pop();

        transfer(*p, p1, n - i - 1);
        p->push(x);
        transfer(p1, *p, n - i - 1);
    }
}

int main()
{
    std::stack<char> q;

    // Insert elements
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    printf("\n");

    // Insert elements
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');

    inverte(&q);
    //printf("%d\n", q.size());

    // Print the queue
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}