#ifndef CAPADEPRESENTACIO_H
#define CAPADEPRESENTACIO_H

#include <iostream>

class CapaDePresentacio {
public:
    /* Pre: Usuario debe estar autenticado si el método requiere sesión. */
    /* Post: Muestra información del usuario actual. */
    void ConsultarUsuari() const;

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite modificar información del usuario actual. */
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
    /* Post: Cierra la sesión del usuario actual. */
    void TencaSessio();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite visualizar una película. */
    void VisualitPeli();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Permite visualizar un capítulo de una serie. */
    void VisualitCapi();

    /* Pre: Usuario debe estar autenticado. */
    /* Post: Muestra las visualizaciones realizadas por el usuario. */
    void ConsultVisualit() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las próximas estrenas según la modalidad del usuario. */
    void ProxEstrenes() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las últimas novedades disponibles. */
    void UltNovetats() const;

    /* Pre: Ninguna. */
    /* Post: Muestra las películas más vistas en el sistema. */
    void PelisMesVistes() const;


    /* Singleton para obtener una única instancia de la clase. */
    static CapaDePresentacio& getInstance() {
        static CapaDePresentacio instance;
        return instance;
    }


private:
    /* Constructor privado para evitar instanciación directa. */
    CapaDePresentacio() {}

    /* Impedir copia y asignación. */
    CapaDePresentacio(const CapaDePresentacio&) = delete;
    CapaDePresentacio& operator=(const CapaDePresentacio&) = delete;
};

#endif // CAPADEPRESENTACIO_H