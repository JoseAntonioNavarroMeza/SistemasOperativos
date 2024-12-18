# Actividades: Dispositivos de entrada y salida en Linux

## Introducción
En este ejercicio, aprenderá a listar, verificar y analizar los dispositivos de entrada y salida en Linux. Usarán comandos básicos y herramientas comunes disponibles en cualquier distribución.

---

# **ACT1: Listar dispositivos conectados**

## Objetivo
Conocer los dispositivos de entrada y salida conectados al sistema.

## Instrucciones
Abra una terminal en su entorno Linux.
Ejecute los siguientes comandos y anote sus observaciones:

### `lsblk`: Enumera los dispositivos de bloque.

```bash
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0 269.8M  1 loop /snap/firefox/4793
loop2    7:2    0  74.3M  1 loop /snap/core22/1564
loop3    7:3    0  10.7M  1 loop /snap/firmware-updater/127
loop4    7:4    0 505.1M  1 loop /snap/gnome-42-2204/176
loop5    7:5    0  91.7M  1 loop /snap/gtk-common-themes/1535
loop6    7:6    0  10.5M  1 loop /snap/snap-store/1173
loop7    7:7    0  38.8M  1 loop /snap/snapd/21759
loop8    7:8    0   500K  1 loop /snap/snapd-desktop-integration/178
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sr0     11:0    1  56.9M  0 rom  /media/vboxuser/VBox_GAs_7.1.4
```
---

### `lsusb`: Lista los dispositivos conectados a los puertos USB.
```bash
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 002 Device 002: ID 80ee:0021 VirtualBox USB Tablet
```
---

### `lspci`: Muestra los dispositivos conectados al bus PCI.
```bash
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
```
---

### `dmesg | grep usb`: Muestra los mensajes del kernel relacionados con dispositivos USB.
```bash
[sudo] password for vboxuser: 
[    0.352568] usbcore: registered new interface driver usbfs
[    0.352568] usbcore: registered new interface driver hub
[    0.352568] usbcore: registered new device driver usb
[    0.449637] usb usb1: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.08
[    0.449642] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.449643] usb usb1: Product: EHCI Host Controller
[    0.449644] usb usb1: Manufacturer: Linux 6.8.0-51-generic ehci_hcd
[    0.449645] usb usb1: SerialNumber: 0000:00:0b.0
[    0.545872] usb usb2: New USB device found, idVendor=1d6b, idProduct=0001, bcdDevice= 6.08
[    0.545877] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.545878] usb usb2: Product: OHCI PCI host controller
[    0.545878] usb usb2: Manufacturer: Linux 6.8.0-51-generic ohci_hcd
[    0.545879] usb usb2: SerialNumber: 0000:00:06.0
[    0.840467] usb 2-1: new full-speed USB device number 2 using ohci-pci
[    1.241949] usb 2-1: New USB device found, idVendor=80ee, idProduct=0021, bcdDevice= 1.00
[    1.241954] usb 2-1: New USB device strings: Mfr=1, Product=3, SerialNumber=0
[    1.241955] usb 2-1: Product: USB Tablet
[    1.241956] usb 2-1: Manufacturer: VirtualBox
[    1.403539] usbcore: registered new interface driver usbhid
[    1.403542] usbhid: USB HID core driver
[    1.408764] input: VirtualBox USB Tablet as /devices/pci0000:00/0000:00:06.0/usb2/2-1/2-1:1.0/0003:80EE:0021.0001/input/input6
[    1.408823] hid-generic 0003:80EE:0021.0001: input,hidraw0: USB HID v1.10 Mouse [VirtualBox USB Tablet] on usb-0000:00:06.0-1/input0
```
---

## Conteste:
### **1. Tipos de dispositivos en la salida de `lsblk`:**
La salida de `lsblk` enumera dispositivos de bloque conectados al sistema, como discos duros, particiones y dispositivos de bucle (loop). En este caso:

- **`loopX`**: Dispositivos de bucle, utilizados para montar imágenes o archivos como si fueran discos físicos. Ejemplos en la salida: `/snap/firefox/4793`, `/snap/core22/1564`, etc.
- **`sda`**: Un disco físico virtual con dos particiones:
  - **`sda1`**: Una partición de 1 MB (probablemente utilizada para datos de arranque).
  - **`sda2`**: Una partición de 25 GB montada en el sistema de archivos raíz (`/`).
- **`sr0`**: Unidad óptica virtual (CD-ROM) que contiene la imagen de las Guest Additions (`VBox_GAs_7.1.4`).

---

### **2. Diferencia entre `lsusb` y `lspci`:**

- **`lsusb`**:
  - Enumera dispositivos conectados a los puertos USB.
  - Proporciona identificadores como `idVendor` (fabricante) e `idProduct` (producto).
  - Ejemplo: Un dispositivo USB tablet conectado con `idVendor=80ee` y `idProduct=0021`.

- **`lspci`**:
  - Enumera dispositivos conectados al bus PCI, como tarjetas de red, controladores SATA y tarjetas gráficas.
  - Incluye detalles sobre el tipo de dispositivo, fabricante y modelo.
  - Ejemplo: Controlador de red `Intel Corporation 82540EM Gigabit Ethernet Controller`.

**Resumen**:  
`lsusb` se enfoca exclusivamente en dispositivos USB, mientras que `lspci` muestra dispositivos conectados al bus PCI.

---

### **3. Información adicional proporcionada por `dmesg | grep usb`:**

El comando `dmesg | grep usb` muestra mensajes del kernel relacionados con dispositivos USB. En este caso, proporciona:

1. **Registro de eventos USB**:
   - Reconocimiento de nuevos dispositivos USB conectados.
   - Ejemplo: `"New USB device found, idVendor=80ee, idProduct=0021"`.

2. **Detalles técnicos del controlador**:
   - Indica el tipo de controlador USB en uso, como:
     - `EHCI Host Controller` (para USB 2.0).
     - `OHCI PCI host controller`.

3. **Cargado de controladores**:
   - Registro de los drivers cargados para dispositivos USB, como `usbhid` (USB Human Interface Device).

4. **Asignación de dispositivos**:
   - Asigna un dispositivo a un archivo en `/dev`. Ejemplo: Dispositivo de entrada para el tablet USB: 
     `"hid-generic 0003:80EE:0021.0001"`.

**Resumen**:  
`dmesg | grep usb` proporciona una vista detallada del proceso de detección, inicialización y configuración de dispositivos USB por parte del kernel.
---
# ACT2: Verificar dispositivos de almacenamiento

## Objetivo

Aprender cómo identificar discos duros, particiones y su configuración.

## Intrucciones

Abra una terminal en su entorno Linux.
Ejecute los siguientes comandos y anote sus observaciones:

### Use el comando `fdisk -l` para listar todos los discos y particiones.
```bash
Disk /dev/loop0: 4 KiB, 4096 bytes, 8 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop1: 269.77 MiB, 282873856 bytes, 552488 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop2: 74.27 MiB, 77881344 bytes, 152112 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop3: 10.72 MiB, 11239424 bytes, 21952 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop4: 505.09 MiB, 529625088 bytes, 1034424 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop5: 91.69 MiB, 96141312 bytes, 187776 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop6: 10.54 MiB, 11051008 bytes, 21584 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop7: 38.83 MiB, 40714240 bytes, 79520 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/sda: 25 GiB, 26843545600 bytes, 52428800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 74325FC8-8394-472E-B18F-11319C58F470

Device     Start      End  Sectors Size Type
/dev/sda1   2048     4095     2048   1M BIOS boot
/dev/sda2   4096 52426751 52422656  25G Linux filesystem


Disk /dev/loop8: 500 KiB, 512000 bytes, 1000 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
```

### Utilice `blkid` para ver los identificadores UUID y los tipos de sistema de archivos.
```bash
/dev/sda2: UUID="bea16ab7-3d25-45cd-a1ea-200cc4e1991d" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="017c6ca7-ec81-49bf-8af9-9da9cfe6a367"
/dev/loop1: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop8: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop6: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop4: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/sr0: BLOCK_SIZE="2048" UUID="2024-10-10-17-52-15-90" LABEL="VBox_GAs_7.1.4" TYPE="iso9660"
/dev/loop2: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop0: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop7: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/sda1: PARTUUID="bcd0a217-850e-4285-9028-3c01d886b887"
/dev/loop5: BLOCK_SIZE="131072" TYPE="squashfs"
/dev/loop3: BLOCK_SIZE="131072" TYPE="squashfs"
```

### Use `df -h` para listar los dispositivos montados y su espacio disponible.
```bash
Filesystem      Size  Used Avail Use% Mounted on
tmpfs           794M  1.5M  793M   1% /run
/dev/sda2        25G  5.3G   18G  23% /
tmpfs           3.9G     0  3.9G   0% /dev/shm
tmpfs           5.0M  8.0K  5.0M   1% /run/lock
tmpfs           794M  124K  794M   1% /run/user/1000
/dev/sr0         57M   57M     0 100% /media/vboxuser/VBox_GAs_7.1.4
```

## Conteste:
### **1. ¿Qué dispositivos de almacenamiento están conectados a su sistema?**
Los dispositivos de almacenamiento detectados son:

1. **Dispositivos de bucle (`/dev/loopX`)**:
   - Usados para sistemas de archivos montados a partir de imágenes (como Snap).
   - Ejemplos: `/dev/loop0`, `/dev/loop1`, hasta `/dev/loop8`.

2. **Disco virtual principal (`/dev/sda`)**:
   - Tamaño: 25 GiB.
   - Modelo: `VBOX HARDDISK`.
   - Particiones:
     - `/dev/sda1`: 1 MiB, partición de arranque (BIOS boot).
     - `/dev/sda2`: 25 GiB, partición del sistema de archivos Linux.

3. **Unidad óptica virtual (`/dev/sr0`)**:
   - Contiene la imagen de las Guest Additions de VirtualBox (`VBox_GAs_7.1.4`).

---

### **2. ¿Qué particiones están montadas actualmente?**
Según la salida de `df -h`, las particiones montadas son:

1. **`/dev/sda2`**:
   - Montada en `/`.
   - Tamaño: 25 GiB, con 5.3 GiB usados y 18 GiB disponibles.

2. **`/dev/sr0`**:
   - Montada en `/media/vboxuser/VBox_GAs_7.1.4`.
   - Tamaño: 57 MiB (uso completo, 100%).

3. **Particiones temporales (`tmpfs`)**:
   - `tmpfs` en `/run`, `/dev/shm`, `/run/lock`, y `/run/user/1000`.

---

### **3. ¿Qué tipo de sistemas de archivos se usan en las particiones?**
Los sistemas de archivos detectados son:

1. **`ext4`**:
   - Usado en la partición principal `/dev/sda2`.

2. **`squashfs`**:
   - Usado en los dispositivos de bucle (`/dev/loopX`) para Snap.

3. **`iso9660`**:
   - Usado en la unidad óptica virtual `/dev/sr0`.

4. **`tmpfs`**:
   - Usado para sistemas de archivos temporales en memoria.

---
# ACT3: Explorar dispositivos de entrada

## Objetivo

**Identificar dispositivos como teclados, ratones y cámaras.**

## Intrucciones

### Ejecute `cat /proc/bus/input/devices` para listar los dispositivos de entrada.
```bash
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb2/2-1/2-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0000
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input8
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=b
B: KEY=10000 0 0 0 0
B: ABS=3
```

### Use `evtest` para monitorear eventos de dispositivos de entrada (requiere permisos de superusuario).
```bash
No device specified, trying to scan all of /dev/input/event*
Available devices:
/dev/input/event0:	Power Button
/dev/input/event1:	Sleep Button
/dev/input/event2:	AT Translated Set 2 keyboard
/dev/input/event3:	Video Bus
/dev/input/event4:	ImExPS/2 Generic Explorer Mouse
/dev/input/event5:	VirtualBox USB Tablet
/dev/input/event6:	VirtualBox mouse integration
Select the device event number [0-6]: 
```
Investigue los siguientes dispositivos:
Teclado
```bash
Input device name: "AT Translated Set 2 keyboard"
Supported events:
  Event type 0 (EV_SYN)
  Event type 1 (EV_KEY)
    Event code 1 (KEY_ESC)
    Event code 2 (KEY_1)
    Event code 3 (KEY_2)
    Event code 4 (KEY_3)
    Event code 5 (KEY_4)
    Event code 6 (KEY_5)
    Event code 7 (KEY_6)
    Event code 8 (KEY_7)
    Event code 9 (KEY_8)
    Event code 10 (KEY_9)
    Event code 11 (KEY_0)
    Event code 12 (KEY_MINUS)
    Event code 13 (KEY_EQUAL)
    Event code 14 (KEY_BACKSPACE)
    Event code 15 (KEY_TAB)
    Event code 16 (KEY_Q)
    Event code 17 (KEY_W)
    Event code 18 (KEY_E)
    Event code 19 (KEY_R)
    Event code 20 (KEY_T)
    Event code 21 (KEY_Y)
    Event code 22 (KEY_U)
    Event code 23 (KEY_I)
    Event code 24 (KEY_O)
    Event code 25 (KEY_P)
    Event code 26 (KEY_LEFTBRACE)
    Event code 27 (KEY_RIGHTBRACE)
    Event code 28 (KEY_ENTER)
    Event code 29 (KEY_LEFTCTRL)
    Event code 30 (KEY_A)
    Event code 31 (KEY_S)
    Event code 32 (KEY_D)
    Event code 33 (KEY_F)
    Event code 34 (KEY_G)
    Event code 35 (KEY_H)
    Event code 36 (KEY_J)
    Event code 37 (KEY_K)
    Event code 38 (KEY_L)
    Event code 39 (KEY_SEMICOLON)
    Event code 40 (KEY_APOSTROPHE)
    Event code 41 (KEY_GRAVE)
    Event code 42 (KEY_LEFTSHIFT)
    Event code 43 (KEY_BACKSLASH)
    Event code 44 (KEY_Z)
    Event code 45 (KEY_X)
    Event code 46 (KEY_C)
    Event code 47 (KEY_V)
    Event code 48 (KEY_B)
    Event code 49 (KEY_N)
    Event code 50 (KEY_M)
    Event code 51 (KEY_COMMA)
    Event code 52 (KEY_DOT)
    Event code 53 (KEY_SLASH)
    Event code 54 (KEY_RIGHTSHIFT)
    Event code 55 (KEY_KPASTERISK)
    Event code 56 (KEY_LEFTALT)
    Event code 57 (KEY_SPACE)
    Event code 58 (KEY_CAPSLOCK)
    Event code 59 (KEY_F1)
    Event code 60 (KEY_F2)
    Event code 61 (KEY_F3)
    Event code 62 (KEY_F4)
    Event code 63 (KEY_F5)
    Event code 64 (KEY_F6)
    Event code 65 (KEY_F7)
    Event code 66 (KEY_F8)
    Event code 67 (KEY_F9)
    Event code 68 (KEY_F10)
    Event code 69 (KEY_NUMLOCK)
    Event code 70 (KEY_SCROLLLOCK)
    Event code 71 (KEY_KP7)
    Event code 72 (KEY_KP8)
    Event code 73 (KEY_KP9)
    Event code 74 (KEY_KPMINUS)
    Event code 75 (KEY_KP4)
    Event code 76 (KEY_KP5)
    Event code 77 (KEY_KP6)
    Event code 78 (KEY_KPPLUS)
    Event code 79 (KEY_KP1)
    Event code 80 (KEY_KP2)
    Event code 81 (KEY_KP3)
    Event code 82 (KEY_KP0)
    Event code 83 (KEY_KPDOT)
    Event code 85 (KEY_ZENKAKUHANKAKU)
    Event code 86 (KEY_102ND)
    Event code 87 (KEY_F11)
    Event code 88 (KEY_F12)
    Event code 89 (KEY_RO)
    Event code 90 (KEY_KATAKANA)
    Event code 91 (KEY_HIRAGANA)
    Event code 92 (KEY_HENKAN)
    Event code 93 (KEY_KATAKANAHIRAGANA)
    Event code 94 (KEY_MUHENKAN)
    Event code 95 (KEY_KPJPCOMMA)
    Event code 96 (KEY_KPENTER)
    Event code 97 (KEY_RIGHTCTRL)
    Event code 98 (KEY_KPSLASH)
    Event code 99 (KEY_SYSRQ)
    Event code 100 (KEY_RIGHTALT)
    Event code 102 (KEY_HOME)
    Event code 103 (KEY_UP)
    Event code 104 (KEY_PAGEUP)
    Event code 105 (KEY_LEFT)
    Event code 106 (KEY_RIGHT)
    Event code 107 (KEY_END)
    Event code 108 (KEY_DOWN)
    Event code 109 (KEY_PAGEDOWN)
    Event code 110 (KEY_INSERT)
    Event code 111 (KEY_DELETE)
    Event code 112 (KEY_MACRO)
    Event code 113 (KEY_MUTE)
    Event code 114 (KEY_VOLUMEDOWN)
    Event code 115 (KEY_VOLUMEUP)
    Event code 116 (KEY_POWER)
    Event code 117 (KEY_KPEQUAL)
    Event code 118 (KEY_KPPLUSMINUS)
    Event code 119 (KEY_PAUSE)
    Event code 121 (KEY_KPCOMMA)
    Event code 122 (KEY_HANGUEL)
    Event code 123 (KEY_HANJA)
    Event code 124 (KEY_YEN)
    Event code 125 (KEY_LEFTMETA)
    Event code 126 (KEY_RIGHTMETA)
    Event code 127 (KEY_COMPOSE)
    Event code 128 (KEY_STOP)
    Event code 140 (KEY_CALC)
    Event code 142 (KEY_SLEEP)
    Event code 143 (KEY_WAKEUP)
    Event code 155 (KEY_MAIL)
    Event code 156 (KEY_BOOKMARKS)
    Event code 157 (KEY_COMPUTER)
    Event code 158 (KEY_BACK)
    Event code 159 (KEY_FORWARD)
    Event code 163 (KEY_NEXTSONG)
    Event code 164 (KEY_PLAYPAUSE)
    Event code 165 (KEY_PREVIOUSSONG)
    Event code 166 (KEY_STOPCD)
    Event code 172 (KEY_HOMEPAGE)
    Event code 173 (KEY_REFRESH)
    Event code 183 (KEY_F13)
    Event code 184 (KEY_F14)
    Event code 185 (KEY_F15)
    Event code 217 (KEY_SEARCH)
    Event code 226 (KEY_MEDIA)
  Event type 4 (EV_MSC)
    Event code 4 (MSC_SCAN)
  Event type 17 (EV_LED)
    Event code 0 (LED_NUML) state 0
    Event code 1 (LED_CAPSL) state 0
    Event code 2 (LED_SCROLLL) state 0
Key repeat handling:
  Repeat type 20 (EV_REP)
    Repeat code 0 (REP_DELAY)
      Value    250
    Repeat code 1 (REP_PERIOD)
      Value     33
```
Mouse
 **Esa parte no me dejo copiar y pegarla ya que no podia seleccionar con el mouse**
Controladores USB adicionales
```bash
Input device name: "VirtualBox USB Tablet"
Supported events:
  Event type 0 (EV_SYN)
  Event type 1 (EV_KEY)
    Event code 272 (BTN_LEFT)
    Event code 273 (BTN_RIGHT)
    Event code 274 (BTN_MIDDLE)
    Event code 275 (BTN_SIDE)
    Event code 276 (BTN_EXTRA)
  Event type 2 (EV_REL)
    Event code 6 (REL_HWHEEL)
    Event code 8 (REL_WHEEL)
    Event code 11 (REL_WHEEL_HI_RES)
    Event code 12 (REL_HWHEEL_HI_RES)
  Event type 3 (EV_ABS)
    Event code 0 (ABS_X)
      Value      0
      Min        0
      Max    32767
    Event code 1 (ABS_Y)
      Value      0
      Min        0
      Max    32767
  Event type 4 (EV_MSC)
    Event code 4 (MSC_SCAN)
Properties:
Testing ... (interrupt to exit)
```


## Conteste:

### 1. ¿Qué eventos genera cada dispositivo al interactuar con ellos?

#### **Teclado ("AT Translated Set 2 keyboard"):**
- **Eventos admitidos:**
  - **`EV_SYN`**: Eventos de sincronización para delimitar las acciones del teclado.
  - **`EV_KEY`**: Eventos clave, correspondientes a las teclas presionadas y liberadas.
    - Cada tecla tiene un código único, como `KEY_A` para la tecla "A".
  - **`EV_MSC`**: Eventos misceláneos como `MSC_SCAN`, que identifica el escaneo de hardware.
  - **`EV_LED`**: Manejo de indicadores LED como Num Lock, Caps Lock y Scroll Lock.
- **Eventos comunes al interactuar:**
  - Presionar una tecla genera un evento `EV_KEY` con el código de la tecla (`KEY_X`) y el estado (`1` para presionada).
  - Soltar una tecla genera el mismo evento pero con estado `0`.
  - Cambiar el estado de los LEDs (por ejemplo, activar Caps Lock) genera eventos `EV_LED`.

---

#### **Mouse ("ImExPS/2 Generic Explorer Mouse"):**
- **Eventos admitidos:**
  - **`EV_SYN`**: Eventos de sincronización.
  - **`EV_KEY`**: Botones del mouse (`BTN_LEFT`, `BTN_RIGHT`, etc.).
  - **`EV_REL`**: Movimientos relativos, como desplazamiento del cursor o del scroll.
    - `REL_X` y `REL_Y`: Movimiento horizontal y vertical.
    - `REL_WHEEL`: Movimiento de la rueda del mouse.
- **Eventos comunes al interactuar:**
  - Mover el mouse genera eventos `EV_REL` con valores en `REL_X` y `REL_Y`.
  - Hacer clic en los botones genera eventos `EV_KEY` con los códigos de los botones y sus estados (1 para presionado, 0 para liberado).
  - Usar el scroll genera eventos `REL_WHEEL`.

---

#### **Controladores USB ("VirtualBox USB Tablet"):**
- **Eventos admitidos:**
  - **`EV_SYN`**: Eventos de sincronización.
  - **`EV_KEY`**: Botones del mouse (`BTN_LEFT`, `BTN_RIGHT`, etc.).
  - **`EV_REL`**: Movimientos relativos como el desplazamiento horizontal o vertical.
  - **`EV_ABS`**: Movimientos absolutos, mapeados a una pantalla virtual.
    - `ABS_X` y `ABS_Y`: Coordenadas absolutas del dispositivo.
  - **`EV_MSC`**: Eventos misceláneos como `MSC_SCAN`.
- **Eventos comunes al interactuar:**
  - Arrastrar o mover el puntero genera eventos `EV_ABS` para las coordenadas absolutas.
  - Clics en los botones generan eventos `EV_KEY`.
  - Usar el scroll puede generar eventos `EV_REL`.

---

### 2. ¿Cómo se identifican los dispositivos en `/proc/bus/input/devices`?

Cada dispositivo de entrada se identifica mediante los siguientes campos:  

- **`I` (Información del Bus):**
  - Especifica el bus al que pertenece el dispositivo, como:
    - `0019`: Dispositivos de sistema (por ejemplo, botones de encendido/suspensión).
    - `0011`: Teclado PS/2.
    - `0003`: Dispositivo USB (por ejemplo, el "VirtualBox USB Tablet").
  - Incluye el identificador de fabricante (`Vendor`) y producto (`Product`), junto con la versión del dispositivo.

- **`N` (Nombre):**
  - Nombre descriptivo del dispositivo (por ejemplo, "AT Translated Set 2 keyboard").

- **`P` (Físico):**
  - Representa la ubicación física del dispositivo en el sistema (por ejemplo, `isa0060/serio0/input0` para el teclado).

- **`S` (Sysfs):**
  - Ruta al archivo de sistema asociado al dispositivo (por ejemplo, `/devices/platform/i8042/serio0/input/input2`).

- **`U` (Unique):**
  - Identificador único del dispositivo (puede estar vacío).

- **`H` (Handlers):**
  - Interfaces asociadas para interactuar con el dispositivo, como:
    - `kbd`: Para teclados.
    - `mouseX`: Para dispositivos apuntadores.
    - `eventX`: Para eventos asociados al dispositivo.

- **`B` (Bits de propiedades):**
  - Especifican las capacidades del dispositivo, como:
    - `EV_KEY`: Manejo de teclas.
    - `EV_REL` o `EV_ABS`: Movimientos relativos o absolutos.
---
# ACT4: Examinar dispositivos de salida

## Objetivo

Entender cómo identificar dispositivos de salida como monitores y tarjetas de sonido.

## Intrucciones

### Use `xrandr` para listar las pantallas conectadas y sus resoluciones.

```bash
Screen 0: minimum 16 x 16, current 1280 x 800, maximum 32767 x 32767
Virtual-1 connected primary 1280x800+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1280x800      59.81*+
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1152x720      59.97  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77 
```


### Ejecute `aplay -l` para listar las tarjetas de sonido disponibles.

```bash
vboxuser@uwuntu:~$ sudo aplay -l
[sudo] password for vboxuser: 
**** List of PLAYBACK Hardware Devices ****
card 0: I82801AAICH [Intel 82801AA-ICH], device 0: Intel ICH [Intel 82801AA-ICH]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
```

### Use `lsof /dev/snd/*` para ver qué procesos están utilizando la tarjeta de sonido.
```bash
vboxuser@uwuntu:~$ lsof /dev/snd/*
COMMAND    PID     USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
pipewire  2846 vboxuser   59u   CHR  116,1      0t0  412 /dev/snd/seq
pipewire  2846 vboxuser   60u   CHR  116,1      0t0  412 /dev/snd/seq
wireplumb 2850 vboxuser   35u   CHR  116,5      0t0  704 /dev/snd/controlC0
```

## Conteste:

### 1. **Salidas de video disponibles en el sistema**
Usando `xrandr`, se identificó una salida de video activa:

- **Salida:** `Virtual-1`  
  - **Resolución actual:** `1280x800` (establecida como principal).
  - **Resoluciones disponibles:**  
    ```
    1280x800, 1024x768, 800x600, 640x480, 320x240, 1152x720, 
    960x600, 928x580, 800x500, 768x480, 720x480, 640x400, 
    320x200, 1280x720, 1024x576, 864x486, 720x400, 640x350.
    ```

### 2. **Dispositivos de sonido detectados**
El comando `aplay -l` identificó un dispositivo de sonido:

- **Tarjeta:** `Intel 82801AA-ICH`  
  - **Dispositivo:** `Intel ICH`  
  - **Subdispositivos disponibles:** 1  
  - **Subdispositivo activo:** `subdevice #0`

### 3. **Procesos utilizando la tarjeta de sonido**
El comando `lsof /dev/snd/*` mostró que los siguientes procesos están utilizando el dispositivo de sonido:

1. **pipewire**  
   - **PID:** `2846`  
   - **Usuario:** `vboxuser`  
   - **Dispositivos utilizados:**  
     - `/dev/snd/seq` (dos instancias abiertas).

2. **wireplumber**  
   - **PID:** `2850`  
   - **Usuario:** `vboxuser`  
   - **Dispositivo utilizado:**  
     - `/dev/snd/controlC0`
---
# ACT5: Crear un script de resumen

## Objetivo

Automatizar la recopilación de información de dispositivos de entrada y salida.

## Intrucciones

### Cree un archivo llamado `dispositivos.sh` y agregue el siguiente contenido: ```bash #!/bin/bash echo "Dispositivos de bloque:" lsblk echo "Dispositivos USB:" lsusb echo "Dispositivos PCI:" lspci echo "Dispositivos de entrada:" cat /proc/bus/input/devices echo "Salidas de video:" xrandr echo "Tarjetas de sonido:" aplay -l ```
### Ejecute el script usando `bash dispositivos.sh`.
### Modifique el script para guardar la salida en un archivo llamado `resumendispositivos.txt`.

```bash
vboxuser@uwuntu:~/Desktop$ cat resumendispositivos.txt
Dispositivos de bloque:
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0 269.8M  1 loop /snap/firefox/4793
loop2    7:2    0  74.3M  1 loop /snap/core22/1564
loop3    7:3    0  10.7M  1 loop /snap/firmware-updater/127
loop4    7:4    0 505.1M  1 loop /snap/gnome-42-2204/176
loop5    7:5    0  91.7M  1 loop /snap/gtk-common-themes/1535
loop6    7:6    0  10.5M  1 loop /snap/snap-store/1173
loop7    7:7    0  38.8M  1 loop /snap/snapd/21759
loop8    7:8    0   500K  1 loop /snap/snapd-desktop-integration/178
loop9    7:9    0  44.3M  1 loop /snap/snapd/23258
loop10   7:10   0  73.9M  1 loop /snap/core22/1722
loop11   7:11   0   568K  1 loop /snap/snapd-desktop-integration/253
loop12   7:12   0  11.1M  1 loop /snap/firmware-updater/147
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sr0     11:0    1  56.9M  0 rom  /media/vboxuser/VBox_GAs_7.1.4

Dispositivos USB:
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 002 Device 003: ID 80ee:0021 VirtualBox USB Tablet

Dispositivos PCI:
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)

Dispositivos de entrada:
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0001 Vendor=80ee Product=cafe Version=0000
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input8
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=b
B: KEY=10000 0 0 0 0
B: ABS=3

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb2/2-1/2-1:1.0/0003:80EE:0021.0002/input/input9
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10


Salidas de video:
Screen 0: minimum 16 x 16, current 1280 x 800, maximum 32767 x 32767
Virtual-1 connected primary 1280x800+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1280x800      59.81*+
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1152x720      59.97  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  

Tarjetas de sonido:
**** List of PLAYBACK Hardware Devices ****
card 0: I82801AAICH [Intel 82801AA-ICH], device 0: Intel ICH [Intel 82801AA-ICH]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

```

## Respuesta

### **Ventajas de usar un script para recopilar esta información**

1. **Automatización:**  
   Permite ejecutar múltiples comandos de forma secuencial sin intervención manual. Esto ahorra tiempo y reduce errores humanos.

2. **Consolidación de datos:**  
   Toda la información se recopila en un solo lugar (archivo o terminal), facilitando su análisis posterior.

3. **Reproducibilidad:**  
   Puede ejecutarse en diferentes máquinas o entornos para recopilar la misma información de manera consistente.

4. **Portabilidad:**  
   Es fácil de compartir con otros usuarios o equipos para que obtengan los mismos datos sin necesidad de explicar cada comando.

5. **Documentación:**  
   El script actúa como un registro de los pasos realizados, útil para auditorías o resolución de problemas.

6. **Salida personalizada:**  
   Es posible formatear la salida o redirigirla para integrarla con otras herramientas (logs, informes, etc.).

---

### **Cambios para personalizar el script**

#### 1. **Filtrar la información relevante**
   - Usar opciones específicas de los comandos para mostrar solo datos necesarios.  
     Por ejemplo, limitar `lsblk` a discos montados:  
     ```bash
     lsblk -o NAME,SIZE,MOUNTPOINT
     ```

#### 2. **Incluir fecha y hora en la salida**
   - Agregar un encabezado con la marca de tiempo para registrar cuándo se ejecutó el script:  
     ```bash
     echo "Reporte generado el: $(date)"
     ```

#### 3. **Permitir elegir la salida (pantalla o archivo)**
   - Usar variables o argumentos para decidir si se imprime en pantalla o se guarda en un archivo:  
     ```bash
     OUTPUT_FILE=${1:-"resumendispositivos.txt"}
     ```

#### 4. **Soporte para formatos específicos**
   - Guardar la salida en formatos como JSON o CSV para un análisis más estructurado:  
     ```bash
     echo "{\"Dispositivos de bloque\": $(lsblk -J)}" > $OUTPUT_FILE
     ```

#### 5. **Ampliar el alcance del script**
   - Incluir más información, como:
     - Procesos en ejecución: `ps aux`
     - Uso de memoria: `free -h`
     - Estado de red: `ip a`

#### 6. **Colores o resaltado para la terminal**
   - Mejorar la legibilidad en la terminal resaltando encabezados con colores:  
     ```bash
     echo -e "\033[1;34mDispositivos de bloque:\033[0m"
     ```

#### 7. **Añadir comprobaciones de errores**
   - Verificar si los comandos están instalados antes de ejecutarlos:  
     ```bash
     if ! command -v xrandr &> /dev/null; then
       echo "El comando xrandr no está disponible."
     fi
     ```
---
# ACT6: Reflexión y discusión

## Objetivo

Analizar la importancia del manejo de dispositivos en sistemas Linux.

## Responde:

### **1. ¿Qué comando encontró más útil y por qué?**
El comando más útil depende del contexto y la tarea a realizar. Por ejemplo:  

- **`lsblk`:**  
  Este comando es muy útil para identificar rápidamente los dispositivos de almacenamiento conectados, su jerarquía y los puntos de montaje. Es esencial cuando se trabaja con discos duros, particiones o sistemas de archivos.  

- **`xrandr`:**  
  Indispensable para administrar las configuraciones de salida de video, como resolución y orientación de las pantallas, especialmente en entornos gráficos o cuando se trabaja con múltiples monitores.  

- **`aplay -l`:**  
  Fundamental para diagnosticar problemas relacionados con el sonido. Permite verificar si el sistema reconoce las tarjetas de sonido disponibles.  

---

### **2. ¿Qué tan importante es conocer los dispositivos conectados al sistema?**
Conocer los dispositivos conectados es **crucial** por varias razones:  

1. **Diagnóstico y resolución de problemas:**  
   Identificar rápidamente dispositivos que no funcionan correctamente o que no son detectados por el sistema operativo.  

2. **Optimización del sistema:**  
   Permite gestionar recursos de hardware, asegurando que los dispositivos estén configurados y funcionando de manera óptima.  

3. **Seguridad:**  
   Detectar dispositivos no autorizados que podrían comprometer la seguridad del sistema.  

4. **Compatibilidad:**  
   Garantiza que el hardware conectado sea compatible con el sistema operativo y los controladores instalados.

---

### **3. ¿Cómo podrían estos conocimientos aplicarse en la administración de sistemas?**

#### **En la práctica diaria:**
- **Monitoreo de hardware:**  
  Los administradores de sistemas necesitan verificar regularmente el estado y funcionamiento de dispositivos de almacenamiento, monitores, dispositivos USB, tarjetas de sonido, entre otros.  

- **Resolución de incidentes:**  
  En caso de problemas (como fallas en pantallas o almacenamiento), estos comandos permiten identificar y aislar rápidamente el problema.  

- **Configuración de sistemas:**  
  Al instalar nuevos sistemas operativos o configurar hardware adicional, conocer los dispositivos disponibles ayuda a optimizar el proceso de instalación y configuración.

#### **En proyectos más avanzados:**
- **Automatización:**  
  Scripts como el que se creó permiten recopilar información sobre hardware de manera automática, ideal para administrar múltiples servidores o estaciones de trabajo.  

- **Escalabilidad:**  
  En entornos empresariales, es esencial administrar hardware en infraestructura masiva, como redes de servidores, donde estos conocimientos facilitan la gestión centralizada.
---
