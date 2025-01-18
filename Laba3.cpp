#include <iostream>
#include <vector>

int main() {
    int size;

    //
    std::cout << "Please type the size of the array\n";
    std::cin >> size;
    if (std::cin.fail() || size <= 0) {
        std::cout << "no.";
        return 1;
    }

    //
    std::vector<int> arr(size);
    /*
    std::vector<int> res;
    */
    std::cout << "Please type the elements of the array\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cout << "No.";
            return 1;
        }
    }
    /*
    std::vector<int> out;  // out.push_back()
    */
    int o = 1;
    /*
    for (int i = 0; i < size;) {
        if (arr[i] != arr[i + o])
            o++;
        else {
            arr.erase(arr.begin() + i + o);
            i++;
            o = 1;
        }
    }
    */
    // Removing the repetative elements ≽^•⩊•^≼
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); ) {
            if (arr[i] == arr[j]) {
                arr.erase(arr.begin() + j);
            }
            else {
                j++;
            }
        }
    }

    //
    std::cout << "The edited array:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    return 0;
}