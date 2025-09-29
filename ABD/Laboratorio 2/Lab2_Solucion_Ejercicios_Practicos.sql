
/* 
   LABORATORIO 2 SOLUCION DE EJERCICIOS PROPUESTOS (3 claves)
   PREREQUISITO: La base DB_Gimnasio y las tablas deben estar ya creadas en el schema dbo.
   ACLARACION: CADA GRUPO DE LABORATORIO SOLO TIENE QUE HACER UNA DE LAS CLAVES 

   ENTREGABLES (para cada ejercicio):
   - Script .sql ordenado con creacion de logins/usuarios/roles y pruebas.
   - Agregar documentacion y trabajar en orden el codigo
   - Captura de pantalla del error por DENY DELETE.
*/

/* 
   Ejercicio 1: Aplicacion con CRUD parcial 
   - Crea un login/usuario de aplicacion llamados ex1_app_gym y un rol llamado ex1_db_app.
   - NOTA: Los usuarios de aplicacion tiene el check_expiration OFF.
   - Otorga al rol los privilegios SELECT/INSERT/UPDATE sobre las tablas dbo.Cliente y dbo.Membresia.
   - Prohibe eliminar registros en dbo.Cliente.
   - Prueba: INSERT y UPDATE (deben funcionar) y DELETE (debe fallar).
   - Toma captura de pantalla del error al intentar realizar DELETE en dbo.Cliente.
*/

-- 1) LOGIN (servidor)
USE [master];
IF NOT EXISTS (SELECT 1 FROM sys.server_principals WHERE name = N'ex1_app_gym')
BEGIN
    PRINT 'Creando LOGIN [ex1_app_gym]';
    CREATE LOGIN [ex1_app_gym]
    WITH PASSWORD = 'UCA@2025',
         CHECK_POLICY = ON,
         CHECK_EXPIRATION = OFF; -- cuenta de aplicacion
END
GO

-- 2) USER (base) y ROLE
USE DB_Gimnasio;

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex1_app_gym')
BEGIN
    PRINT 'Creando USER [ex1_app_gym] en DB_Gimnasio';
    CREATE USER [ex1_app_gym] FOR LOGIN [ex1_app_gym];
END

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex1_db_app')
BEGIN
    PRINT 'Creando ROLE [ex1_db_app]';
    CREATE ROLE [ex1_db_app];
END

-- 3) Permisos
GRANT SELECT, INSERT, UPDATE ON dbo.Cliente   TO [ex1_db_app]; -- Otorgando permisos sobre dbo.Cliente
GRANT SELECT, INSERT, UPDATE ON dbo.Membresia TO [ex1_db_app]; -- Otorgando permisos sobre dbo.Membresia
DENY DELETE ON dbo.Cliente TO [ex1_db_app]; -- Bloquear opcion de eliminar

-- 4) Miembro de rol
EXEC sp_addrolemember 'ex1_db_app', 'ex1_app_gym';
GO

-- 5) PRUEBAS
USE DB_Gimnasio;

-- Probando permisos (deberian funcionar)
EXECUTE AS USER = 'ex1_app_gym';

-- Prueba de insert
INSERT INTO dbo.Cliente (nombre, email) VALUES (N'Cliente prueba', N'prueba@gmail.com');

-- Prueba de update
DECLARE @id INT = (SELECT MAX(id) FROM dbo.Cliente); 
UPDATE dbo.Cliente SET email = N'prueba2@hotmail.com' WHERE id = @id;
REVERT;

-- *** TOMAR CAPTURA DE PANTALLA DEL ERROR QUE APARECE AL EJECUTAR EL DELETE ***
DELETE FROM dbo.Cliente WHERE id = 1;  -- debe FALLAR por DENY DELETE
REVERT;
GO

/* 
   Ejercicio 2: Capturista de Membresias sin modificaciones
   - Crea un login/usuario de aplicación llamados ex2_data_entry y un rol llamado ex2_db_entry.
   - NOTA: Los usuarios de aplicación tienen el check_expiration OFF.
   - Otorga al rol permisos SELECT sobre dbo.Cliente (para consultar clientes existentes).
   - Otorga permisos SELECT e INSERT sobre dbo.Membresia (para registrar nuevas membresías).
   - Prohíbe que el rol realice UPDATE o DELETE sobre dbo.Membresia.
   - Prueba: SELECT, INSERT (deben funcionar), UPDATE y DELETE (deben fallar).
   - Toma captura de pantalla del error al intentar realizar DELETE en dbo.Membresia.
*/

-- 1) LOGIN 
USE [master];
IF NOT EXISTS (SELECT 1 FROM sys.server_principals WHERE name = N'ex2_data_entry')
BEGIN
    PRINT 'Creando LOGIN [ex2_data_entry]';
    CREATE LOGIN [ex2_data_entry]
    WITH PASSWORD = 'UCA@2025',
         CHECK_POLICY = ON,
         CHECK_EXPIRATION = OFF; -- cuenta de aplicacion
END
GO

-- 2) USER y ROLE
USE DB_Gimnasio;

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex2_data_entry')
BEGIN
    PRINT 'Creando USER [ex2_data_entry] en DB_Gimnasio';
    CREATE USER [ex2_data_entry] FOR LOGIN [ex2_data_entry];
END

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex2_db_entry')
BEGIN
    PRINT 'Creando ROLE [ex2_db_entry]';
    CREATE ROLE [ex2_db_entry];
END

-- 3) Permisos
GRANT SELECT ON dbo.Cliente TO [ex2_db_entry];
GRANT SELECT, INSERT ON dbo.Membresia TO [ex2_db_entry];
DENY  UPDATE, DELETE ON dbo.Membresia TO [ex2_db_entry]; -- Bloquear modificaciones

-- 4) Miembro de rol
EXEC sp_addrolemember 'ex2_db_entry', 'ex2_data_entry';
GO

-- 5) PRUEBAS
USE DB_Gimnasio;

-- Probando permisos (deberian funcionar)
EXECUTE AS USER = 'ex2_data_entry';
SELECT TOP(3) id, nombre, email FROM dbo.Cliente ORDER BY id;
REVERT;

DECLARE @id INT = (SELECT MAX(id) FROM dbo.Cliente); 
INSERT INTO dbo.Membresia (cliente_id, plan_membresia, fecha_inicio)
VALUES (@id, N'Basico', GETDATE());
REVERT;

-- Probando permisos (UPDATE debe FALLAR)
EXECUTE AS USER = 'ex2_data_entry';
UPDATE dbo.Membresia SET plan_membresia = N'No Permitido' WHERE id = (SELECT MAX(id) FROM dbo.Membresia);
REVERT;

EXECUTE AS USER = 'ex2_data_entry';
-- *** TOMAR CAPTURA DE PANTALLA DEL ERROR QUE APARECE A CONTINUACION ***
DELETE FROM dbo.Membresia WHERE id = (SELECT MAX(id) FROM dbo.Membresia);
REVERT;
GO

/* 
   Ejercicio 3: Backoffice de Membresias con actualización controlada
   - Crea un login/usuario de backoffice llamados ex3_backoffice y un rol llamado ex3_db_backoffice.
   - NOTA: Los usuarios de backoffice tienen el check_expiration ON (contraseña con vencimiento).
   - Otorga al rol permisos SELECT sobre dbo.Cliente (para consultar clientes).
   - Otorga permisos SELECT/INSERT/UPDATE sobre dbo.Membresia (para dar de alta y modificar membresías).
   - Prohíbe que el rol realice DELETE sobre dbo.Membresia.
   - Prueba: SELECT, INSERT y UPDATE (deben funcionar) y DELETE (debe fallar).
   - Toma captura de pantalla del error al intentar realizar DELETE en dbo.Membresia.
*/

-- 1) LOGIN 
USE [master];
IF NOT EXISTS (SELECT 1 FROM sys.server_principals WHERE name = N'ex3_backoffice')
BEGIN
    PRINT 'Creando LOGIN [ex3_backoffice]...';
    CREATE LOGIN [ex3_backoffice]
    WITH PASSWORD = 'UCA@2025',
         CHECK_POLICY = ON,
         CHECK_EXPIRATION = ON; -- cuenta de usuario normal
END
GO

-- 2) USER y ROLE
USE DB_Gimnasio;

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex3_backoffice')
BEGIN
    PRINT 'Creando USER [ex3_backoffice] en DB_Gimnasio...';
    CREATE USER [ex3_backoffice] FOR LOGIN [ex3_backoffice];
END

IF NOT EXISTS (SELECT 1 FROM sys.database_principals WHERE name = N'ex3_db_backoffice')
BEGIN
    PRINT 'Creando ROLE [ex3_db_backoffice]...';
    CREATE ROLE [ex3_db_backoffice];
END

-- 3) Permisos
GRANT SELECT ON dbo.Cliente TO [ex3_db_backoffice];
GRANT SELECT, INSERT, UPDATE ON dbo.Membresia TO [ex3_db_backoffice];
DENY  DELETE ON dbo.Membresia TO [ex3_db_backoffice];

-- 4) Miembro de rol
EXEC sp_addrolemember 'ex3_db_backoffice', 'ex3_backoffice';
GO

-- 5) PRUEBAS
USE DB_Gimnasio;

-- Probando permisos (deberian funcionar)
EXECUTE AS USER = 'ex3_backoffice';

DECLARE @clienteId INT = (SELECT MAX(id) FROM dbo.Cliente); 
INSERT INTO dbo.Membresia(cliente_id, plan_membresia, fecha_inicio)
VALUES (@clienteId, N'Mensual', GETDATE());

DECLARE @mId INT = (SELECT MAX(id) FROM dbo.Membresia); 
UPDATE dbo.Membresia SET plan_membresia = N'Bimestral' WHERE id = @mId;
REVERT;
GO

-- Probando permisos (DELETE debe FALLAR)
EXECUTE AS USER = 'ex3_backoffice';

-- *** TOMAR CAPTURA DE PANTALLA DEL ERROR QUE APARECE A CONTINUACION ***
DELETE FROM dbo.Membresia WHERE id = (SELECT MAX(id) FROM dbo.Membresia);  -- Debe FALLAR
REVERT;
GO