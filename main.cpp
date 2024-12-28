#include <iostream>
#include "Conexio.h"
#include "PetitFlix.h"
#include "CapaDePresentacio.h"

void gestionar_usuari() {
    std::cout << "------------------" << std::endl;
    std::cout << "   Gestió usuari  " << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "1. Consultar usuari" << std::endl;
    std::cout << "2. Modificar usuari" << std::endl;
    std::cout << "3. Esborrar usuari" << std::endl;
    std::cout << "4. Tornar" << std::endl;
    std::cout << "Opcio: ";
    int op;
    std::cin >> op;

    while (op < 1 || op > 4) {
        std::cout << "Opció no vàlida. Intenta-ho de nou: ";
        std::cin >> op;
    }

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    switch (op) {
    case 1:
        presentacio.ConsultarUsuari();
        break;
    case 2:
        presentacio.ModificarUsuari();
        break;
    case 3:
        presentacio.EsborraUsuari();
        break;
    }
}

void gestionar_visualitzacions() {
    std::cout << "-------------------------" << std::endl;
    std::cout << "       Visualitzar       " << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "1. Visualitzar pel·lícula" << std::endl;
    std::cout << "2. Visualitzar capítol" << std::endl;
    std::cout << "3. Consultar visualitzacions" << std::endl;
    std::cout << "4. Tornar" << std::endl;
    std::cout << "Opcio: ";
    int op;
    std::cin >> op;

    while (op < 1 || op > 3) {
        std::cout << "Opció no vàlida. Intenta-ho de nou: ";
        std::cin >> op;
    }

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    switch (op) {
    case 1:
        presentacio.VisualitPeli();
        break;
    case 2:
        presentacio.VisualitCapi();
        break;
    case 3:
        presentacio.ConsultVisualit();
        break;
    }
}

void gestionar_consultes() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "   Consultar  continguts  " << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "1. Properes Estrenes" << std::endl;
    std::cout << "2. Últimes Novetats" << std::endl;
    std::cout << "3. Pel·lícules més vistes" << std::endl;
    std::cout << "4. Tornar" << std::endl;
    std::cout << "Opcio: ";
    int op;
    std::cin >> op;

    while (op < 1 || op > 3) {
        std::cout << "Opció no vàlida. Intenta-ho de nou: ";
        std::cin >> op;
    }

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    switch (op) {
    case 1:
        presentacio.ProxEstrenes();
        break;
    case 2:
        presentacio.UltNovetats();
        break;
    case 3:
        presentacio.PelisMesVistes();
        break;
    }
}

int main() {
    std::string d, u, pa, h, p;
    std::cout << "Dades necessaries per generar la connexio amb la base de dades: " << std::endl;
    std::cout << "dbname= ";
    std::cin >> d;
    std::cout << "user= ";
    std::cin >> u;
    std::cout << "password= ";
    std::cin >> pa;
    std::cout << "hostaddr= ";
    std::cin >> h;
    std::cout << "port= ";
    std::cin >> p;

    Conexio& con = Conexio::getInstance();
    con.inicialitzar_atributs(d, u, pa, h, p);

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    PetitFlix& sistema = PetitFlix::getInstance();

    bool sortir = false;
    while (!sortir) {
        std::cout << "******************" << std::endl;
        std::cout << "  Menu Principal  " << std::endl;
        std::cout << "******************" << std::endl;

        if (!sistema.hiHaUsuariLoggejat()) {
            std::cout << "1. Iniciar sessió" << std::endl;
            std::cout << "2. Registrar usuari" << std::endl;
            std::cout << "3. Consultar properes estrenes" << std::endl;
            std::cout << "4. Consultar pel·lícules més vistes" << std::endl;
            std::cout << "5. Sortir" << std::endl;
        } else {
            std::cout << "1. Gestionar usuari" << std::endl;
            std::cout << "2. Gestionar visualitzacions" << std::endl;
            std::cout << "3. Gestionar consultes" << std::endl;
            std::cout << "4. Tancar sessió" << std::endl;
            std::cout << "5. Sortir" << std::endl;
        }

        std::cout << "Opcio: ";
        int op;
        std::cin >> op;

        if (!sistema.hiHaUsuariLoggejat()) {
            switch (op) {
            case 1:
                presentacio.IniciSessio();
                break;
            case 2:
                presentacio.RegistreUsuari();
                break;
            case 3:
                presentacio.ProxEstrenes();
                break;
            case 4:
                presentacio.PelisMesVistes();
                break;
            case 5:
                sortir = true;
                break;
            default:
                std::cout << "Opció no vàlida." << std::endl;
            }
        } else {
            switch (op) {
            case 1:
                gestionar_usuari();
                break;
            case 2:
                gestionar_visualitzacions();
                break;
            case 3:
                gestionar_consultes();
                break;
            case 4:
                presentacio.TencaSessio();
                break;
            case 5:
                sortir = true;
                break;
            default:
                std::cout << "Opció no vàlida." << std::endl;
            }
        }
    }
}
