
#include "SqrHeader.h"

#include <cstdio>

//-----------------------------------------------

void Input_SqrSolution(Equ_Coeff* Sqr_Input)       //->                 //(*test).a
{

int num = 0, Flag = -1;
while (num != 3 && Flag)
    {
        printf( "\nВведите значения коэффициэнтов\n"
                "квадратного уравнения:\n\n");
        num = scanf("%lg %lg %lg", &(Sqr_Input->a), &(Sqr_Input->b), &(Sqr_Input->c));   //?

        if (num != 3)
        {
            Clear_All_Buffer();       //1 -2 1a     //если 1 то continue
        }

        Find_Evil_In_Buffer(&Flag);
    }
}

//-----------------------------------------------
                                                                     //TestStr
 void Manager_SqrSolution()
{
    int key = 1;  // <-- enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;
        Equ Sqr_Input = {{NAN, NAN, NAN}, {NOT_A_ROOT, NOT_A_ROOT, -1}};

        Input_SqrSolution(&Sqr_Input.coeff);

        int res = SqrSolution(&Sqr_Input);

        Output_SqrSolution(res, &Sqr_Input);

        Restart(&key);
    }

}

//-----------------------------------------------

int SqrSolution(Equ* const Sqr_Input)    // struct, NAN
{

    if (! DoubleEqual(Sqr_Input->coeff.a, 0))
    {
        return SqrEq(Sqr_Input);
    }
    else
    {
        return LinearEq(Sqr_Input);
    }
}

//-----------------------------------------------

int SqrEq(Equ* const Sqr_Input)   //struct
{
    double* x1 = &(Sqr_Input->roots.x1);
    double* x2 = &(Sqr_Input->roots.x2);

    double d = Diskr(Sqr_Input->coeff.a, Sqr_Input->coeff.b, Sqr_Input->coeff.c);

    if (DoubleEqual(d, 0))
    {
        *x1 = *x2 = -(Sqr_Input->coeff.b / (2 * Sqr_Input->coeff.a));
        return ROOTS_ONE;
    }
    else if (d > 0)
    {
        double new_d = sqrt(d) / 2 / Sqr_Input->coeff.a;
        double new_b = -Sqr_Input->coeff.b / Sqr_Input->coeff.a / 2;
        *x1 = new_b - new_d;
        *x2 = new_b + new_d;
        return ROOTS_TWO;
    }
    else
    {
        return ROOTS_ZERO;

        *x1 = *x2 = NOT_A_ROOT;
    }
}

//-----------------------------------------------

int LinearEq(Equ* Sqr_Inut)   //struct
{
    if (! DoubleEqual(Sqr_Inut->coeff.b, 0))
    {
        Sqr_Inut->roots.x1 = Sqr_Inut->roots.x2 = (-Sqr_Inut->coeff.c / Sqr_Inut->coeff.b);
        return ROOTS_ONE;
    }
    else
    {
        if (! DoubleEqual(Sqr_Inut->coeff.c, 0))
        {
            return ROOTS_ZERO;

            Sqr_Inut->roots.x1 = Sqr_Inut->roots.x2 = NOT_A_ROOT;
        }
        else
        {
            return ROOTS_INF;

            Sqr_Inut->roots.x1 = Sqr_Inut->roots.x2 = NOT_A_ROOT;
        }
    }
}

//-----------------------------------------------

void Output_SqrSolution(int res, Equ* const Sqr_Input)  //struct
{
    switch (res)
    {
    case ROOTS_ZERO: printf("\nНет решений\n");
            break;

    case ROOTS_ONE: printf("\nКорень уравнения: %.2lg\n", Sqr_Input->roots.x1);
            break;

    case ROOTS_TWO: printf("\nКорни уравнения: %.2lg и %.2lg\n", Sqr_Input->roots.x1, Sqr_Input->roots.x2);
            break;

    case ROOTS_INF: printf("\nБесконечность решений\n");
            break;

    default: printf("\nerror\n\n");
    }
}

//-----------------------------------------------
