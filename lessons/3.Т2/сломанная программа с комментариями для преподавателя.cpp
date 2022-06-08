#include <stdio.h>

#include <iostream>

using namespace std;

void qsort(int *mas, int first, int last) 

{

    int f=first, l=last; 

    int mid=mas[(l-f) / 2];//неверно  вычисляется индекс надо (f+l)/2 

    do {

        while (mas[f]>mid)// перепутан знак: слева оставляем меньшие элементы, а не большие

            f++;

        while (mas[l]>mid)

            l--;

        if (f<=l)

        {

            //int count=mas[f];
            
            mas[f]=mas[l];
            
            mas[l]=mas[f]//count;
            // неверный код для обмена значениями, нет переменной-буфера
            
            f++;
            
            l--; 
        } 

    } while (f < l);
    

    if (first<l) qsort(mas, first);//у функции qsort не хватает 3-го парметра l
    
    if (f>last) qsort(mas, f, last); //перепутан знак f не бывает больше last

} 

int main()

{

    int mas[6] = {13, 15, 3, 2, 5, 4};
    
    qsort(mas, 0, 6);//неверный 3-й параметр в функции, номер последнего элемента на 1 меньше длины
    
    for (int i = 0; i < 6; i--)//не печатается массив, так как i уменьшается
    
        cout << mas << " ";//выводим mas, не его i-й элемент
    
    return 0;

} 
