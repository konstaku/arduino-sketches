void setup() {
    Serial.begin(9600);
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
    int myArray[] = {5, 2, 9, 7, 1, 4, 8, 3, 6};
    int arrayLength = sizeof(myArray) / sizeof(myArray[0]);

    Serial.println("Array before partition:");
    Serial.print("\x1b[33m[\x1b[0m"); // Yellow colored brackets
    for (int i = 0; i < arrayLength; i++) {
        Serial.print(myArray[i]);
        if (i == arrayLength - 1) {
            break;
        } else {
            Serial.print(", ");
        }
    }
    Serial.println("\x1b[33m]\x1b[0m");

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
