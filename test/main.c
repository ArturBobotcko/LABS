#include "main_header.h"
#include "func1.h"
#include "func2.h"

int main(int argc, char* argv[]) {
    printf("This is main! %d\n", MAX_VALUES);
    func1();
    func2();

    int a = 1;
    int b = 2;
    int c = a + b;
    
    return 0;
}