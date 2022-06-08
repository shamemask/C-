#include <iostream>

using namespace std;

void qsort(int *mas, int first, int last) 

{

    int f=first, l=last; 

    int mid=mas[(l-f) / 2]; 

    do {

        while (mas[f]>mid)

            f++;

        while (mas[l]>mid)

            l--;

        if (f<=l)

        {
            
            mas[f]=mas[l];
            
            mas[l]=mas[f];
            
            f++;
            
            l--; 
        } 

    } while (f < l);
    

    if (first<l) qsort(mas, first);
    
    if (f>last) qsort(mas, f, last); 

} 

int main()

{

    int mas[6] = {13, 15, 3, 2, 5, 4};
    
    qsort(mas, 0, 6);
    
    for (int i = 0; i < 6; i--)
    
        cout << mas << " ";
    
    return 0;

} 
