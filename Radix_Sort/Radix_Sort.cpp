#include <iostream>
#include <vector>

void swap(int* arr, int idx1, int idx2);
void printArr(int* arr, int length);
int randInt(int upperBound);
void shuffleArr(int* arr, int length);
int getDigit(int num, int idx);
int getTotalDigits(int num);
int maxDigits(int* arr, int length);
int* radixSort(int* arr, int length);

static int temp{ 0 };

int main() {
    int size = 100;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1);
    }
    shuffleArr(arr, size);

    printArr(arr, size);
    arr = radixSort(arr, size);
    printArr(arr, size);

    delete[] arr;
    return 0;
    
}

int* radixSort(int* arr, int length) {
    int max = maxDigits(arr, length);
    for (int i = 0; i < max; i++) {
        std::vector<std::vector<int>> buckets{ {},{},{},{},{},{},{},{},{},{} };
        for (int j = 0; j < length; j++) {
            buckets[getDigit(arr[j], i)].push_back(arr[j]);
            std::cout << "\nCount = " << ++temp;
        }
        delete[] arr;
        arr = new int[length] {};
        int count{ 0 };
        for (size_t x = 0; x < buckets.size(); x++) {
            if (buckets[x].empty()) continue;
            for (size_t y = 0; y < buckets[x].size(); y++) {
                if (count < length) {
                    std::cout << "\nCount = " << ++temp;
                    arr[count] = buckets[x][y];
                    count++;
                }
            }
        }
    }
    return arr;
}

int getDigit(int num, int idx) {
    return (int(std::floor(std::abs(num) / std::pow(10, idx))) % 10);
}

int getTotalDigits(int num) {
    if (num != 0) return (int(std::floor(std::log10(std::abs(num))) + 1));
    else return 1;
}

int maxDigits(int* arr, int length) {
    int maxDigit = 0;
    for (int i = 1; i < length; i++) {
        maxDigit = std::max(maxDigit, getTotalDigits(arr[i]));
    }
    return maxDigit;
}

void printArr(int* arr, int length) {
    std::cout << "\n[";
    for (int i = 0; i < length; i++) {
        i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
    }
    std::cout << "]\n";
}

int randInt(int upperBound) {
    int random = std::rand() % upperBound + 1;
    return random;
}

void shuffleArr(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        swap(arr, i, randInt(length - 1));
    }
}

void swap(int* arr, int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
