#include <iostream>

class NoDeque
{
public:
	char dado;
	NoDeque* prox;
	NoDeque* ant;
};

class Deque
{
public:
	NoDeque* inicio;
	NoDeque* fim;

	int N;

	void cria()
	{
		this->N = 0;
		this->inicio = 0;
		this->fim = 0;
	}

	void libera()
	{
		while(N > 0)
		{
			RemoveInicio();
		}
	}

	char frente()
	{
		//NoDeque* p = inicio;

		return inicio->dado;
	}

	char atras()
	{
		//NoDeque* p = inicio;

		return fim->dado;
	}

	void InsereInicio(char v)
	{
		NoDeque *no = new NoDeque;
		no->dado = v;
		no->prox = inicio;
		no->ant = 0;

		if(N == 0)
		{
			inicio = fim = no;
		}
		else
		{
			inicio->ant = no;
			//NoDeque *p = inicio;

			inicio = no;
		}
		

		N++;
	}

	void InsereFim(char v)
	{
		NoDeque* no = new NoDeque;
		no->dado = v;
		no->prox = 0;


		if(N == 0)
		{
			no->ant = 0;
			inicio = fim = no;
		}
		else
		{
			fim->prox = no;
			no->ant = fim;
			fim = no;
		}

		N++;
	}

	char RemoveInicio()
	{
		NoDeque* p = inicio;

		if(N == 1)
		{
			char r = p->dado;

			delete p;
			N--;

			return r;
		}
		else
		{
			inicio = inicio->prox;
			inicio->ant = 0;

			char r = p->dado;

			delete p;
			N--;

			return r;
		}
	}

	char RemoveFim()
	{
		NoDeque* p = fim;

		if(N == 1)
		{
			//fim = fim->ant;
			//fim->prox = 0;

			char r = p->dado;

			delete p;
			N--;

			return r;
		}
		else
		{
			fim = fim->ant;
			fim->prox = 0;

			char r = p->dado;

			delete p;
			N--;

			return r;
		}

	}
};

class FilaDeque
{
public:
	Deque f;

	void criar()
	{
		f.cria();
	}

	char frente()
	{
		return f.frente();
	}

	void enfileira(char dado)
	{
		f.InsereFim(dado);
	}

	char desenfileira()
	{
		return f.RemoveInicio();
	}

	void liberar()
	{
		f.libera();
	}
};