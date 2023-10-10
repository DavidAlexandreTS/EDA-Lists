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

    return 0; // Assume que qualquer outra coisa (incluindo parênteses) tem precedência zero
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
            // É um operando, copia diretamente para a saída
            saida_polonesa[posSaida++] = atual;
        }
        else if(atual == '(')
        {
            // É um parêntese esquerdo, empilha na pilha de operadores
            operadores.push(atual);
        }
        else if(atual == ')')
        {
            // É um parêntese direito, desempilha os operadores até encontrar o parêntese esquerdo
            while(!operadores.empty() && operadores.top() != '(')
            {
                saida_polonesa[posSaida++] = operadores.top();
                operadores.pop();
            }
            // Remove o parêntese esquerdo da pilha
            if(!operadores.empty() && operadores.top() == '(')
            {
                operadores.pop();
            }
        }
        else if (isOperator(atual))
        {
            // É um operador, desempilha os operadores de maior ou igual precedência
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

    // Adiciona o terminador nulo à saída
    saida_polonesa[posSaida] = '\0';
}

int main()
{
    char expressao[] = "((A+B)*(C-(F/D)))";
    int N = sizeof(expressao) - 1; // Desconta o terminador nulo
    char saida_polonesa[N];

    polonesa(expressao, N, saida_polonesa);

    std::cout << "Expressão em notação polonesa reversa: " << saida_polonesa << std::endl;

    return 0;
}
