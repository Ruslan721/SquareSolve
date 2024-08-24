
#include <stdio.h>
#include "SqrTest.h"

const TestStr TEST_DATA [6] =
    {                                                 //Clear_Buffer       //g++ -c Test_Manager.c -o Test_Manager.o
     {1,  1,  1, NAN, NAN, ROOTS_ZERO},
     {1, -4,  4, 2, 2, ROOTS_ONE},
     {0,  0,  0, NAN, NAN, ROOTS_INF},
     {1, -3,  2, 1, 2, ROOTS_TWO},
     {0,  1, -2, 2, 2, ROOTS_ONE},
     {0,  0,  1, NAN, NAN, ROOTS_ZERO} //+веществ
    };

void Manager_InputTests_by_data()
{
    for ( unsigned int i = 0; i < sizeof(TEST_DATA)/sizeof(TEST_DATA[0]) ; i++)
    {
        printf("\nTest є%d", i+1);
        RunTest(&TEST_DATA[i]);
    }

}

void Manager_InputFunc_by_keyboard()    //ввод тестов с клавы
{
    double key = 1;        //enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;

        TestStr testing = {NAN, NAN, NAN, NAN, NAN, -1};

        printf("\n¬ведите три коэффициента квадратного уравнени€,\n"
                "верные корни этого уравнени€ и количество различных\n"
                "значений корн€ последовательно:\n\n");
        int Help_Counter = scanf("%lg %lg %lg %lg %lg %d", &testing.a, &testing.b, &testing.c,&testing.x1_exp, &testing.x2_exp, &testing.nRoots_exp);

        RunTest(&testing);

        Restart(&key);
    }
}
