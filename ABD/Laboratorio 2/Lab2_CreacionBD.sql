-- Base de datos a utilizar para la realización de los ejercicios practicos.
-- Administración de bases de datos 02-2025

IF DB_ID(N'DB_Gimnasio') IS NULL
BEGIN
    PRINT 'Creando base de datos DB_Gimnasio...';
    CREATE DATABASE DB_Gimnasio;
END
GO

USE DB_Gimnasio;

IF OBJECT_ID(N'dbo.Cliente', N'U') IS NULL
BEGIN
    CREATE TABLE dbo.Cliente (
        id INT IDENTITY(1,1) PRIMARY KEY,
        nombre NVARCHAR(100) NOT NULL,
        email  NVARCHAR(100) NULL,
        fecha_alta DATE NOT NULL DEFAULT (GETDATE())
    );
INSERT INTO dbo.Cliente(nombre,email) 
VALUES ('Ana Pérez','ana@fit.com'),('Luis Díaz','luis@fit.com'),('María López','maria@fit.com'); 
END

IF OBJECT_ID(N'dbo.Membresia', N'U') IS NULL
BEGIN
    CREATE TABLE dbo.Membresia (
        id INT IDENTITY(1,1) PRIMARY KEY,
        cliente_id INT NOT NULL,
		plan_membresia NVARCHAR(40) NOT NULL, 
        fecha_inicio DATE NOT NULL DEFAULT (GETDATE()),
        fecha_fin    DATE NULL,
        CONSTRAINT FK_Membresia_Cliente FOREIGN KEY (cliente_id) REFERENCES dbo.Cliente(id)
    );
	  INSERT INTO dbo.Membresia(cliente_id,plan_membresia,fecha_inicio,fecha_fin) 
	  VALUES (1,'Mensual','2025-08-01',NULL),(2,'Trimestral','2025-07-15','2025-10-14'); 
END
