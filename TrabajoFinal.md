# Actividad Final

## **Contenido**

### Sistemas de Archivos

#### **Ejercicio 1: Concepto y Noción de Archivo Real y Virtual**

**Descripción:**

- Define los conceptos de archivo real y archivo virtual y explica sus diferencias.
- Identifica ejemplos prácticos de cada tipo en sistemas operativos actuales.

**Respuesta:**

1. **Archivo real:** Un archivo real es aquel que existe físicamente en un medio de almacenamiento (por ejemplo, un disco duro). Contiene datos que pueden ser accedidos directamente. Ejemplo: Un documento de texto (.txt) almacenado en el disco.
   
   **Archivo virtual:** Un archivo virtual no existe como una entidad física, sino que es generado dinámicamente por el sistema operativo o una aplicación, basado en datos reales o simulados. Ejemplo: “/dev/null” en sistemas Linux.

2. **Diferencias:** Los archivos reales ocupan espacio de almacenamiento, mientras que los virtuales no. Además, los archivos reales son independientes de la aplicación que los crea, mientras que los virtuales dependen del sistema operativo para su generación.

3. **Caso práctico:** Un archivo virtual es útil en escenarios como la simulación de dispositivos (por ejemplo, impresoras virtuales o unidades de disco virtual) donde no se requiere almacenamiento real.

---

#### **Ejercicio 2: Componentes de un Sistema de Archivos**

**Descripción:**

- Investiga los componentes principales de un sistema de archivos y compáralos entre dos sistemas operativos, como Linux y Windows.

**Respuesta:**

1. **Componentes clave:**
   - Metadatos: Información sobre el archivo (nombre, tamaño, permisos).
   - Tablas de asignación: Mapas que indican dónde están almacenados los datos en el disco.
   - Directorios: Estructuras jerárquicas para organizar archivos.

2. **Cuadro comparativo:**

| Componente        | EXT4 (Linux)                     | NTFS (Windows)                     |
|-------------------|-----------------------------------|-------------------------------------|
| Metadatos         | Estructuras flexibles, journaling | Soporte avanzado, journaling       |
| Tablas de asignación | Tabla basada en bloques         | Tabla basada en clústers           |
| Directorios       | Organizados jerárquicamente      | Integración con ACLs para permisos |

3. **Ventajas y desventajas:**
   - EXT4: Mayor estabilidad en sistemas Linux, pero menos compatible con Windows.
   - NTFS: Mejor compatibilidad con Windows, pero con mayor sobrecarga en recursos.

---

#### **Ejercicio 3: Organización Lógica y Física de Archivos**

**Descripción:**

- Crea un esquema que muestre la organización lógica y física de un sistema de archivos. Explica cómo se relacionan las estructuras lógicas con las físicas en el disco.

**Respuesta:**

1. **Organización lógica:**
   ```
   / (root)
   |
   |-- /home
   |    |-- /user1
   |    |-- /user2
   |
   |-- /var
   |-- /etc
   ```

2. **Relación con estructuras físicas:** La dirección lógica (por ejemplo, /home/user1) se traduce a bloques específicos en el disco duro mediante las tablas de asignación de archivos.

3. **Ejemplo práctico:** Un archivo creado en /home/user1 se almacena en bloques contiguos (o no contiguos) en el disco, con su ubicación registrada en una tabla como FAT o inode.

---

#### **Ejercicio 4: Mecanismos de Acceso a los Archivos**

**Descripción:**

- Simula diferentes mecanismos de acceso a archivos (secuencial, directo e indexado) en un entorno práctico.

**Respuesta:**

1. **Definiciones:**
   - Acceso secuencial: Lectura o escritura de datos en orden consecutivo.
   - Acceso directo: Acceso aleatorio a una posición específica del archivo.
   - Acceso indexado: Uso de un índice para localizar datos rápidamente.

2. **Pseudocódigos:**
   ```
   # Acceso secuencial
   for line in file:
       print(line)

   # Acceso directo
   file.seek(position)
   data = file.read(bytes)

   # Acceso indexado
   index = {"key1": offset1, "key2": offset2}
   file.seek(index["key1"])
   data = file.read()
   ```

3. **Ventajas:**
   - Secuencial: Simple y eficiente para archivos ordenados.
   - Directo: útil para bases de datos o registros específicos.
   - Indexado: Rápido para buscar datos específicos en grandes volúmenes de información.

---

#### **Ejercicio 5: Modelo Jerárquico y Mecanismos de Recuperación en Caso de Falla**

**Descripción:**

- Diseña una estructura jerárquica para un sistema de archivos y simula un escenario de falla en el sistema. Describe cómo recuperar los datos utilizando mecanismos de recuperación.

**Respuesta:**

1. **Modelo jerárquico:**
   ```
   / (root)
   |
   |-- /home
   |    |-- /user1
   |         |-- file.txt
   ```

2. **Simulación de falla:** Si el directorio /home/user1 falla, el sistema intenta recuperar la información desde un respaldo.

3. **Técnicas de recuperación:** Usar herramientas como "rsync" o snapshots para restaurar los datos perdidos.

---

### Protección y Seguridad

#### **Ejercicio 1: Concepto y Objetivos de Protección y Seguridad**

**Respuesta:**

1. **Definiciones:**
   - Protección: Control de acceso para garantizar que solo usuarios autorizados interactúen con los recursos.
   - Seguridad: Prevención de amenazas externas e internas.

2. **Objetivos:**
   - Confidencialidad: Asegurar que solo usuarios autorizados accedan a los datos.
   - Integridad: Garantizar que los datos no sean alterados sin autorización.
   - Disponibilidad: Mantener los recursos accesibles.

3. **Ejemplo práctico:** Uso de contraseñas y encriptación para proteger información sensible en un servidor.

---

#### **Ejercicio 2: Clasificación Aplicada a la Seguridad**

**Respuesta:**

1. **Clasificaciones:**
   - Seguridad física: Protección de hardware y dispositivos. Ejemplo: Cerraduras físicas para servidores.
   - Seguridad lógica: Mecanismos de protección de software y datos. Ejemplo: Contraseñas y firewalls.
   - Seguridad de red: Protección de la comunicación de datos en redes. Ejemplo: Uso de VPNs o encriptación TLS.

2. **Papel de cada clasificación:** Cada nivel trabaja en conjunto para minimizar riesgos, asegurando que los datos estén protegidos tanto en su almacenamiento como en su transmisión.

3. **Ejemplos prácticos:**
   - Físico: Sistemas de vigilancia en centros de datos.
   - Lógico: Uso de software antivirus.
   - Red: Configuración de firewalls para bloquear acceso no autorizado.

---

#### **Ejercicio 3: Funciones del Sistema de Protección**

**Respuesta:**

1. **Control de acceso:** El sistema verifica credenciales para permitir o denegar acceso a recursos. Ejemplo: Login de usuarios.

2. **Funciones principales:**
   - Autenticación: Validación de identidad. Ejemplo: Uso de contraseñas o biometría.
   - Autorización: Permitir acciones específicas según roles. Ejemplo: Un administrador puede modificar configuraciones, pero un usuario básico no.
   - Auditoría: Registro de actividades. Ejemplo: Monitoreo de accesos y cambios.

3. **Caso práctico:** Un sistema multiusuario donde un estudiante solo puede leer archivos, pero un profesor puede editarlos.

---

#### **Ejercicio 4: Implantación de Matrices de Acceso**

**Respuesta:**

1. **Matriz de acceso:**

| Usuario   | Recurso 1 (Lectura) | Recurso 2 (Escritura) | Recurso 3 (Ejecución) | Recurso 4 (Completo) |
|-----------|----------------------|-----------------------|-------------------------|-----------------------|
| Usuario1  | X                    |                      |                         |                       |
| Usuario2  | X                    | X                     |                         |                       |
| Admin     | X                    | X                     | X                       | X                     |

2. **Control de acceso:** La matriz asegura que cada usuario sólo pueda realizar acciones autorizadas. Ejemplo: Usuario1 intenta escribir en Recurso 2 y se le niega acceso.

3. **Simulación:** Si Usuario2 intenta ejecutar Recurso 3, el sistema deniega la acción basándose en la matriz de permisos.

---

#### **Ejercicio 5: Protección Basada en el Lenguaje**

**Respuesta:**

1. **Definición:** Algunos lenguajes como Java o Rust incluyen características que garantizan seguridad, como manejo seguro de memoria para evitar errores como desbordamientos de buffer.

2. **Ejemplo:** En Rust, el compilador previene accesos no autorizados a memoria mediante verificaciones estrictas en tiempo de compilación.

3. **Comparación:**
   - Protección basada en lenguaje: Mecanismos internos al código.
   - Otros enfoques: Uso de herramientas externas como antivirus o firewalls.

---

#### **Ejercicio 6: Validación y Amenazas al Sistema**

**Respuesta:**

1. **Amenazas comunes:**
   - Malware: Software malicioso que daña o roba información.
   - Fuerza bruta: Intentos repetitivos para adivinar contraseñas.
   - Inyección de código: Inserción de comandos maliciosos en aplicaciones vulnerables.

2. **Mecanismos de validación:**
   - Autenticación multifactor: Uso de varios métodos de verificación (contraseña + código SMS).
   - Control de integridad: Verificar que los archivos no hayan sido alterados.

3. **Esquema de validación:** Un sistema operativo puede usar hashes para verificar la integridad de archivos y registros de acceso.

---

#### **Ejercicio 7: Cifrado**

**Respuesta:**

1. **Definiciones:**
   - Cifrado simétrico: Usa una misma clave para cifrar y descifrar. Ejemplo: AES.
   - Cifrado asimétrico: Usa una clave pública para cifrar y una privada para descifrar. Ejemplo: RSA.

2. **Ejemplo práctico:**
   - Simétrico: Cifrar un archivo con AES para protegerlo.
   - Asimétrico: Enviar datos seguros por correo electrónico usando claves RSA.

3. **Simulación:**
   - Cifrado: `echo "texto" | openssl enc -aes-256-cbc -e -k clave`
   - Descifrado: `echo "texto_cifrado" | openssl enc -aes-256-cbc -d -k clave`.

