#include <stdio.h>
#include <math.h>
#include <locale.h>

const double e = 1e-20;

void InputFunc(double* a, double* b, double* c);
int SqrSolution(double a, double b, double c, double* x1, double* x2);
double Diskr(double a, double b, double c);
int DoubleComp(double a, double b);
int Restart(int* key);
/*int RunTest(double a, double b, double c, double x1_exp, double x2_exp, int nRoots_exp);
void InputFunc_RT(double* a, double* b, double* c, double* x1_exp, double* x2_exp, int* nRoots_exp);*/

int main()
{
    setlocale(LC_ALL, "Rus");
     /*
    double a = 0, b = 0, c = 0, x1_exp = 0, x2_exp = 0;         // тест
    int nRoots_exp = 0;
    InputFunc_RT(&a, &b, &c, &x1_exp, &x2_exp, &nRoots_exp);
    RunTest(a, b, c, x1_exp, x2_exp, nRoots_exp); */


    int key = 1;
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        InputFunc(&a,&b,&c);

        int res = SqrSolution(a, b,  c, &x1, &x2);

        switch (res)
        {
        case 0: printf("Нет решений\n\n");
                break;

        case 1: printf("Корень уравнения: %.2lg\n\n",x1);
                break;

        case 2: printf("Корни уравнения: %.2lg, %.2lg\n\n", x1, x2);
                break;

        default: printf("error");
        }

        Restart(&key);
    }
        return 0;
}
void InputFunc( double* const a, double* const b, double* const c)
{
    int num =0;

    while (num != 3)
    {
    printf("Введите значения коэффициэнтов\n"
           "квадратного уравнения: ");
    num = scanf("%lg %lg %lg", a, b, c);

    while(getchar() != '\n') {}   //?
    }
}

int SqrSolution(const double a,const double b,const double c, double* const x1, double* const x2)
{
    if (!(DoubleComp(a,0)))
    {
        double d = Diskr(a,b,c);
        if (DoubleComp(d,0))
        {
            *x1 = *x2 = -(b / 2 / a);
            return 1;
        }
        else if (d > 0)
        {
            d = sqrt(d)/2/a;
            *x1 = -b/2/a + d;
            *x2 = - b/2/a - d;
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        *x1 = *x2 = -c / b;
        return 1;
    }
}

double Diskr(const double a,const double b,const double c)
{
    return b*b - 4*a*c;
}

int DoubleComp(const double a, const double b)
{
    return fabs(a - b) > e;
}

int Restart( int* const key)
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

/*int RunTest(const double a,const double b,const double c,const double x1_exp,const double x2_exp,const int nRoots_exp)    //тест
{
    double x1 = 0, x2 = 0;
    int nRoots = SqrSolution(a,b,c,&x1, &x2);
    if (x1 != x1_exp || x2 != x2_exp || nRoots != nRoots_exp)
    {
        printf("Error\na = %.2lg, b = %.2lg, c = %.2lg\n"
                "      x1    x2\nExp   %-6.2lg%.2lg\nRes   %-6.2lg%.2lg\n", a, b, c, x1_exp, x2_exp, x1, x2);
    }
    else
    {
        printf("perfect!\n");
    }
}

void InputFunc_RT( double* const a, double* const b, double* const c, double* const x1_exp, double* const x2_exp, int* const nRoots_exp)
{
    printf("Введите три коэффициента квадратного уравнения,\n"
            "верные корни этого уравнения и количество различных\n"
            "значений корня последовательно: ");
    scanf("%lg %lg %lg %lg %lg %d", a, b, c, x1_exp, x2_exp, nRoots_exp);
} */


//оптимизировать ввод
