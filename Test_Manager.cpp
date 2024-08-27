
#include "SqrHeader.h"

const double DOUBLE_NULL = 0.0;

const Equ TEST_DATA [TESTS_COUNT] =     //const
    {                                                 //Clear_Buffer       //g++ -c Test_Manager.c -o Test_Manager.o
     {{1,  1,  1}, {NOT_A_ROOT, NOT_A_ROOT, ROOTS_ZERO}},
     {{1, -4,  4},    {      2,          2,  ROOTS_ONE}},
     {{0,  0,  0}, {NOT_A_ROOT, NOT_A_ROOT,  ROOTS_INF}},
     {{1, -3,  2},      {   1,          2,  ROOTS_TWO}},
     {{0,  1, -2},      {   2,          2,  ROOTS_ONE}},
     {{0,  0,  1}, {NOT_A_ROOT, NOT_A_ROOT, ROOTS_ZERO}} //+веществ
    };

//  ввод

//-----------------------------------------------
                                                                      //на самом еле это ввод
void Manager_InputFunc_by_keyboard()    //ввод тестов с клавы
{
    int key = 1;        //enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        Equ testing = {{NAN, NAN, NAN}, {NOT_A_ROOT, NOT_A_ROOT, -1}};

        printf("\n¬ведите три коэффициента квадратного уравнени€,\n"
                "верные корни этого уравнени€ и количество различных\n"
                "значений корн€ последовательно:\n\n");
        int Help_Counter = scanf("%lg %lg %lg %lg %lg %d", &testing.coeff.a, &testing.coeff.b, &testing.coeff.c,&testing.roots.x1, &testing.roots.x2, &testing.roots.nRoots);


        RunTest(&testing);     //сделать проверку

        Restart(&key);
    }
}

//-----------------------------------------------
                                                                    //два менеджера
void Manager_InputTests_by_data()
{
    for (unsigned int i = 0; i < sizeof(TEST_DATA)/sizeof(TEST_DATA[0]) ; i++)
    {
        printf("\nTest є%d", i+1);
        RunTest(&TEST_DATA[i]);
    }

}

//-----------------------------------------------
                                                               //на самом деле это вывод
void RunTest( const Equ* const test)    //тест
{
    // double DOUBLE_NULL = 0.0;

    Equ Coeff_TESTS = {test->coeff, {NOT_A_ROOT, NOT_A_ROOT, -1}};

    Coeff_TESTS.roots.nRoots = SqrSolution(&Coeff_TESTS);

    if (! (DoubleEqual(Coeff_TESTS.roots.x1,test->roots.x1)) ||  ! (DoubleEqual(Coeff_TESTS.roots.x2, test->roots.x2)) || Coeff_TESTS.roots.nRoots != test->roots.nRoots) //func, сравнить корни, ->
    {
        printf("\nError\n------------------\na = %.2lg, b = %.2lg, c = %.2lg\n"
                "      x1    x2\nExp   %-6.2lg%-6.2lg%-6d\nRes   %-6.2lg%-6.2lg%-6d\n------------------\n",
                test->coeff.a, test->coeff.b, test->coeff.c,
                test->roots.x1, test->roots.x2, test->roots.nRoots, Coeff_TESTS.roots.x1, Coeff_TESTS.roots.x2, Coeff_TESTS.roots.nRoots);  //\t  ->
    }
    else
    {
        printf("\nperfect!\n");
    }

}

//-----------------------------------------------

// вывод
