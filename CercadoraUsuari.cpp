#include "CercadoraUsuari.h"
#include<stdexcept>

PasarellaUsuari CercadoraUsuari::cercaUsuari(std::string sobrenomU) { //excepcio: UsuariNoExisteix
    Conexio& con = Conexio::getInstance();

    try {
        std::string query = "SELECT nom, contrasenya, correu_electronic, data_naixement, subscripcio FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
        std::shared_ptr<sql::ResultSet> result = con.executar(query);

        if (result->next()) {
            std::string nom = result->getString("nom");
            std::string contrasenya = result->getString("contrasenya");
            std::string correuElectronic = result->getString("correu_electronic");
            std::string dataNaixement = result->getString("data_naixement");
            std::string subscripcio = result->getString("subscripcio");

            PasarellaUsuari u(nom, sobrenomU, contrasenya, correuElectronic, dataNaixement, subscripcio);
            return u;
        }
        else {
            throw std::runtime_error("Usuari no existeix: " + sobrenomU);
        }

    }
    catch (const sql::SQLException& e) {
        throw std::runtime_error("Error al cercar usuari en la base de dades: " + std::string(e.what()));
    }
}