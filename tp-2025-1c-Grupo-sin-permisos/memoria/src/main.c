#include <utils/hello.h>
#include "memoria-conexiones.h"

int main(int argc, char* argv[]) {
    saludar("memoria");

    memoria_conectar_a_kernel();

    return 0;
}
