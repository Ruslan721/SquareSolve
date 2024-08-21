#include <stdio.h>
#include <math.h>
#include <locale.h>

const int INF = -1;

const double e = 1e-20;

void InputFunc();
int SqrSolution(double a, double b, double c, double* x1, double* x2);
void OutputFun_SS(const int res,const double x1,const double x2);
double Diskr(double a, double b, double c);
int DoubleComp(double a, double b);
int Restart(int* key);
void RunTest(double a, double b, double c, double x1_exp, double x2_exp, int nRoots_exp);
void InputFunc_RT();
void InputTests_RT();

int main()
{
    setlocale(LC_ALL, "Rus");


    //InputFunc_RT();
    //InputTests_RT();       // тесты


    InputFunc();          // квадратка


    return 0;
}
void InputFunc()
{
    int key = 1;
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int num =0;

        while (num != 3)
        {
            printf( "Введите значения коэффициэнтов\n"
                    "квадратного уравнения: ");
            num = scanf("%lg %lg %lg", &a, &b, &c);

            if (num != 3)
            while(getchar() != '\n') {}
        }

        int res = SqrSolution(a, b,  c, &x1, &x2);

        OutputFun_SS(res, x1, x2);

        Restart(&key);
    }

}

int SqrSolution(const double a,const double b,const double c, double* const x1, double* const x2)
{
    if (!(DoubleComp(a,0)))
    {
        double d = Diskr(a,b,c);
        if (DoubleComp(d,0))
        {
            *x1 = *x2 = -(b /( 2 * a));
            return 1;
        }
        else if (d > 0)
        {
            d = sqrt(d)/2/a;
            *x1 = -b/2/a - d;
            *x2 = - b/2/a + d;
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else if (!(DoubleComp(b,0)))
    {
        *x1 = *x2 = -c / b;
        return 1;
    }
    else
    {
        if (DoubleComp(c,0))
            return INF;
        else
            return 0;
    }
}

double Diskr(const double a,const double b,const double c)
{
    return b*b - 4*a*c;
}

void OutputFun_SS(const int res,const double x1,const double x2)
{
    switch (res)
    {
    case 0: printf("Нет решений\n\n");
            break;

    case 1: printf("Корень уравнения: %.2lg\n\n",x1);
            break;

    case 2: printf("Корни уравнения: %.2lg, %.2lg\n\n", x1, x2);
            break;

    case INF: printf("Бесконечность решений\n");
            break;

    default: printf("error\n");
    }
}

int DoubleComp(const double a, const double b)
{
    return fabs(a - b) < e;
}

int Restart( int* const key)
{
    while (*key != 1 && *key != 0)
    {
    printf("Продолжть[ 1 ]\n"
            "Остановить[ 0 ]\n");
    while(getchar() != '\n') {}
    scanf("%d", key);
    }

    return 0;
}

void RunTest(const double a,const double b,const double c,const double x1_exp,const double x2_exp,const int nRoots_exp)    //тест
{
    double x1 = 0, x2 = 0;
    int nRoots = SqrSolution(a,b,c,&x1, &x2);

    if (!(DoubleComp(x1,x1_exp)) || !(DoubleComp(x2,x2_exp)) || !(DoubleComp(nRoots,nRoots_exp)))
    {
        printf("\nError\n------------------\na = %.2lg, b = %.2lg, c = %.2lg\n"
                "      x1    x2\nExp   %-6.2lg%-6.2lg%-6d\nRes   %-6.2lg%-6.2lg%-6d\n------------------\n", a, b, c, x1_exp, x2_exp, nRoots_exp, x1, x2, nRoots);  //\t
    }
    else
    {
        printf("\nperfect!\n\n");
    }

}

void InputTests_RT()
{
    double TestsDouble [30] = { 1,1,1,0,0,
                                1,-4,4,2,2,
                                0,0,0,0,0,
                                1,-3,2,1,2,
                                0,1,-2,2,2,
                                0,0,1,0,0};

    int TestsInt [6] = {0, 1, INF, 2, 1, 0};        //
    for (int i = 0; i < 6; i++)
    {
        RunTest(TestsDouble[i*5], TestsDouble[i*5+ 1], TestsDouble[i*5+ 2], TestsDouble[i*5+3], TestsDouble[i*5+4], TestsInt[i]);
    }
}

void InputFunc_RT()
{
    int key = 1;
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        double a = 0, b = 0, c = 0, x1_exp = 0, x2_exp = 0;
        int nRoots_exp = 0;

        printf("Введите три коэффициента квадратного уравнения,\n"
                "верные корни этого уравнения и количество различных\n"
                "значений корня последовательно:\n");
        scanf("%lg %lg %lg %lg %lg %d", &a, &b, &c, &x1_exp, &x2_exp, &nRoots_exp);

        RunTest(a, b, c, x1_exp, x2_exp, nRoots_exp);

        Restart(&key);
    }
}

//assert(x1!= NULL);
// %c в конце ввода
//оптимизировать ввод (ввод -> счёт -> вывод), цикл в вводе   \/
//чтение файла
//текстовый ввод
//NUN, NULL
//структуры
//енам (enum)
//doxygen
//тесты с массивом
