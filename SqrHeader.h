
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

struct Equ_Coeff
{
    double a, b, c;
};

struct Equ_Roots
{
    double x1, x2;
    int nRoots;
};

struct Equ
{
    Equ_Coeff coeff;
    Equ_Roots roots;
};

const double NOT_A_ROOT = 0;
                        //Clear_Buffer

const int TESTS_COUNT = 6;

enum SqrConstants
{
    ROOTS_ZERO  =  0,
    ROOTS_ONE   =  1,
    ROOTS_TWO   =  2,
    ROOTS_INF   =  -1

};


int Find_Evil_In_Buffer(int* OptionNum);
void Manager_SqrSolution();
void Input_SqrSolution(Equ* const Sqr_Input);
int SqrSolution(Equ* const Sqr_Input);
void Output_SqrSolution(int res, Equ* const Sqr_Input);
double Diskr(double const a, double const b, double const c);
int DoubleEqual(double const a, double const b);
int Restart( int* const key);
void RunTest(const  Equ* const test);
void InputTests_by_data();
void InputFunc_by_keyboard();
int SqrEq(Equ* const Sqr_Input);
int LinearEq(Equ* Sqr_Inut);
void Clear_All_Buffer();
void Manager_InputTests_by_data();
void Manager_InputFunc_by_keyboard();



