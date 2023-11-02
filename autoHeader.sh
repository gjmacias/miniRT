#!/bin/bash

find . \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) | while read archivo; do
    # Comprobar si el archivo comienza con '/*'
    if ! grep -q '^/\*' "$archivo"; then
        # Si no comienza con '/*', ejecutar el script de expect
        ./vim_stdheader_expect.sh "$archivo"
    fi
done
