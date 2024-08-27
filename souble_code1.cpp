

#include "SqrHeader.h"


const double EPS = 1e-20;

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
                                                //очистка буфера
void Clear_All_Buffer()     //int
{
    int Clear_Reader = 0;
    while((Clear_Reader = getchar()) != '\n'  && Clear_Reader != EOF) {}


         //EOF, символ isspace()   //Если не пробел - ретерн 1 ; 0                         //Clear_Buffer
}   //вне цикла флажок

//-----------------------------------------------
                                                //поиск текстовых символов
int Find_Evil_In_Buffer(int* OptionNum)
{
    char Checker;
    if ( isspace(Checker = getchar()) == 0)
    {
        Clear_All_Buffer();

        *OptionNum = -1;      //enum
        return -1;
    }
    else if (Checker != '\n')
    {
        Find_Evil_In_Buffer(OptionNum);
    }

    return 1;
}


//-----------------------------------------------

double Diskr(const double a,const double b,const double c)
{
    return b*b - 4*a*c;
}

//-----------------------------------------------

int DoubleEqual(const double a, const double b) //!
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
{                                         //исправить
    while (*key != 1 && *key != 0)
    {
        printf( "\nПродолжть[ 1 ]\n"
                "Выход[ 0 ]\n\n");

        double Scanf_Helper = -1;

        int Count = scanf("%lg",&Scanf_Helper);

        *key = int(Scanf_Helper);

        printf("%d", *key);

        if ((! DoubleEqual(Scanf_Helper, *key)) || Count != 1)
        {
            *key = -1;
        }

        Find_Evil_In_Buffer(key);  //?
    }

    printf("%d", *key);

    return 0;
}

//-----------------------------------------------

//Исправить защиту ввода
//.bat    \/
//компиляция в файлах      \/
//оптимизировать вывод
//assert(x1!= NULL);
// %c в конце ввода
//оптимизировать ввод (ввод -> счёт -> вывод), цикл в вводе   \/
//чтение файла
//текстовый ввод
//NUN, NULL
//структуры               \/
//енам (enum)    \/
//doxygen
//тесты с массивом      \/
// аргументы командной строки + работа из консоли.       \/
//asci последовательность

//assert
//header files                 \/

//выход из функции в компеяторе      \/
