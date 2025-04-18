#include "cpu-conexiones.h"


int conectar_a_kernel(void){
    
    t_log* cpu_logger = iniciar_logger("cpu.log", "[CPU]");
    int socket_kernel = crear_conexion (IP, PUERTO_KERNEL_CPU, cpu_logger);

    log_info(cpu_logger, "FD de conexion con el KERNEL %d", socket_kernel);
    log_info(cpu_logger, "Enviando handhsake a KERNEL...");

    if(enviar_handshake (socket_kernel, HANDSHAKE_CPU, cpu_logger) == -1){
        log_error(cpu_logger, "Fallo al enviar handshake a KERNEL. Cierro conexion.");
        close(socket_kernel);
        return -1;
    }

    log_info(cpu_logger, "Handshake exitoso! Envio mensaje a KERNEL '");
    enviar_mensaje("Hola kernel como andas :3 soy el CPU", socket_kernel, cpu_logger);
    log_info(cpu_logger, "Esperando respuesta del KERNEL...");

    char* respuesta = recibir_mensaje(socket_kernel, cpu_logger);

    log_info(cpu_logger, "Me llego esto:  %s", respuesta);

    
    free(respuesta);
    log_destroy(cpu_logger);
    close(socket_kernel);


}