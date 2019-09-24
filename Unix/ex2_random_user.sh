#!/usr/bin/env bash
# Display the name of a random user.
cut -d: -f1 < /etc/passwd | sort -R | head -n 1
