#include <iostream>
#include <stack>

void inverte(std::stack<char> *p)
{
	std::stack<char> p1;
	std::stack<char> p2;

	while(!(p->empty()))
	{
		p1.push(p->top());
		p->pop();
	}

	while(!p1.empty())
	{
		p2.push(p1.top());
		p1.pop();
	}

	while(!p2.empty())
	{
		p->push(p2.top());
		p2.pop();
	}
}
