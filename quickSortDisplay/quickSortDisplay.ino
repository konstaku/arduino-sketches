#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
}

int partition(int array[], int length, int start, int end) {
    int pivotIndex = end;
    int leftIndex = start;
    int rightIndex = pivotIndex - 1;

    while (true) {
        while (array[leftIndex] < array[pivotIndex]) {
            leftIndex++;
        }

        while (array[rightIndex] > array[pivotIndex]) {
            rightIndex--;
        }

        if (leftIndex >= rightIndex) {
            break;
        }

        int temp = array[leftIndex];
        array[leftIndex] = array[rightIndex];
        array[rightIndex] = temp;
        temp = NULL;
    }

    int temp = array[leftIndex];
    array[leftIndex] = array[pivotIndex];
    array[pivotIndex] = temp;
    temp = NULL;

    return leftIndex;
}

void quickSort(int array[], int length, int start, int end) {
    delay(100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting array...");
    lcd.setCursor(0, 1);
    lcd.print("["); // Yellow colored brackets
    for (int i = 0; i < length; i++) {
        lcd.print(array[i]);
        // if (i == length - 1) {
        //     break;
        // } else {
        //     lcd.print(",");
        // }
    }
    lcd.print("]");

    if (end - start <= 0) {
        return;
    }

    int pivot = partition(array, length, start, end);

    quickSort(array, length, start, pivot - 1);
    quickSort(array, length, pivot + 1, end);
}

void loop() {
    int myArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 100; i++) {
        int first = random(0, 9);
        int second = random(9, 9);

        if (first != second) {
            int temp = myArray[first];
            myArray[first] = myArray[second];
            myArray[second] = temp;
        }
    }

    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    quickSort(myArray, arrayLength, 0, arrayLength - 1);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Array OK!");
    lcd.setCursor(0, 1);
    lcd.print("["); // Yellow colored brackets
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(myArray[i]);
        // if (i == arrayLength - 1) {
        //     break;
        // } else {
        //     lcd.print(",");
        // }
    }
    lcd.print("]");

    delay(1000);
}
