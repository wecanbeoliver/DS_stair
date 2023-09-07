#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int a, int b){

    return a>b;
}


int main()
{


    string sentence,word;
    vector<int> arr;
    vector<int> arr_x;
    vector<int> arr_y;

    getline(cin,sentence);

    istringstream iss (sentence);    // to parse sentence using space

    while (iss >> word){
        arr.push_back(stoi(word));
    }

    arr.pop_back();

    int sum_x = 0;

    for (int row=0; row < arr.size(); row = row+2){

        arr_x.push_back(arr[row]+sum_x);
        sum_x += arr[row];

    }
    int sum_y = 0;

    for (int col=arr.size()-1; col>0; col = col-2){

       arr_y.push_back(arr[col]+sum_y);
       sum_y += arr[col];

    }


    sort(arr_y.begin(),arr_y.end(),cmp);

    arr_x.insert(arr_x.begin(),0);
    arr_y.push_back(0);


//    cout << "X" <<endl;
//    for (auto i:arr_x){
//        cout << i << endl;
//    }
//
//    cout << "Y" <<endl;
//    for (auto r:arr_y){
//        cout << r << endl;
//    }


    int x,y;


    while (1){

//        cout << "X :" << x << "  Y: "<<y<<endl;
        cin >> x >> y;
        if (cin.eof()) break;
        int idx;

        if (arr_x.back()<x){
            cout << "out" <<endl;
            continue;
        }

        for (idx=0;idx<arr_x.size()-1;idx++){
            if (arr_x[idx]<x && x<=arr_x[idx+1]){
                break;
            }
        }

//        cout << "IDX = " << idx <<endl;




        if (arr_x[idx+1]==x && arr_y[idx+1]<=y && y<=arr_y[idx]){
            cout << "on" << endl;
        }
        else if (y == arr_y[idx]){
            cout << "on" << endl;
        }
        else if (y > arr_y[idx]){
            cout << "out" <<endl;
        }
        else {
            cout << "in" <<endl;
        }



}

    return 0;
}
