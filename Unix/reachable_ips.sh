#!/usr/bin/env bash
# Print the IP adresses that are reachable on the same network
filename="iplist.txt"
timeout=3

[[ $(ip --brief addr) =~ UP\ *([^\/]*) ]] && ip=${BASH_REMATCH[1]} || exit 1

echo "This computer's IP address: $ip"

rm -f "$filename"
for i in $(seq -f "${ip%\.*}.%g" 1 254); do
    (ping "$i" -c 1 -w "$timeout" >/dev/null && echo "$i" >> "$filename" &)
done
sleep "$timeout"

echo "IPs reachable on the network:"
cat "$filename"
