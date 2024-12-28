#include "Conexio.h"


Conexio::Conexio() : _driver(nullptr), _conn(nullptr) {
    _dbname = "";
    _user = "";
    _password = "";
    _hostaddr = "";
    _port = "";
}


Conexio& Conexio::getInstance() {
    static Conexio instance;
    return instance;
}


void Conexio::inicialitzar_atributs(const std::string& dbname, const std::string& user, const std::string& password, const std::string& hostaddr, const std::string& port) {
    _dbname = dbname;
    _user = user;
    _password = password;
    _hostaddr = hostaddr;
    _port = port;

    try {

        _driver = sql::mysql::get_mysql_driver_instance();
        _conn = std::shared_ptr<sql::Connection>(
            _driver->connect("tcp://" + _hostaddr + ":" + _port, _user, _password));
        _conn->setSchema(_dbname);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al conectar a la base de dades: " << e.what() << std::endl;
        throw;
    }
}


std::shared_ptr<sql::ResultSet> Conexio::executar(const std::string& sentenciaSQL) {
    try {
        if (!_conn || _conn->isClosed()) {
            throw std::runtime_error("La conexió a la base de dades no está oberta.");
        }
        std::shared_ptr<sql::Statement> stmt(_conn->createStatement());
        return std::shared_ptr<sql::ResultSet>(stmt->executeQuery(sentenciaSQL));
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al executar la consulta SQL: " << e.what() << std::endl;
        throw;
    }
}