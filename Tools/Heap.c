void addHeap(Line* line){
    int curr;
    heap[++heapSize] = line->start;
    curr = heapSize;
    while (curr > 1 && heap[curr / 2] > heap[curr]) {
        int temp = heap[curr];
        heap[curr] = heap[curr / 2];
        heap[curr / 2] = temp;
        curr = curr / 2;
    }
}
void popping(){
    int curr;
    while(heapSize > 0 && line->end - heap[1] > length){
        heap[1] = heap[heapSize];
        heap[heapSize--] = NULLVAL;
        curr = 1;
        // 여기가 문제였네;;;;
        while (2 * curr <= heapSize) {
            int minChild = (heap[curr * 2] < heap[curr * 2 + 1]) ? curr * 2 : curr * 2 + 1;
            if (heap[minChild] < heap[curr]) {
                int temp = heap[curr];
                heap[curr] = heap[minChild];
                heap[minChild] = temp;
                curr = minChild;
            } else {
                break;
            }
        }
    }
}