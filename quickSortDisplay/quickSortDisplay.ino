#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
}

int partition(char array[], int length, int start, int end) {
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

        char temp = array[leftIndex];
        array[leftIndex] = array[rightIndex];
        array[rightIndex] = temp;
        temp = NULL;
    }

    char temp = array[leftIndex];
    array[leftIndex] = array[pivotIndex];
    array[pivotIndex] = temp;
    temp = NULL;

    return leftIndex;
}

void quickSort(char array[], int length, int start, int end) {
    delay(100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting...");
    lcd.setCursor(0, 1);
    // lcd.print("[");
    for (int i = 0; i < length; i++) {
        lcd.print(array[i]);
        // if (i == length - 1) {
        //     break;
        // } else {
        //     lcd.print(",");
        // }
    }
    // lcd.print("]");

    if (end - start <= 0) {
        return;
    }

    int pivot = partition(array, length, start, end);

    quickSort(array, length, start, pivot - 1);
    quickSort(array, length, pivot + 1, end);
}

void loop() {
    //char alphabet[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char myArray[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    // int count = 0;
    // int i = 0;

    for (int i = 0; i < 100; i++) {
        int left = random(0, 16);
        int right = random(0, 16);

        if (left == right) {
            continue;
        }

        int temp = myArray[left];
        myArray[left] = myArray[right];
        myArray[right] = temp;
    }

    // while (count < 15) {
    //     int randomIndex = random(0, 16);

    //     if (alphabet[randomIndex] == NULL) {
    //         continue;
    //     }

    //     myArray[i] = alphabet[randomIndex];
    //     alphabet[randomIndex] = NULL;
    //     count++;
    //     i++;
    // }

    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    quickSort(myArray, arrayLength, 0, arrayLength - 1);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting OK!");
    lcd.setCursor(0, 1);
    // lcd.print("["); 
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(myArray[i]);
        // if (i == arrayLength - 1) {
        //     break;
        // } else {
        //     lcd.print(",");
        // }
    }
    // lcd.print("]");

    delay(800);
}
