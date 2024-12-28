#pragma once
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <memory>

class Conexio
{
private:
    // Atributos
    std::string _dbname;
    std::string _user;
    std::string _password;
    std::string _hostaddr;
    std::string _port;
    sql::mysql::MySQL_Driver* _driver;
    std::shared_ptr<sql::Connection> _conn;

    // Constructor privado (Singleton)
    Conexio();

public:
    // Obtener la instancia singleton
    static Conexio& getInstance();

    // Método para inicializar los atributos
    void inicialitzar_atributs(const std::string& dbname, const std::string& user, const std::string& password, const std::string& hostaddr, const std::string& port);

    // Método para ejecutar una consulta SQL
    std::shared_ptr<sql::ResultSet> executar(const std::string& sentenciaSQL);

    // Eliminar copia y asignación para el Singleton
    Conexio(const Conexio&) = delete;
    Conexio& operator=(const Conexio&) = delete;
};