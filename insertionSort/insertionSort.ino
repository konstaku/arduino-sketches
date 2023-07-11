#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
}

void insertionSort(char array[], int length) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting...");

    for (int i = 0; i < length; i++) {
        int position = i;
        char tempValue = array[i];

        while (position > 0 && array[position-1] > tempValue) {
            lcd.setCursor(0, 1);
            for (int i = 0; i < length; i++) {
                lcd.print(array[i]);
            }
            delay(100);

            array[position] = array[position-1];
            position--;
        }

        array[position] = tempValue;
    }
}

void loop() {
    //                INITIALIZING AND SHUFFLING AN ARRAY
    
    int arrayLength = 16;
    char array[arrayLength] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 0; i < 99; i++) {
        int left = random(0, 16);
        int right = random(0, 16);

        if (left == right) {
            continue;
        }

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }

    //                CALLING SORTING FUNCTION

    insertionSort(array, arrayLength);

    //                DISPLAY SORTING RESULTS
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sorting OK!");

    lcd.setCursor(0, 1);
    for (int i = 0; i < arrayLength; i++) {
        lcd.print(array[i]);
    }

    delay(800);
}
