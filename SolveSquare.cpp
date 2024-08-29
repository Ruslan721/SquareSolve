
#include "SqrHeader.h"

#include <cstdio>

//-----------------------------------------------

void Input_Sqr_Solution(Equality_Coeff* const Sqr_Input)       //->                 //(*test).a
{
    assert(Sqr_Input != 0);

    int num = 0, Flag = -1;
    while (Flag == -1)
    {

        printf( "\nВведите значения коэффициэнтов\n"
                "квадратного уравнения:\n\n");
        num = scanf("%lg %lg %lg", &(Sqr_Input->a), &(Sqr_Input->b), &(Sqr_Input->c));   //?

        if (num == 3)
        {
            Flag = 1;       //1 -2 1a     //если 1 то continue
        }

        Find_Symbol_In_Buffer(&Flag);

    }
}

//-----------------------------------------------
                                                                     //TestStr
 void Manager_Sqr_Solution()
{
    int key = 1;  // <-- enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;
        Equality Sqr_Input = {{NAN, NAN, NAN}, {NOT_A_ROOT, NOT_A_ROOT, -1}};

        Input_Sqr_Solution(&Sqr_Input.coeff);

        int res = Sqr_Solution(&Sqr_Input);

        Output_Sqr_Solution(res, &Sqr_Input);

        Restart(&key);
    }

}

//-----------------------------------------------

int Sqr_Solution(Equality* const Sqr_Input)    // struct, NAN
{
    assert(Sqr_Input);

    if (! Double_Equal(Sqr_Input->coeff.a, 0))
    {
        return Sqr_Equality(Sqr_Input);
    }
    else
    {
        return Linear_Equality(Sqr_Input);
    }
}

//-----------------------------------------------

int Sqr_Equality(Equality* const Sqr_Input)   //struct
{
    assert(Sqr_Input != 0);

    double* x1 = &(Sqr_Input->roots.x1);
    double* x2 = &(Sqr_Input->roots.x2);

    const double d = Diskr(Sqr_Input->coeff.a, Sqr_Input->coeff.b, Sqr_Input->coeff.c);

    if (Double_Equal(d, 0))
    {
        *x1 = *x2 = -(Sqr_Input->coeff.b / (2 * Sqr_Input->coeff.a));
        return ROOTS_ONE;
    }
    else if (d > EPS)
    {
        const double new_d = sqrt(d) / 2 / Sqr_Input->coeff.a;
        const double new_b = -Sqr_Input->coeff.b / Sqr_Input->coeff.a / 2;
        *x1 = new_b - new_d;
        *x2 = new_b + new_d;
        return ROOTS_TWO;
    }
    else
    {
        return ROOTS_ZERO;
    }
}

//-----------------------------------------------

int Linear_Equality(Equality* const Sqr_Inut)   //struct
{
    assert(Sqr_Inut != 0);

    if (! Double_Equal(Sqr_Inut->coeff.b, 0))
    {
        Sqr_Inut->roots.x1 = Sqr_Inut->roots.x2 = (-Sqr_Inut->coeff.c / Sqr_Inut->coeff.b);
        return ROOTS_ONE;
    }
    else
    {
        if (! Double_Equal(Sqr_Inut->coeff.c, 0))
        {
            return ROOTS_ZERO;
        }
        else
        {
            return ROOTS_INF;
        }
    }
}

//-----------------------------------------------

void Output_Sqr_Solution(const int res, Equality* const Sqr_Input)  //struct
{
    assert(Sqr_Input != 0);

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
