#!/bin/bash

find . \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) | while read archivo; do
    # Obtener la primera línea del archivo
    primera_linea=$(head -n 1 "$archivo")

    # Comprobar si la primera línea comienza con '/*' o '# ***'
    if ! echo "$primera_linea" | grep -q -E '^(\/\*|# \*\*\*)'; then
        # Si no comienza con esos patrones, ejecutar el script de expect
        ./vim_stdheader_expect.sh "$archivo"
    fi
done
