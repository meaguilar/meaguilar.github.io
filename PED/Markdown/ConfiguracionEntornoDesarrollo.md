# Instalación de MinGW-w64 desde WinLibs y Visual Studio Code en Windows

## 1. Objetivo

Este documento explica cómo instalar un entorno de desarrollo C/C++ en Windows utilizando:

-   **WinLibs** para obtener GCC, G++, MinGW-w64, Binutils y GDB.
-   **Visual Studio Code (VS Code)** como editor y entorno de desarrollo.
-   La extensión **C/C++** de Microsoft para IntelliSense, compilación y depuración.

La configuración está orientada principalmente a proyectos **C++17 o posteriores**.

----------

## 2. Descargar WinLibs

WinLibs proporciona paquetes precompilados de GCC y MinGW-w64 para Windows.

Sitio oficial:

https://winlibs.com/

Para un Windows de 64 bits se recomienda descargar una versión **Win64**.

Para proyectos modernos se recomienda utilizar una versión reciente de GCC con:

-   MinGW-w64
-   UCRT
-   POSIX threads

Por ejemplo:

```text
GCC 16.x
MinGW-w64 14.x
UCRT
POSIX
Win64

```

> Las versiones disponibles pueden cambiar con el tiempo. Se recomienda descargar la versión estable más reciente compatible con el proyecto.

----------

## 3. Descargar el paquete

En la página de WinLibs:

1.  Buscar la versión estable más reciente.
2.  Seleccionar **Win64**.
3.  Seleccionar la variante **UCRT**.
4.  Seleccionar **POSIX threads**.
5.  Descargar el archivo `.7z` o `.zip`.

Si se dispone de 7-Zip, se recomienda utilizar el archivo `.7z`.

----------

## 4. Extraer WinLibs

Crear una carpeta para los compiladores. Por ejemplo:

```text
C:\dev\
```

Extraer el paquete descargado dentro de esa carpeta.

La estructura final puede ser similar a:

```text
C:\dev\mingw64\
├── bin\
│   ├── gcc.exe
│   ├── g++.exe
│   ├── gdb.exe
│   ├── ld.exe
│   └── ...
├── include\
├── lib\
└── ...
```

La ubicación exacta puede variar dependiendo de la versión descargada.

Lo importante es localizar la carpeta que contiene:

```text
bin\g++.exe
```

Por ejemplo:

```text
C:\dev\mingw64\bin\g++.exe
```

----------

## 5. Comprobar GCC

Abrir **CMD** o **PowerShell**.

Entrar en la carpeta `bin`:

```powershell
cd C:\dev\mingw64\bin
```

Ejecutar:

```powershell
.\g++.exe --version
```

También se puede comprobar GCC:

```powershell
.\gcc.exe --version
```

Y GDB:

```powershell
.\gdb.exe --version

```

Debería aparecer la versión de GCC instalada.

----------

# 6. Agregar MinGW al PATH

Para poder ejecutar `gcc`, `g++` y `gdb` desde cualquier terminal, agregar la carpeta `bin` al `PATH`.

Por ejemplo:

```text
C:\dev\mingw64\bin
```

## 6.1 Abrir las variables de entorno

En Windows:

1.  Presionar `Win + R`.
2.  Escribir:

```text
sysdm.cpl
```

3.  Abrir **Opciones avanzadas**.
4.  Seleccionar **Variables de entorno**.
5.  En **Variables del sistema**, seleccionar `Path`.
6.  Presionar **Editar**.
7.  Presionar **Nuevo**.
8.  Agregar:

```text
C:\dev\mingw64\bin
```

9.  Aceptar todas las ventanas.

----------

## 6.2 Comprobar PATH

Cerrar las terminales abiertas y abrir una nueva.

Ejecutar:

```powershell
g++ --version
```

Después:

```powershell
gcc --version
```

Y:

```powershell
gdb --version
```

También se puede comprobar qué ejecutable está utilizando Windows:

```powershell
where.exe g++
```

El resultado debe apuntar al nuevo MinGW.

Por ejemplo:

```text
C:\dev\mingw64\bin\g++.exe
```

### Importante

Si `where.exe g++` muestra una instalación antigua de MinGW antes que la nueva, Windows utilizará la antigua.

Esto puede causar problemas cuando existen varias instalaciones de MinGW.

----------

# 7. No mezclar diferentes instalaciones de MinGW

Si anteriormente se utilizaba MinGW 6, es recomendable evitar mezclar sus componentes con la nueva instalación.

Por ejemplo, evitar una configuración como:

```text
MinGW 6
    gcc.exe
    g++.exe

MinGW nuevo
    libstdc++
    headers
    binutils
```

Todos los componentes deben pertenecer al mismo toolchain.

Comprobar:

```powershell
where.exe gcc
where.exe g++
where.exe ld
```

Los ejecutables deberían proceder de la misma instalación.

----------

# 8. Instalar Visual Studio Code

Descargar Visual Studio Code desde su sitio oficial:

https://code.visualstudio.com/

Descargar la versión correspondiente a Windows.

Ejecutar el instalador.

Durante la instalación es recomendable activar las opciones relacionadas con:

-   Agregar "Open with Code" al menú contextual.
-   Agregar `code` al PATH.
-   Registrar VS Code como editor.
----------

# 9. Instalar la extensión C/C++

Abrir Visual Studio Code.

Seleccionar **Extensions**.

Buscar:

```text
C/C++
```

Instalar:

```text
C/C++ — Microsoft
```

Esta extensión proporciona:

-   IntelliSense.
-   Navegación de código.
-   Detección de errores.
-   Depuración.
-   Integración con GCC.
-   Configuración de compilación.

----------

# 10. Crear un proyecto C++

Crear una carpeta para el proyecto:

```text
C:\proyectos\cpp\HolaMundo
```

Abrirla en VS Code:

```text
File → Open Folder
```

Crear:

```text
main.cpp
```

Contenido:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hola, mundo!" << std::endl;

    return 0;
}

```

----------

# 11. Compilar desde la terminal de VS Code

Abrir:

```text
Terminal → New Terminal

```

Comprobar el compilador:

```powershell
g++ --version
```

Compilar:

```powershell
g++ -std=c++17 main.cpp -o programa.exe
```

Ejecutar:

```powershell
.\programa.exe
```

Debe aparecer:

```text
Hola, mundo!
```
----------


La ventaja de utilizar un paquete completo de WinLibs es que **GCC, G++, MinGW-w64, la biblioteca estándar de C++ y las herramientas de enlace pertenecen al mismo toolchain**, evitando mezclar componentes de diferentes versiones.
