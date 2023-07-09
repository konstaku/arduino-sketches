void setup() {
    Serial.begin(9600);
}

int partition(int array[]) {
    int arrayLength = sizeof(array);
    return arrayLength;
}

void loop() {
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Serial.println(partition(myArray));
}
