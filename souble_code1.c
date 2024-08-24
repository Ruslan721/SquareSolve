/*#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>  */

#include "SqrTest.h"

/*struct TestStr
{
    double a, b, c;
    double x1_exp, x2_exp;
    int nRoots_exp;
};  */

/*const double DOUBLE_NULL = 0.0;*/

/*enum SqrConstants
{
    ROOTS_ZERO   =  0,
    ROOTS_ONE   =  1,
    ROOTS_TWO   =  2,
    ROOTS_INF = -1

}; */

const double EPS = 1e-20;

/*const TestStr TEST_DATA [6] =
    {
     {1,  1,  1, DOUBLE_NULL, DOUBLE_NULL, ROOTS_ZERO},
     {1, -4,  4, 2, 2, ROOTS_ONE},
     {0,  0,  0, DOUBLE_NULL, DOUBLE_NULL, ROOTS_INF},
     {1, -3,  2, 1, 2, ROOTS_TWO},
     {0,  1, -2, 2, 2, ROOTS_ONE},
     {0,  0,  1, DOUBLE_NULL, DOUBLE_NULL, ROOTS_ZERO} //+веществ
    };*/

/*void Manager_SqrSolution();
void InputFunc(double* const a, double* const b, double* const c);
int SqrSolution(double const a, double const b, double const c, double* const x1, double* const x2);
void OutputFun_SS(const int res,const double x1,const double x2);
double Diskr(double const a, double const b, double const c);
int DoubleEqual(double const a, double const b);
int Restart(double* const key);
void RunTest( const TestStr* const test);
void InputTests_by_data();
void InputFunc_by_keyboard();
int SqrEq(const double a, const double b, const double c, double* const x1, double* const x2);
int LinearEq(const double b, const double c, double* const x1, double* const x2);
void Clear_All_Buffer();
void Manager_InputTests_by_data();
void Manager_InputFunc_by_keyboard(); */             //исправить конст в программах

//-----------------------------------------------

int main()      //g++ -c souble_code1.c -o souble_code1.o
                //g++ souble_code1.o Test_Manager.o
{
    setlocale(LC_ALL, "Rus");   //сделать интерфейс для выбора   \/

    int OptionNum = 0;
    printf( "\nВыберите опцию:\n\n"
            "Тест квадратки [ 1 ]\n"
            "Тест квадратки с клавиатуры [ 2 ]\n"
            "Квадратка [ 3 ]\n"
            "Выход [ 0 ]\n\n" );

    double Scanf_Helper = -1;
    scanf("%lg",&Scanf_Helper);

    OptionNum = int(Scanf_Helper);

    if (! DoubleEqual(Scanf_Helper, OptionNum))
    {
        OptionNum = -1;
    }

    Find_Evil_In_Buffer(&OptionNum);    //ошибка -

    /**while (true)
    {

         char Checker;
        if (! DoubleEqual(Scanf_Helper, OptionNum) || isspace(Checker = getchar()) == 0)
        {
            OptionNum = -1;

            Clear_Buffer();

            break;
        }
        else if (Checker == '\n')
        {
            break;
        }
    }   */

    switch (OptionNum)
    {
    case 0: break;

    case 1: Manager_InputTests_by_data();
            main();
            break;

    case 2: Manager_InputFunc_by_keyboard();
            main();
            break;

    case 3: Manager_SqrSolution();   //не работает с вещ.
            main();
            break;

    default:main();
            break;
    }

    //Manager_InputTests_by_data();
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
        printf( "\nВведите значения коэффициэнтов\n"
                "квадратного уравнения:\n\n");
        num = scanf("%lg %lg %lg", a, b, c);

        if (num != 3)
        {
            Clear_All_Buffer();       //1 -2 1a     //если 1 то continue
        }
    }
}

//-----------------------------------------------

void Manager_SqrSolution()
{
    double key = 1;  // <-- enum
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

void Clear_All_Buffer()     //int
{
    char Clear_Reader;
    while((Clear_Reader = getchar()) != '\n'  || Clear_Reader != EOF) {}


         //EOF, символ isspace()   //Если не пробел - ретерн 1 ; 0                         //Clear_Buffer
}   //вне цикла флажок

//-----------------------------------------------

int Find_Evil_In_Buffer(int* OptionNum)
{
    char Checker;
    if ( isspace(Checker = getchar()) == 0)
    {
        Clear_All_Buffer();

        *OptionNum = -1;
        return -1;
    }
    else if (Checker != '\n')
    {
        Find_Evil_In_Buffer(OptionNum);
    }

    return 1;
}

//-----------------------------------------------

int SqrSolution(const double a, const double b, const double c, double* const x1, double* const x2)    // struct, NAN
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
        return ROOTS_ONE;
    }
    else if (d > 0)
    {
        d = sqrt(d) / 2 / a;
        b = -b / a / 2;
        *x1 = b - d;
        *x2 = b + d;
        return ROOTS_TWO;
    }
    else
    {
        return ROOTS_ZERO;

        *x1 = *x2 = NAN;
    }
}

//-----------------------------------------------

int LinearEq(double b, double c, double* x1, double* x2)   //struct
{
    if (! DoubleEqual(b, 0))
    {
        *x1 = *x2 = (-c / b);
        return ROOTS_ONE;
    }
    else
    {
        if (! DoubleEqual(c, 0))
        {
            return ROOTS_ZERO;

            *x1 = *x2 = NAN;
        }
        else
        {
            return ROOTS_INF;

            *x1 = *x2 = NAN;
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
    case ROOTS_ZERO: printf("\nНет решений\n");
            break;

    case ROOTS_ONE: printf("\nКорень уравнения: %.2lg\n",x1);
            break;

    case ROOTS_TWO: printf("\nКорни уравнения: %.2lg и %.2lg\n", x1, x2);
            break;

    case ROOTS_INF: printf("\nБесконечность решений\n");
            break;

    default: printf("\nerror\n\n");
    }
}

//-----------------------------------------------

int DoubleEqual(const double a, const double b)         //!
{
    return fabs(a - b) < EPS;
}

//-----------------------------------------------

int Restart( double* const key)
{
    while (*key != 1 && *key != 0)
    {
    printf( "\nПродолжть[ 1 ]\n"
            "Выход[ 0 ]\n\n");

    getchar() ;
    scanf("%lg", key);
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
        printf("\nperfect!\n");
    }

}

//-----------------------------------------------

/* void Manager_InputTests_by_data()
{
    for ( unsigned int i = 0; i < sizeof(TEST_DATA)/sizeof(TEST_DATA[0]) ; i++)
    {
        printf("\nTest №%d", i+1);
        RunTest(&TEST_DATA[i]);
    }

}

//-----------------------------------------------

void Manager_InputFunc_by_keyboard()    //ввод тестов с клавы
{
    double key = 1;        //enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        TestStr testing;

        printf("\nВведите три коэффициента квадратного уравнения,\n"
                "верные корни этого уравнения и количество различных\n"
                "значений корня последовательно:\n\n");
        scanf("%lg %lg %lg %lg %lg %d", &testing.a, &testing.b, &testing.c,&testing.x1_exp, &testing.x2_exp, &testing.nRoots_exp);

        RunTest(&testing);

        Restart(&key);
    }
}     */

//-----------------------------------------------

//.bat
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

//выход из функции в компеяторе
