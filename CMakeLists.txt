cmake_minimum_required(VERSION 4.3)
project(ADTs C)

set(CMAKE_C_STANDARD 11)

add_executable(Einfuerhung Einfuerhung.c
        Stack.c
        Queue.c
)
add_executable(Einfuerhung_2 Einfuerhung_2.c)
add_executable(LinkedList LinkedList_Node.c)
add_executable(LinkedList_2 LinkedList_Stack.c)

add_executable(Stack Stack.c)
add_executable(Queue Queue.c)