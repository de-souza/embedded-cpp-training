#!/usr/bin/env bash
# Use bash pipes for various operations.
read -s -p "Number of entries in the current directory : "
ls -1A | wc -l

read -s -p "Number of directories in the current directory : "
ls -lA | grep ^d | wc -l

read -s -p "Files in /usr/bin sorted by size : "; echo
ls -lAhS /usr/bin | tail -n +2 | awk '{print $9 " (" $5 "B)"}'

read -s -p "Number of users on the system : "
cut -d: -f1 /etc/passwd | wc -l

read -s -p "Names of the users : "; echo
cut -d: -f1 /etc/passwd

read -s -p "Users who do not use bash : "; echo
grep -v "/bin/bash" /etc/passwd | cut -d: -f1
