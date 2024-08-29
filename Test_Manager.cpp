
#include "SqrHeader.h"

const Equality TEST_DATA [] =     //const
    {                                                 //Clear_Buffer       //g++ -c Test_Manager.c -o Test_Manager.o
     {{1,    1,    1}, {NOT_A_ROOT, NOT_A_ROOT, ROOTS_ZERO}},
     {{1,   -4,    4}, {         2,          2,  ROOTS_ONE}},
     {{0,    0,    0}, {NOT_A_ROOT, NOT_A_ROOT,  ROOTS_INF}},
     {{1,   -3,    2}, {         1,          2,  ROOTS_TWO}},
     {{0,    1,   -2}, {         2,          2,  ROOTS_ONE}},
     {{0,    0,    1}, {NOT_A_ROOT, NOT_A_ROOT, ROOTS_ZERO}},
     {{1, -0.4, 0.04}, {       0.2,        0.2,  ROOTS_ONE}} //+веществ
    };

//  ввод

//-----------------------------------------------

void Input_Input_Func_by_keyboard(Equality* const testing)       //->                 //(*test).a
{
    assert(testing != 0);

    int Help_Counter = 0, Flag = -1;
    while (Flag == -1)
    {

        printf("\n¬ведите три коэффициента квадратного уравнени€,\n"
                "верные корни этого уравнени€ и количество различных\n"
                "значений корн€ последовательно:\n\n");
        int Help_Counter = scanf("%lg %lg %lg %lg %lg %d", &testing->coeff.a, &testing->coeff.b, &testing->coeff.c,
                                                        &testing->roots.x1, &testing->roots.x2, &testing->roots.nRoots);

        if (testing->roots.x1 > testing->roots.x2)
        {
            testing->roots.x1 = testing->roots.x1+testing->roots.x2;
            testing->roots.x2 = testing->roots.x1-testing->roots.x2;
            testing->roots.x1 = testing->roots.x1-testing->roots.x2;
        }

        if (Help_Counter == 6)
        {
            Flag = 1;       //1 -2 1a     //если 1 то continue
        }

        Find_Symbol_In_Buffer(&Flag);

    }
}

//-----------------------------------------------
                                                                      //на самом еле это ввод
void Manager_Input_Func_by_keyboard()    //ввод тестов с клавы
{
    int key = 1;        //enum
    while (key == 1 || key == 1)
    {
        if (key == 0)
            break;
        key = -1;

        Equality testing = {{NAN, NAN, NAN}, {NOT_A_ROOT, NOT_A_ROOT, -1}};

        Input_Input_Func_by_keyboard(&testing);

        Run_Test(&testing);

        Restart(&key);
    }
}

//-----------------------------------------------
                                                                    //два менеджера
void Manager_Input_Tests_by_data()
{
    for (unsigned int i = 0; i < sizeof(TEST_DATA)/sizeof(TEST_DATA[0]) ; i++)
    {
        printf("\nTest є%d", i+1);
        Run_Test(&TEST_DATA[i]);
    }

}

//-----------------------------------------------
                                                               //на самом деле это вывод
void Run_Test( const Equality* const test)    //тест
{
    assert(test != 0);

    Equality Coeff_TESTS = {test->coeff, {NOT_A_ROOT, NOT_A_ROOT, -1}};

    Coeff_TESTS.roots.nRoots = Sqr_Solution(&Coeff_TESTS);

    if (! (Double_Equal(Coeff_TESTS.roots.x1,test->roots.x1)) || ! (Double_Equal(Coeff_TESTS.roots.x2, test->roots.x2))
                                                                     || Coeff_TESTS.roots.nRoots != test->roots.nRoots)
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
