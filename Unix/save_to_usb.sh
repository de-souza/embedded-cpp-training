#!/usr/bin/env bash
# Backup a folder (by default ~) to an external device.
# The device's UUID can be found with "lsblk -f".
uuid="0E7A-4CAE"
folder=~
device="$(realpath /dev/disk/by-uuid/$uuid)"

if mount | grep -q "$device"; then
    mountpoint="$(lsblk --noheadings --output MOUNTPOINT /dev/disk/by-uuid/$uuid)"
else
    echo "The device $uuid is not mounted."; exit
fi

echo "Saving $folder to $uuid…"
rsync -a --delete --exclude='.*/' --info=progress2 "$folder" "$mountpoint"

read -s -n 1 -p "Eject device? (Y/n): " answer
echo
if [ "$answer" != "n" ]; then
    umount "$device" && udisksctl power-off -b "$device" && echo "Ejected $uuid."
fi
