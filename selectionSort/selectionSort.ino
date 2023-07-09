void setup() {
    Serial.begin(9600);
}

void selectionSort(int array[], int arrayLength) {
    int leastSortedIndex = 0;
    int currentMinimumIndex = 0;
    int counter = 0;

    for (int i = 0; i < arrayLength - 1; i++) {
        currentMinimumIndex = leastSortedIndex;
        Serial.print("Sorting ");
        Serial.print(i);
        Serial.print(" of ");
        Serial.print(arrayLength);
        Serial.print("...\n");


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
    int arrayLength = 500;
    int array[arrayLength];

    for (int i = 0; i < arrayLength; i++) {
        array[i] = 505 - i;
    }

    selectionSort(array, arrayLength);

    for (int i = 0; i < arrayLength; i++) {
        Serial.println(array[i]);
    }
}
