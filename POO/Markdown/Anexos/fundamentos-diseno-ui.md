# Fundamentos de diseño UI en Figma

## Importancia de conocer las dimensiones

Comprender las dimensiones de pantalla es fundamental para diseñar interfaces adaptadas a distintos dispositivos. Conocer los tamaños más utilizados permite crear diseños más consistentes, optimizar la experiencia de usuario y validar correctamente la distribución de los elementos antes del desarrollo.

### ¿Por qué es importante?

-   Diseñar para resoluciones reales de usuarios.
    
-   Definir correctamente el tamaño de los frames en Figma.
    
-   Anticipar comportamientos responsivos.
    
-   Mejorar la experiencia visual en diferentes dispositivos.
    

### Referencia

-   Screensize: [https://www.screensize.io/](https://www.screensize.io/)
    

----------

# Sistema de 8 puntos (8pt Grid)

El sistema de **8 puntos (8pt Grid)** es una metodología de espaciado utilizada en diseño de interfaces. Consiste en definir que todos los márgenes, paddings, separaciones y dimensiones se construyan utilizando múltiplos de 8 píxeles.

## Ejemplos

|Correcto  |Incorrecto  |
|:--------:|:----------:|
| 8px      |7px         |	
| 16px     |15px        |
| 24px     |22px        |
| 32px     |31px        |
| 40px     |38px        |


## Beneficios

-   Mayor consistencia visual.
    
-   Facilita la alineación de componentes.
    
-   Mejora la escalabilidad del diseño.
    
-   Simplifica la comunicación entre diseño y desarrollo.
    

## Relación con otros conceptos

El sistema 8pt se aplica directamente en:

-   Principios CARP (especialmente **Alineación** y **Proximidad**).
    
-   Configuración de espacios dentro de **Auto Layout**.
    
-   Diseño de componentes reutilizables.
    

## Referencias

-   Figma Community: [https://www.figma.com/community/file/1342415305553231324](https://www.figma.com/community/file/1342415305553231324)
    
-   Video explicativo: [https://www.youtube.com/watch?v=sK7ZapOAR1M](https://www.youtube.com/watch?v=sK7ZapOAR1M)
    

----------

# Guía de dimensiones y componentes UI

Una vez definido el sistema de 8 puntos, es importante establecer tamaños estándar para los componentes más utilizados en una interfaz.

El objetivo no es seguir reglas rígidas, sino mantener consistencia visual y facilitar la implementación durante el desarrollo.

----------

## Grid Recomendado para Desktop

### Frame Desktop

```text
1440px

```

### Layout Grid

```text
12 columnas
Margin: 32px
Gutter: 24px

```

### Grid Vertical

```text
Rows: Auto
Height: 8px
Gutter: 8px
Alignment: Top

```

Esta configuración se integra perfectamente con el sistema de 8 puntos y facilita la construcción de interfaces escalables mediante Auto Layout.

----------

## Medidas más utilizadas
| Categoría | Componente | Tamaño recomendado |
|:---------:|:----------:|:------------------:|
| Campos de entrada | TextField | 48px alto |
| Campos de entrada | Select | 48px alto |
| Campos de entrada | Text Area | 96px mínimo |
| Controles | Button | 48px alto |
| Controles | Checkbox | 16 × 16px |
| Controles | Radio Button | 16 × 16px |
| Navegación | Navbar Desktop | 64px alto |
| Navegación | Navbar Mobile | 56px alto |
| Navegación | Sidebar | 280px ancho |
| Espaciado interno | Card Padding | 24px |
| Espaciado interno | Modal Padding | 24px |
| Estilo visual | Border Radius Base | 8px |
| Espaciado | Espaciado pequeño | 8px |
| Espaciado | Espaciado entre campos | 16px |
| Espaciado | Espaciado interno estándar | 24px |
| Espaciado | Separación entre secciones | 32px |
| Espaciado | Separación entre bloques principales | 48px |
| Botones | Ancho mínimo de botón | 120px |
| Formularios | Ancho recomendado de formulario | 480–640px |
| Tablas | Altura mínima de fila | 48px |
| Iconografía | Tamaño de iconos estándar | 20–24px |
----------

# Auto Layout (Herramienta de Figma)

**Auto Layout** es una herramienta de Figma que permite organizar, alinear y distribuir elementos automáticamente dentro de un frame o componente.

A diferencia del sistema de 8 puntos, Auto Layout **no define reglas de espaciado**, sino que administra cómo se comportan los elementos dentro de una estructura flexible.

## Funcionalidades principales

-   Distribución automática de elementos.
    
-   Espaciado consistente entre componentes.
    
-   Adaptación dinámica al contenido.
    
-   Creación de interfaces responsivas.
    
-   Reutilización eficiente de componentes.
    

## Beneficios

-   Reduce el trabajo manual de alineación.
    
-   Facilita cambios de contenido.
    
-   Mejora la escalabilidad de los diseños.
    
-   Permite construir sistemas de diseño más robustos.
    

## Relación con el sistema 8pt

El sistema 8pt define **qué espacios utilizar**, mientras que Auto Layout define **cómo se organizan esos espacios dentro de la interfaz**.

## Referencia

-   Guía oficial de Figma:  
    [https://help.figma.com/hc/en-us/articles/360040451373-Guide-to-auto-layout](https://help.figma.com/hc/en-us/articles/360040451373-Guide-to-auto-layout)
    

----------

# Principios CARP en Diseño GUI

Los principios **CARP** son fundamentos del diseño visual que ayudan a construir interfaces claras, organizadas y consistentes.

CARP significa:

-   **C**ontrast (Contraste)
    
-   **A**lignment (Alineación)
    
-   **R**epetition (Repetición)
    
-   **P**roximity (Proximidad)
    

----------

## Contraste (Contrast)

Permite diferenciar elementos importantes mediante cambios visuales como:

-   Tamaño
    
-   Color
    
-   Peso tipográfico
    
-   Espaciado
    
-   Forma
    

### Objetivo

Guiar la atención del usuario hacia la información más relevante.

----------

## Alineación (Alignment)

Consiste en organizar los elementos siguiendo una estructura visual coherente.

### Buenas prácticas

-   Utilizar grids y columnas.
    
-   Mantener alineaciones consistentes.
    
-   Evitar elementos colocados arbitrariamente.
    

### Relación con 8pt Grid

La alineación se fortalece cuando todos los elementos respetan una misma unidad de medida.

----------

## Repetición (Repetition)

Consiste en reutilizar patrones visuales a lo largo de la interfaz.

### Elementos que pueden repetirse

-   Colores
    
-   Tipografías
    
-   Botones
    
-   Espaciados
    
-   Componentes
    

### Objetivo

Mantener una experiencia visual coherente y familiar para el usuario.

----------

## Proximidad (Proximity)

Agrupa elementos relacionados para facilitar su comprensión.

### Objetivo

Reducir el desorden visual y mejorar la lectura de la interfaz.

### Ejemplos

-   Etiqueta y campo de formulario cercanos.
    
-   Opciones de un mismo grupo agrupadas visualmente.
    

### Relación con 8pt Grid

Los espacios definidos mediante múltiplos de 8 ayudan a crear agrupaciones visuales consistentes.

----------

## Referencias CARP

-   [https://medium.com/@pandubudikusuma/application-of-contrast-alignment-repetition-and-proximity-carp-in-ui-design-13dce8bd7c8c](https://medium.com/@pandubudikusuma/application-of-contrast-alignment-repetition-and-proximity-carp-in-ui-design-13dce8bd7c8c)
    
-   [https://online.fliphtml5.com/uejlb/wnsd/#p=1](https://online.fliphtml5.com/uejlb/wnsd/#p=1)
    
-   [https://www.figma.com/resource-library/graphic-design-principles/](https://www.figma.com/resource-library/graphic-design-principles/)
    

----------

# Recursos Extra para Diseño UI

## Iconos

-   [https://boxicons.com/icons?free=true](https://boxicons.com/icons?free=true)
    

## Imágenes

-   [https://unsplash.com/es](https://unsplash.com/es)
    

## Paletas de color

-   [https://coolors.co](https://coolors.co/)
    

## Tipografías

-   [https://fonts.google.com](https://fonts.google.com/)
    

----------

# Resumen del Proceso de Diseño

## Wireframe

El wireframe define la estructura y organización de la interfaz.

### Herramientas y recursos

-   Figma
    
-   Screensize
    
-   Sistema 8pt Grid
    

### Objetivo

Definir distribución, jerarquía y tamaño de los elementos sin enfocarse aún en el aspecto visual final.

----------

## Mockup

El mockup representa el diseño visual completo de la interfaz.

### Herramientas y recursos

-   Figma
    
-   Tipografías
    
-   Paletas de color
    
-   Imágenes
    
-   Iconos
    

### Objetivo

Mostrar cómo lucirá el producto final antes de pasar a la etapa de desarrollo.

----------

# Conclusión

Un buen diseño de interfaces combina:

1.  Conocimiento de las dimensiones reales de los dispositivos.
    
2.  Uso consistente del sistema de 8 puntos.
    
3.  Construcción flexible mediante Auto Layout.
    
4.  Aplicación correcta de los principios CARP.
    
5.  Uso de componentes con dimensiones estandarizadas.
    

La combinación de estos elementos permite crear interfaces más ordenadas, escalables, consistentes, accesibles y fáciles de implementar tanto en diseño como en desarrollo.