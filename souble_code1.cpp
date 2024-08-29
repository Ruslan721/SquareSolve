
#include "SqrHeader.h"



//-----------------------------------------------

int main()      //g++ -c souble_code1.c -o souble_code1.o
                //g++ souble_code1.o Test_Manager.o
{

    setlocale(LC_ALL, "Rus");   //сделать интерфейс для выбора   \/

    Quadratka_Programm();

    return 0;
}

//-----------------------------------------------

void Quadratka_Programm()
{
    int OptionNum = 0;
    printf( "\nВыберите опцию:\n\n"
            "Тест квадратки [ 1 ]\n"
            "Тест квадратки с клавиатуры [ 2 ]\n"
            "Квадратка [ 3 ]\n"
            "Выход [ 0 ]\n\n" );

    double Scanf_Helper = -1;
    scanf("%lg",&Scanf_Helper);

    OptionNum = int(Scanf_Helper);

    if (! Double_Equal(Scanf_Helper, OptionNum))
    {
        OptionNum = -1;
    }

    Find_Symbol_In_Buffer(&OptionNum);    //ошибка -

    Select_Menu(OptionNum);
}

//-----------------------------------------------

void Select_Menu(int OptionNum)
{
    switch (OptionNum)
        {
        case 0: break;

        case 1: Manager_Input_Tests_by_data();
                Quadratka_Programm();
                break;

        case 2: Manager_Input_Func_by_keyboard();
                Quadratka_Programm();
                break;

        case 3: Manager_Sqr_Solution();   //не работает с вещ.
                Quadratka_Programm();
                break;

        default:main();
                break;
        }
}

//-----------------------------------------------
                                                //очистка буфера
void Clear_All_Buffer()     //int
{
    int Clear_Reader = 0;
    while((Clear_Reader = getchar()) != '\n' && Clear_Reader != EOF) {}
}

//-----------------------------------------------
                                                //поиск текстовых символов
int Find_Symbol_In_Buffer(int* const OptionNum)
{
    assert(OptionNum != 0);

    int Checker = 0;
    if ( isspace(Checker = getchar()) == 0)
    {
        Clear_All_Buffer();

        *OptionNum = -1;      //enum
        return -1;
    }
    else if (Checker != '\n')
    {
        Find_Symbol_In_Buffer(OptionNum);
    }

    return 1;
}


//-----------------------------------------------

double Diskr(const double a,const double b,const double c)
{
    return b*b - 4*a*c;
}

//-----------------------------------------------

int Double_Equal(const double a, const double b) //!
{
    return fabs(a - b) < EPS;
}

//-----------------------------------------------

/*                                              //вспомогательный цикл
    double key = 1;                    //enum
    while (key == 1 || key == 0)
    {
        if (key == 0)
            break;
        key = -1;
*/
int Restart( int* const key)
{
    assert(key != 0);

    while (*key != 1 && *key != 0)
    {
        printf( "\nПровторить[ 1 ]\n"
                "Выход[ 0 ]\n\n");

        double Scanf_Helper = -1;

        int Count = scanf("%lg",&Scanf_Helper);

        *key = int(Scanf_Helper);

        if ((! Double_Equal(Scanf_Helper, *key)) || Count != 1)
        {
            *key = -1;
        }

        Find_Symbol_In_Buffer(key);  //?
    }

    return 0;
}

//-----------------------------------------------

//Исправить защиту ввода
//.bat    \/
//компиляция в файлах      \/
//оптимизировать вывод    \/
//assert(x1!= NULL);  \/
// %c в конце ввода
//оптимизировать ввод (ввод -> счёт -> вывод), цикл в вводе   \/
//чтение файла
//текстовый ввод
//NUN, NULL    \/
//структуры               \/
//енам (enum)    \/
//doxygen
//тесты с массивом      \/
// аргументы командной строки + работа из консоли.       \/
//asci последовательность

//assert
//header files                 \/

//выход из функции в компеяторе      \/
