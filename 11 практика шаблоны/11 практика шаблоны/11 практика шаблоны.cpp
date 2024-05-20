#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//7 вариант

void task1();
//void task2();


int main() {
    setlocale(LC_ALL, "rus");
    task1();
    /*task2();*/
}

template<typename T>
vector<T> mergeSorted(const vector<T>& arr1, const vector<T>& arr2) {
    vector<T> mergedArray;
    unsigned int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        }
        else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {

        mergedArray.push_back(arr2[j]);
        j++;
    }
    return mergedArray;
}

vector<int> removeDuplicates(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    arr.assign(s.begin(), s.end());
    return arr;
}

void task1() {

    int count1;
    cout << "Введите количество элементов в первом массиве: ";
    cin >> count1;
    vector<int> arr1(count1);
    cout << "Введите элементы первого массива:\n";
    for (int i = 0; i < count1; i++) {
        cout << i + 1 << " элемент: ";
        cin >> arr1[i];
    }
    sort(arr1.begin(), arr1.end());
    cout << endl;

    int count2;
    cout << "Введите количество элементов вo втором массиве: ";
    cin >> count2;
    vector<int> arr2(count2);
    cout << "Введите элементы второго массива:\n";
    for (int i = 0; i < count2; i++) {
        cout << i + 1 << " элемент: ";
        cin >> arr2[i];
    }
    sort(arr2.begin(), arr2.end());
    cout << endl;

    vector<int> mergedArray = mergeSorted(arr1, arr2);

    //функция, если надо удалить повторяющиеся элементы
    /*removeDuplicates(mergedArray);*/

    cout << "Слияние двух отсортированных массивов:\n";
    for (const auto& num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
}

//template<typename T>
//T nod(T a, T b) {
//    while (a != b)
//    {
//        if (a > b)
//            a = a - b;
//        else b = b - a;
//    }
//    return a;
//}
//
//void task2() {
//    int n;
//    cout << "Выберите тип данных:\n1. int\n2. double\n->";
//    cin >> n;
//    if (n == 1) {
//        int num1, num2;
//        cout << "Введите первое число: ";
//        cin >> num1;
//        cout << "Введите второе число: ";
//        cin >> num2;
//        int result = nod(num1, num2);
//        cout << endl<< "Наименьший общий делитель чисел " << num1 << " и " << num2 << " равен: " << result << endl;
//    }
//    else if (n == 2) {
//        double num1, num2;
//        cout << "Введите первое число: ";
//        cin >> num1;
//        cout << "Введите второе число: ";
//        cin >> num2;
//        double result = nod(num1, num2);
//        cout <<endl<< "Наименьший общий делитель чисел " << num1 << " и " << num2 << " равен: " << result << endl;
//    }
//    else
//        cout << "Ошибка ввода";
//}