#ifndef CAPADEPRESENTACIO_H
#define CAPADEPRESENTACIO_H

#include <iostream>

class CapaDePresentacio {
public:
    /* Pre: Usuario debe estar autenticado si el m�todo requiere sesi�n. */
    /* Post: Muestra informaci�n del usuario actual. */
    void ConsultarUsuari() const;

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite modificar informaci�n del usuario actual. */
    void ModificarUsuari();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Elimina al usuario actual del sistema. */
    void EsborraUsuari();

    /* Pre: Ninguna. */
    /* Post: Registra un nuevo usuario en el sistema. */
    void RegistreUsuari() const;

    /* Pre: Usuario no debe estar autenticado. */
    /* Post: Autentica al usuario en el sistema. */
    void IniciSessio();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Cierra la sesi�n del usuario actual. */
    void TencaSessio();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite visualizar una pel�cula. */
    void VisualitPeli();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite visualizar un cap�tulo de una serie. */
    void VisualitCapi();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Muestra las visualizaciones realizadas por el usuario. */
    void ConsultVisualit() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las pr�ximas estrenas seg�n la modalidad del usuario. */
    void ProxEstrenes() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las �ltimas novedades disponibles. */
    void UltNovetats() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las pel�culas m�s vistas en el sistema. */
    void PelisMesVistes() const;


    /* Singleton para obtener una �nica instancia de la clase. */
    static CapaDePresentacio& getInstance() {
        static CapaDePresentacio instance;
        return instance;
    }


private:
    /* Constructor privado para evitar instanciaci�n directa. */
    CapaDePresentacio() {}

    /* Impedir copia y asignaci�n. */
    CapaDePresentacio(const CapaDePresentacio&) = delete;
    CapaDePresentacio& operator=(const CapaDePresentacio&) = delete;
};

#endif // CAPADEPRESENTACIO_H