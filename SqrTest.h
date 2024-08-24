
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

struct TestStr
{
    double a, b, c;
    double x1_exp, x2_exp;
    int nRoots_exp;
};
                           //Clear_Buffer
enum SqrConstants
{
    ROOTS_ZERO  =  0,
    ROOTS_ONE   =  1,
    ROOTS_TWO   =  2,
    ROOTS_INF   =  -1

};

const double DOUBLE_NULL = 0.0;

int Find_Evil_In_Buffer(int* OptionNum);
void Manager_SqrSolution();
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
void Manager_InputFunc_by_keyboard();
