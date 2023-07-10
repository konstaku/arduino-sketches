#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
}

void selectionSort(char array[], int arrayLength) {
    int leastSortedIndex = 0;
    int currentMinimumIndex = 0;
    int counter = 0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting...");

    for (int i = 0; i < arrayLength - 1; i++) {
        currentMinimumIndex = leastSortedIndex;

        delay(100);

        lcd.setCursor(0, 1);
        for (int i = 0; i < arrayLength; i++) {
            lcd.print(array[i]);
        }


        for (int j = leastSortedIndex; j < arrayLength; j++) {
            if (array[j] < array[currentMinimumIndex]) {
                currentMinimumIndex = j;
            }
        }

        if (array[currentMinimumIndex] < array[leastSortedIndex]) {
            int tmp = array[currentMinimumIndex];
            array[currentMinimumIndex] = array[leastSortedIndex];
            array[leastSortedIndex] = tmp;
        }

        leastSortedIndex++;
    }
}

void loop() {
    int arrayLength = 16;
    char array[arrayLength] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < 100; i++) {
        int left = random(0, 16);
        int right = random(0, 16);

        if (left == right) {
            continue;
        }

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }



    selectionSort(array, arrayLength);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting OK!");

    lcd.setCursor(0, 1);
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(array[i]);
    }

    delay(800);
}
