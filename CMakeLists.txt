cmake_minimum_required(VERSION 3.12)
project(dataStructures)

# Define all src files
set(DoublyLinkedListSrc     doubly_linked_list/list.cpp
                            doubly_linked_list/list.h)

set(HashTable               hash_table/hashTable.cpp
                            hash_table/hashTable.h)

add_executable(DList        ${DoublyLinkedListSrc})
add_executable(HashTable    ${HashTable})
