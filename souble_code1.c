#include <stdio.h>
#include <math.h>
#include <locale.h>

const double e = 1e-20;

void InputFunc(double* a, double* b, double* c);
void SqrSolution(double a, double b, double c, double* x1, double* x2);
double Diskr(double a, double b, double c);
int DoubleComp(double a, double b);
int Restart(int* key);

int main()
{
    setlocale(LC_ALL, "Rus");

    int key = 1;
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        InputFunc(&a,&b,&c);

        SqrSolution(a, b,  c, &x1, &x2);

        Restart(&key);
    }
        return 0;
}

void InputFunc(double* a, double* b, double* c)
{
    int num =0;

    while (num != 3)
    {
    printf("Введите значения коэффициэнтов\n"
           "квадратного уравнения: ");
    num = scanf("%lg %lg %lg", a, b, c);
    while(getchar() != '\n') {}
    }
}

void SqrSolution(double a, double b, double c, double* x1, double* x2)
{
    if (!(DoubleComp(a,0)))
    {
        double d = Diskr(a,b,c);
        if (DoubleComp(d,0))
            printf("Корень уравнения: %.2lg\n\n",-(b / 2 / a));

        else if (d > 0)
        {
            *x1 = (-b - sqrt(d))/2/a;
            *x2 = (- b + sqrt(d))/2/a;
            printf("Корни уравнения: %.2lg, %.2lg\n\n", *x1, *x2);
        }
        else
        {
            printf("Нет решений\n\n");
        }
    }
    else
    {
        printf("Задайте старший коэффициент\n"
              "отличный от нуля\n\n");
    }
}

double Diskr(double a, double b, double c)
{
    return b*b - 4*a*c;
}

int DoubleComp(double a, double b)
{
    if (fabs(a - b) > e)
        return 0;
    else
        return 1;
}

int Restart(int* key)
{
    while (*key != 1 && *key != 0)
    {
    printf("Продолжть[ 1 ]\n"
            "Остановить[ 0 ]\n");
    scanf("%d", key);
    while(getchar() != '\n') {}
    }

    return 0;
}
