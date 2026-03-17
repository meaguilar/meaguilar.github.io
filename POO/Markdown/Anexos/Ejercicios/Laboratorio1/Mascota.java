package POO.Markdown.Anexos.Ejercicios.Laboratorio1;

public class Mascota {
    // Atributos encapsulados
    private String nombre;
    private int edad;
    private  boolean  comiendo;

    // Constructor parametrizado
    public Mascota(String nombre, int edad, boolean comiendo) {
        this.nombre = nombre;
        this.edad = edad;
        this.comiendo = comiendo;
    }
    // Métodos de acceso (getters y setters)
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public  boolean  isComiendo() {
        return comiendo;
    }

    public  void  setComiendo(boolean  comiendo) {
        this.comiendo = comiendo;
    }
    // Métodos
    public void comer() {
        this.comiendo = true;
        System.out.println("La mascota está comiendo.");
    }

    public void dejarDeComer() {
        this.comiendo = false;
        System.out.println("La mascota dejó de comer.");
    }

    public void mostrarInfo() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("¿Está comiendo? " + (comiendo ? "Sí" : "No"));
    }
}
