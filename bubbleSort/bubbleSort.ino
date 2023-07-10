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

    int maxSorted = length - 1;

    while (maxSorted >= 0) {
        lcd.setCursor(0, 1);

        for (int i = 0; i < 16; i++) {
            lcd.print(array[i]);
        }

        delay(100);

        int currentMaxIndex = 0;
        int pointer = currentMaxIndex + 1;

        while (pointer < maxSorted) {
            if (array[pointer] > array[currentMaxIndex]) {
                currentMaxIndex = pointer;
            }

            pointer++;
        }

        if (array[maxSorted] < array[currentMaxIndex]) {
            char temp = array[maxSorted];
            array[maxSorted] = array[currentMaxIndex];
            array[currentMaxIndex] = temp;
        }

        maxSorted--;
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
    for (int i = 0; i < 16; i++) {
        lcd.print(array[i]);
    }

    delay(800);
}
