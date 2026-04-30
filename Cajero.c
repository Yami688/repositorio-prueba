#include <stdio.h>
#include <stdlib.h>

struct usuario {
    char nombre[20];
    char contrasena[20];
    float saldo;
};

int main() {
    struct usuario usuarios [3] = {
        {"yamilet", "1234", 1000.0},
        {"gaia", "4321", 2000.0},
        {"ronny", "6767", 1500.0}
    };

    char user[20], pass[20];
    int i, acceso = 0;
    int opcion;
    float monto;

    printf("=== Bienvenido al sistema de banca en linea ===\n");
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", user);
    printf("Ingrese su contrasena: ");
    scanf("%s", pass);

    for (i = 0; i < 3; i++) {
        if (strcmp(user, usuarios[i].nombre) == 0 &&  strcmp(pass, usuarios[i].contrasena) == 0) {
            acceso = 1;
            break;
        }
    }
    if(acceso == 0) {
        printf("Acceso denegado. Usuario o contrasena incorrectos.\n");
        return 0;
    }

    printf("Acceso concedido. Bienvenido, %s!\n", usuarios[i].nombre);

    do {
        printf("\n=== Menu de opciones ===\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Su saldo actual es: %.2f\n", usuarios[i].saldo);
                break;
            case 2:
                printf("Ingrese el monto a depositar: ");
                scanf("%f", &monto);
                if (monto > 0) {
                    usuarios[i].saldo += monto;
                    printf("Deposito exitoso. Nuevo saldo: %.2f\n", usuarios[i].saldo);
                } else {
                    printf("Monto invalido. El deposito debe ser mayor a cero.\n");
                }
                break;
            case 3:
                printf("Ingrese el monto a retirar: ");
                scanf("%f", &monto);
                if (monto > 0 && monto <= usuarios[i].saldo) {
                    usuarios[i].saldo -= monto;
                    printf("Retiro exitoso. Nuevo saldo: %.2f\n", usuarios[i].saldo);
                } else {
                    printf("Monto invalido o saldo insuficiente.\n");
                }
                break;
            case 4:
                printf("Gracias por usar el sistema de banca en linea. Hasta luego\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion del menu.\n");
        }
    } while (opcion != 4); 

    return 0;
    

}


    