void binPackingNextFit(int *items, int numItems, int binCapacity) {
    int binCount = 1;
    int currentBinSpace = binCapacity;
    int i;

    for (i = 0; i < numItems; i++) {
        if (currentBinSpace >= items[i]) {
            currentBinSpace -= items[i];
        } else {
            binCount++;
            currentBinSpace = binCapacity - items[i];
        }
    }

    printf("Number of bins required using Next Fit: %d\n", binCount);
}

int main() {
    int items[] = {2, 5, 4, 7, 1, 3, 8}; 
    int binCapacity = 10;                
    int numItems = sizeof(items) / sizeof(items[0]);

    printf("BIN - PACKING Algorithm (Next Fit)\n");
    printf("Item sizes: {2, 5, 4, 7, 1, 3, 8}\n");
    printf("Bin capacity: %d\n", binCapacity);
    binPackingNextFit(items, numItems, binCapacity);

    return 0;
}