#include <iostream>
#include <stack>

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;

    return 0; // Assume que qualquer outra coisa (incluindo par�nteses) tem preced�ncia zero
}

void polonesa(char *expressao, int N, char *saida_polonesa)
{
    std::stack<char> operadores;
    int posSaida = 0;

    for(int i = 0; i < N; i++)
    {
        char atual = expressao[i];

        if(isalnum(atual))
        {
            // � um operando, copia diretamente para a sa�da
            saida_polonesa[posSaida++] = atual;
        }
        else if(atual == '(')
        {
            // � um par�ntese esquerdo, empilha na pilha de operadores
            operadores.push(atual);
        }
        else if(atual == ')')
        {
            // � um par�ntese direito, desempilha os operadores at� encontrar o par�ntese esquerdo
            while(!operadores.empty() && operadores.top() != '(')
            {
                saida_polonesa[posSaida++] = operadores.top();
                operadores.pop();
            }
            // Remove o par�ntese esquerdo da pilha
            if(!operadores.empty() && operadores.top() == '(')
            {
                operadores.pop();
            }
        }
        else if (isOperator(atual))
        {
            // � um operador, desempilha os operadores de maior ou igual preced�ncia
            while(!operadores.empty() && isOperator(operadores.top()) && precedence(operadores.top()) >= precedence(atual))
            {
                saida_polonesa[posSaida++] = operadores.top();
                operadores.pop();
            }
            // Empilha o operador atual
            operadores.push(atual);
        }
    }

    // Desempilha os operadores restantes
    while(!operadores.empty())
    {
        saida_polonesa[posSaida++] = operadores.top();
        operadores.pop();
    }

    // Adiciona o terminador nulo � sa�da
    saida_polonesa[posSaida] = '\0';
}

int main()
{
    char expressao[] = "((A+B)*(C-(F/D)))";
    int N = sizeof(expressao) - 1; // Desconta o terminador nulo
    char saida_polonesa[N];

    polonesa(expressao, N, saida_polonesa);

    std::cout << "Express�o em nota��o polonesa reversa: " << saida_polonesa << std::endl;

    return 0;
}
