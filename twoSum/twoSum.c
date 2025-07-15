#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct entry {
    int key;
    int value;
    struct entry* next;
} Entry;

Entry* hashTable[TABLE_SIZE];

int hashFunction(int key, int numsSize) {
    return ((unsigned int)key) % numsSize;
}

void initHashTable(int numsSize) {
    for(int i = 0; i < numsSize; i++)
        hashTable[i] = NULL;
}

int getIndex(int key, int numsSize) {
    int slot = hashFunction(key, numsSize);
    Entry* entry = hashTable[slot];

    while(entry != NULL) {
        if(entry->key == key)
            return entry->value;
        entry = entry->next;
    }
    return -1;
}

void insertEntry(int key, int value, int numsSize) {
    int slot = hashFunction(key, numsSize);
    Entry* entry = hashTable[slot];

    if(entry == NULL) {
        Entry* newEntry = malloc(sizeof(Entry));
        newEntry->key = key;
        newEntry->value = value;
        newEntry->next = NULL;
        hashTable[slot] = newEntry;
        return;
    }

    Entry* prev;
    while(entry != NULL) {
        if(entry->key == key) {
            entry->value = value;
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;
    prev->next = newEntry;
}

void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry* entry = hashTable[i];
        while (entry) {
            Entry* tmp = entry;
            entry = entry->next;
            free(tmp);
        }
        hashTable[i] = NULL;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(sizeof(int) * 2);

    initHashTable(numsSize);

    for(int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = getIndex(complement, numsSize);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            free_table();
            return result;
        }
        insertEntry(nums[i], i, numsSize);
    }

    *returnSize = 0;
    free_table();
    return NULL;
}

int main() {
    // int nums[] = {3, 3};
    int nums[] = {3, 2, 4};
    int target = 6;
    int returnSize;

    int* result = twoSum(nums, 3, target, &returnSize);
    if (result) {
        printf("Result: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    free_table();
    return 0;
}
