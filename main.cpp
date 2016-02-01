#include <iostream>
#include<array.h>

using namespace std;

int main()
{
    arraystack<int> obj;
    for(int i = 0;i<=10;i++)
    {
        obj.add(i,10*i);obj.print();
        if(i>0 && (i%4)== 0)
        {
            obj.remove(i-1);
            obj.print();
            obj.add(i-1,i-1);

        }

    }



   // a = new array(5);
    //a = new array<int>(5);
    cout << "Hello world!" << endl;
    return 0;
}
