#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
}

void bubbleSort(char array[], int length) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting...");

    int pointer = 0;
    int maxSortedIndex = length - 1;

    bool sorted = false;

    while (!sorted) {
        sorted = true;

        while (pointer < maxSortedIndex) {
            lcd.setCursor(0, 1);
            for (int i = 0; i < length; i++) {
                lcd.print(array[i]);
            }

            if (array[pointer] > array[pointer+1]) {
                sorted = false;
                char temp = array[pointer];
                array[pointer] = array[pointer+1];
                array[pointer+1] = temp;
            }

            pointer++;
            delay(50);
        }

        pointer = 0;
        maxSortedIndex--;
    }
}

void loop() {
    int arrayLength = 16;
    char array[arrayLength] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

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

    bubbleSort(array, arrayLength);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting OK!");

    lcd.setCursor(0, 1);
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(array[i]);
    }

    delay(800);
}
