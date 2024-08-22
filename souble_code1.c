#include <stdio.h>
#include <math.h>
#include <locale.h>

struct TestStr
{
    double a, b, c;
    double x1_exp, x2_exp;
    int nRoots_exp;
};

const double DOUBLE_NULL = 0.0;

enum SqrConstants
{
    ROOTS_0   =  0,
    ROOTS_1   =  1,
    ROOTS_2   =  2,
    ROOTS_INF = -1   //словами

};

const double e = 1e-20;  //EPS

const TestStr Tests_Data [6] =   // капс
    {
     {1,  1,  1, DOUBLE_NULL, DOUBLE_NULL, ROOTS_0},
     {1, -4,  4, 2, 2, ROOTS_1},
     {0,  0,  0, DOUBLE_NULL, DOUBLE_NULL, ROOTS_INF},
     {1, -3,  2, 1, 2, ROOTS_2},
     {0,  1, -2, 2, 2, ROOTS_1},
     {0,  0,  1, DOUBLE_NULL, DOUBLE_NULL, ROOTS_0}
    };

void Manager_SqrSolution();
void InputFunc(double* const a, double* const b, double* c);  //const
int SqrSolution(double a, double b, double c, double* x1, double* x2);
void OutputFun_SS(const int res,const double x1,const double x2);
double Diskr(double a, double b, double c);
int DoubleEqual(double a, double b);
int Restart(int* key);
void RunTest( const TestStr* const test);
void InputTests_by_data();
void InputFunc_by_keyboard();
int SqrEq(double a, double b, double c, double* x1, double* x2);
int LinearEq(double b, double c, double* x1, double* x2);
void Clear_Buffer();
void Manager_InputTests_by_data();
void Manager_InputFunc_by_keyboard();

//-----------------------------------------------

int main()
{
    setlocale(LC_ALL, "Rus");   //сделать интерфейс для выбора

    Manager_InputTests_by_data();
    //Manager_InputFunc_by_keyboard();


    //Manager_SqrSolution();          // квадратка


    return 0;
}

//-----------------------------------------------

void InputFunc(double* a, double* b, double* c)
{
int num = 0;
while (num != 3)
    {
        printf( "Введите значения коэффициэнтов\n"
                "квадратного уравнения:\n");
        num = scanf("%lg %lg %lg", a, b, c);

        if (num != 3)
        {
            Clear_Buffer();       //1 -2 1a
        }
    }
}

//-----------------------------------------------

void Manager_SqrSolution()
{
    int key = 1;  // <-- enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        InputFunc(&a, &b, &c);

        int res = SqrSolution(a, b, c, &x1, &x2);

        OutputFun_SS(res, x1, x2);

        Restart(&key);
    }

}

//-----------------------------------------------

void Clear_Buffer()
{
    while(getchar() != '\n') {}     //EOF, символ isspace()
}

//-----------------------------------------------

int SqrSolution(const double a, const double b, const double c, double* const x1, double* const x2)    // struct NAN
{

    if (! DoubleEqual(a, 0))
    {
        return SqrEq(a,b,c,x1,x2);
    }
    else
    {
        return LinearEq(b, c, x1, x2);
    }
}

//-----------------------------------------------

int SqrEq(double a, double b, double c, double* x1, double* x2)   //struct
{
    double d = Diskr(a, b, c);

    if (DoubleEqual(d, 0))
    {
        *x1 = *x2 = -(b / (2 * a));
        return ROOTS_1;
    }
    else if (d > 0)
    {
        d = sqrt(d) / 2 / a;
        b = -b / a / 2;
        *x1 = b - d;
        *x2 = b + d;
        return ROOTS_2;
    }
    else
    {
        return ROOTS_0;
    }
}

//-----------------------------------------------

int LinearEq(double b, double c, double* x1, double* x2)   //struct
{
    if (! DoubleEqual(b, 0))
    {
        *x1 = *x2 = (-c / b);
        return ROOTS_1;
    }
    else
    {
        if (! DoubleEqual(c, 0))
        {
            return ROOTS_0;
        }
        else
        {
            return ROOTS_INF;
        }
    }
}

//-----------------------------------------------

double Diskr(const double a,const double b,const double c)
{
    return b*b - 4*a*c;
}

//-----------------------------------------------

void OutputFun_SS(const int res,const double x1,const double x2)  //struct
{
    switch (res)
    {
    case ROOTS_0: printf("Нет решений\n\n");
            break;

    case ROOTS_1: printf("Корень уравнения: %.2lg\n\n",x1);
            break;

    case ROOTS_2: printf("Корни уравнения: %.2lg и %.2lg\n\n", x1, x2);
            break;

    case ROOTS_INF: printf("Бесконечность решений\n");
            break;

    default: printf("error\n");
    }
}

//-----------------------------------------------

int DoubleEqual(const double a, const double b)         //!
{
    return fabs(a - b) < e;
}

//-----------------------------------------------

int Restart( int* const key)
{
    while (*key != 1 && *key != 0)
    {
    printf("Продолжть[ 1 ]\n"
            "Остановить[ 0 ]\n");
    Clear_Buffer();
    scanf("%d", key);
    }

    return 0; //?
}

//-----------------------------------------------

void RunTest( const TestStr* const test)    //тест
{
    double x1 = DOUBLE_NULL, x2 = DOUBLE_NULL;
    const int nRoots = SqrSolution((*test).a,(*test).b, (*test).c,&x1, &x2);

    if (!(DoubleEqual(x1,(*test).x1_exp)) || !(DoubleEqual(x2,(*test).x2_exp)) || nRoots != (*test).nRoots_exp) //func, сравнить корни, ->
    {
        printf("\nError\n------------------\na = %.2lg, b = %.2lg, c = %.2lg\n"
                "      x1    x2\nExp   %-6.2lg%-6.2lg%-6d\nRes   %-6.2lg%-6.2lg%-6d\n------------------\n",
                (*test).a, (*test).b, (*test).c,
                (*test).x1_exp, (*test).x2_exp, (*test).nRoots_exp, x1, x2, nRoots);  //\t
    }
    else
    {
        printf("\nperfect!\n\n");
    }

}

//-----------------------------------------------

void Manager_InputTests_by_data()
{
    for ( unsigned int i = 0; i < sizeof(Tests_Data)/sizeof(Tests_Data[0]) ; i++)
    {
        printf("Test №%d", i+1);
        RunTest(&Tests_Data[i]);
    }

}

//-----------------------------------------------

void Manager_InputFunc_by_keyboard()    //ввод тестов с клавы
{
    int key = 1;        //enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        TestStr testing;

        printf("Введите три коэффициента квадратного уравнения,\n"
                "верные корни этого уравнения и количество различных\n"
                "значений корня последовательно:\n");
        scanf("%lg %lg %lg %lg %lg %d", &testing.a, &testing.b, &testing.c,&testing.x1_exp, &testing.x2_exp, &testing.nRoots_exp);

        RunTest(&testing);

        Restart(&key);
    }
}

//-----------------------------------------------

//компиляция в файлах
//оптимизировать вывод
//assert(x1!= NULL);
// %c в конце ввода
//оптимизировать ввод (ввод -> счёт -> вывод), цикл в вводе   \/
//чтение файла
//текстовый ввод
//NUN, NULL
//структуры
//енам (enum)    \/
//doxygen
//тесты с массивом      \/
// аргументы командной строки + работа из консоли.
//asci последовательность

//assert
//header files
