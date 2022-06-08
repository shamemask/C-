#include <iostream>

using namespace std;

void qsort(int *mas, int first, int last) 

{

    int f=first, l=last; 

    int mid=mas[(f+l) / 2]; 

    do {

        while (mas[f]<mid)

            f++;

        while (mas[l]>mid)

            l--;

        if (f<=l)

        {
            int count = mas[f];
            
            mas[f]=mas[l];
            
            mas[l]=count;
            
            f++;
            
            l--; 
        } 

    } while (f < l);
    

    if (first<l) qsort(mas, first, l);
    
    if (f<last) qsort(mas, f, last); 

} 

int main()

{

    int mas[6] = {13, 15, 3, 2, 5, 4};
    
    qsort(mas, 0, 5);
    
    for (int i = 0; i < 6; i++)
    
        cout << mas[i] << " ";
    
    return 0;

} 
