#include<iostream>
using namespace std;

int main(){
    int row,cols;
    cin>>row;
    cin>> cols;
    int **arr = new int*[row];
    
    for(int i = 0;i<row;i++){
        arr[i] = new int[cols];
    }
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 5 ;
        }
    }

    cout<< "===== GAME MAP ( " << row <<" x "<< cols<< ") =====" <<endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout <<  arr[i][j] << "\t";
        }
        cout<< endl;
    }

    cout<< "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;

    int grass = 0 , water = 0, mountain = 0, forest = 0, dungeon = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            int num = arr[i][j];
            switch(num){
                case 0:
                    grass++;
                    break;
                case 1:
                    water++;
                    break;
                case 2:
                    mountain++;
                    break;
                case 3:
                    forest++;
                    break;
                case 4:
                    dungeon++;
                    break;
            }
        }
        cout<< endl;
    }
    cout<< "Tile Count:" << endl;
    cout<< "Grass : " << grass << endl;
    cout<< "Water : " << water << endl;
    cout<< "Mountain : " << mountain << endl;
    cout<< "Forest : " << forest << endl;
    cout<< "Dungeon : " << dungeon << endl;

    for(int i = 0;i<row ;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
