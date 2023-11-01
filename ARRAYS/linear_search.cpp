#include <iostream>
using namespace std;
void findx(int arr[] , int size , int target){
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == target)
            {
                cout<<target<<" is present at "<<i<<" index\n";
                flag = 1;
                break;
            }

            
        }
        if (flag == 0)
        {
            cout<<"TARGET NOT FOUND IN THE ARRAY\n";
        }
        
        
        
}

int main () {
    int arra[10] = {1,2,3,4,5,6,7,8,9,0};
    findx(arra , 10 ,99);

    
}