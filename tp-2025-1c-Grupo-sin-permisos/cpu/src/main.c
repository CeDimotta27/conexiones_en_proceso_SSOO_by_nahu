#include <utils/sockets.h>
#include <utils/hello.h>
#include <utils/handshake.h>
#include <utils/configs.h>

int main(int argc, char* argv[]) {
    saludar("cpu");

    conectar_a_kernel();

    return 0;
}
