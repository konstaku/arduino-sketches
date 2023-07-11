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
    if (end - start <= 0) {
        return;
    }

    int pivot = partition(array, length, start, end);

    quickSort(array, length, start, pivot - 1);
    quickSort(array, length, pivot + 1, end);
}

void loop() {
    int myArray[] = {5, 2, 9, 7, 1, 4, 8};
    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    lcd.setCursor(0, 0);
    lcd.print("Array before:");
    lcd.setCursor(0, 1);
    lcd.print("["); // Yellow colored brackets
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(myArray[i]);
        if (i == arrayLength - 1) {
            break;
        } else {
            lcd.print(",");
        }
    }
    lcd.print("]");

    // Serial.println("Array before partition:");
    // Serial.print("\x1b[33m[\x1b[0m"); // Yellow colored brackets
    // for (int i = 0; i < arrayLength; i++) {
    //     Serial.print(myArray[i]);
    //     if (i == arrayLength - 1) {
    //         break;
    //     } else {
    //         Serial.print(", ");
    //     }
    // }
    // Serial.println("\x1b[33m]\x1b[0m");

    quickSort(myArray, arrayLength, 0, arrayLength - 1);

    Serial.println("Array after partition:");
    Serial.print("\x1b[33m[\x1b[0m");
    for (int i = 0; i < arrayLength; i++) {
        Serial.print(myArray[i]);
        if (i == arrayLength - 1) {
            break;
        } else {
            Serial.print(", ");
        }
    }
    Serial.println("\x1b[33m]\x1b[0m");
    Serial.println("\n\n\n");

}
