#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>
#include <assert.h>

struct Equality_Coeff
{
    double a, b, c;
};

struct Equality_Roots
{
    double x1, x2;
    int nRoots;
};

struct Equality
{
    Equality_Coeff coeff;
    Equality_Roots roots;
};

const double EPS = 1e-10;

const double NOT_A_ROOT = 0;
                        //Clear_Buffer


enum Sqr_Constants
{
    ROOTS_ZERO  =  0,
    ROOTS_ONE   =  1,
    ROOTS_TWO   =  2,
    ROOTS_INF   =  -1

};

void Quadratka_Programm();
void Select_Menu(int OptionNum);
int Find_Symbol_In_Buffer(int* const OptionNum);
void Manager_Sqr_Solution();
void Input_Sqr_Solution(Equality* const Sqr_Input);
int Sqr_Solution(Equality* const Sqr_Input);
void Output_Sqr_Solution(const int res, Equality* const Sqr_Input);
double Diskr(const double  a, const double b, const double c);
int Double_Equal(const double a, const double b);
int Restart(int* const key);
void Run_Test(const Equality* const test);
void Input_Tests_by_data();
void Input_Func_by_keyboard();
int Sqr_Equality(Equality* const Sqr_Input);
int Linear_Equality(Equality* const Sqr_Inut);
void Clear_All_Buffer();
void Manager_Input_Tests_by_data();
void Manager_Input_Func_by_keyboard();
void Input_Input_Func_by_keyboard(Equality* const testing);
