# Guía: cómo subir imágenes al repositorio y usarlas en guías Markdown

Esta guía explica el flujo recomendado para **subir imágenes al repo** y **consumirlas en archivos `.md`** usando URLs directas (raw) de GitHub o rutas relativas. Incluye buenas prácticas de nombres y tamaños para usarlas en GitHub Pages.

## Objetivo

* Mantener un **repositorio de imágenes organizado** (p. ej. por curso/módulo/guía).
* Insertar imágenes en guías Markdown de forma **estable y reproducible**.
* Evitar problemas de enlaces rotos, repos privados, o reutilización de codigo fuente.

## Estructura de carpetas sugerida

Ejemplo para un curso con guías:

```
PED/
  Markdown/
    CP4.md
  Imagenes/
    CP4/
      A.png
      B.png
      diagrama-1.svg
```

> **Tip**: Usa una carpeta de imágenes por guía (o por módulo) para mantener orden.

## Nombres, formatos y tamaño

* **Nombre de archivo**: `kebab-case` (sin espacios, sin acentos): `diagrama-red-03.png`
* **Formatos**:

  * **PNG**: diagramas/figuras con texto, fondos sólidos.
  * **JPG/JPEG**: fotografías (mejor compresión).
  * **SVG**: vectores (diagramas exportados). *Evita SVG con scripts incrustados.*
* **Tamaño recomendado**: intenta **≤ 300 KB** por imagen (optimiza antes de subir).

## Obtener la URL RAW (directa) de una imagen

1. Abre el archivo de imagen en GitHub (vista del repositorio).
2. Clic en **Download** o **View raw** (según UI), que te lleva a `raw.githubusercontent.com`.
3. Copia la URL del navegador.

**Forma canónica de URL RAW**:

```
https://raw.githubusercontent.com/<owner>/<repo>/<branch>/<ruta/archivo>
```

Ejemplo (rama `main`):

```
https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/main/PED/Imagenes/CP4/B.png
```

## Insertar imágenes en Markdown

### Con URL RAW

```md
![Diagrama CP4](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/main/PED/Imagenes/CP4/B.png)
```

## Ejemplos listos para copiar

**RAW (rama main)**

  ```md
  ![B CP4](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/main/PED/Imagenes/CP4/B.png)
  ```

## Solución de problemas

* **No carga la imagen**: verifica que la URL/relativa sea correcta y que el archivo exista en esa ruta y rama.
* **En repo privado no se ve**: el lector no autenticado no puede ver RAW. Usa repo público/Pages/bucket.
* **Espacios en el nombre**: evita espacios; si existen, debes codificarlos como `%20` en la URL.
