#!/usr/bin/env bash
# Edit a file using sed.
file="$(mktemp)"
trap "rm $file" EXIT

cat > "$file" << EOF
Prénom = ...
Nom = ...
EOF

sed '1s/\.\.\./Léo/' "$file" | sed '2s/\.\.\./De Souza/'
