#!/usr/bin/expect

# Ruta del archivo .c
set archivo [lindex $argv 0]

# Iniciar Vim con el archivo
spawn vim "$archivo"

# Esperar a que Vim se inicie
expect "Press ENTER or type command to continue"

# Enviar el comando :Stdheader y presionar Enter
send ":Stdheader\r"

# Esperar a que el comando se complete (ajusta el tiempo según sea necesario)
expect_after {timeout {sleep 1}}

# Guardar y salir
send ":wq\r"

# Esperar a que Vim se cierre
expect eof
