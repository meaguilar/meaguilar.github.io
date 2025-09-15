# Flujo recomendado de edición con StackEdit

1. **Abrir StackEdit**

   * Ve a [https://stackedit.io/](https://stackedit.io/) y **Sign in**.

2. **Cargar el archivo a editar** (dos opciones):

   * **Desde GitHub (sincronizado)**

     1. En StackEdit, abre el **panel lateral** → **Synchronize** → **Add synchronization**.
     2. Elige **GitHub** y autoriza a StackEdit.
     3. Selecciona **Repository**, **Branch** y la **ruta del archivo** (p. ej. `PED/Guias/CP4.md`).
     4. Activa **Push on save** (si quieres que cada guardado haga commit) o haz **Manual push** al finalizar.
   * **Desde un archivo local / pegar contenido**

     * Crea un documento nuevo en StackEdit y pega el contenido; al terminar, **exporta** o **sincroniza** con GitHub creando la vinculación (recomendado para mantener historial de cambios).

3. **Editar el contenido**

   * Usa el **editor** a la izquierda y la **vista previa** a la derecha.
   * Mantén consistencia en **encabezados**, **tablas**, **listas**, **código** y **bloques con HTML inline** (para controlar tamaños de imagen, ver más abajo).

4. **Guardar y subir cambios**

   * Si configuraste sincronización con **Push on save**, al **Ctrl/Cmd+S** se hará commit al repo (StackEdit solicitará un mensaje).
   * Si no, usa **Synchronize → Push** cuando termines.
   * Verifica en GitHub que el archivo se actualizó en la **rama correcta**.

> **Sugerencia de ramas:** Trabaja en una **rama feature** (p. ej. `docs/cp4-actualizacion`) y luego abre un **Pull Request** para revisión antes de fusionar a `main`.

# Exportar las guías `.md` como **HTML** desde StackEdit

Esta sección explica cómo **generar archivos HTML** a partir de las guías Markdown usando **StackEdit**, elegir plantillas (por ejemplo **Styled HTML with TOC**) y, opcionalmente, **configurar una plantilla personalizada** para el sitio.

## Exportación rápida (recomendada)

1. Abre la guía `.md` en StackEdit.
2. Menú **≡** → **Export as…** → **HTML**.
3. En el diálogo de la captura ("Choose a template for your HTML export") selecciona **Styled HTML with TOC**.
4. Clic **OK**.
5. Guarda el archivo (por ejemplo `CP4.html`).
6. Sube el HTML al repositorio (sugerido: `PED/GuiasHTML/CP4.html`) y publícalo si usas GitHub Pages.

> **Nota**: La plantilla "Styled HTML with TOC" incluye estilos básicos y una **Tabla de Contenido** generada a partir de los encabezados del Markdown.

## Dónde colocar los HTML en el repo

* Carpeta sugerida: `PED/`
* Estructura ejemplo:

```
PED/
    CP4.html
  Markdown/
    CP4.md
  Imagenes/
    CP4/
      B.png
```

## Referencias de imágenes en el HTML
* Alternativa robusta: usar **URL RAW** o **GitHub Pages** para imágenes, por ejemplo:
  * RAW: `https://raw.githubusercontent.com/<owner>/<repo>/main/PED/Imagenes/CP4/B.png`

## Buenas prácticas de exportación

* **Nombre del archivo**: usa el mismo del `.md` (p. ej., `CP4.html`).
* **Enlaces internos**: si en el `.md` enlazas otras guías, asegúrate de que apunten a su versión `.html` al publicar.
* **TOC**: la plantilla con TOC se basa en encabezados `#`, `##`, `###`. Mantén una jerarquía clara.
* **Revisión visual**: abre el HTML exportado en el navegador y recorre todos los enlaces e imágenes.

## Flujo completo sugerido

1. Edita la guía en `.md` con StackEdit.
2. Inserta imágenes usando **URL RAW/PAGES** (ver secciones anteriores).
3. **Exporta a HTML** con la plantilla **Styled HTML with TOC** (o tu plantilla personalizada).
4. Sube el HTML a `PED/`.
5. Verifica la URL pública de **GitHub Pages**.
6. Ejemplo: [https://meaguilar.github.io/PED/CP4.html](https://meaguilar.github.io/PED/CP4.html)
