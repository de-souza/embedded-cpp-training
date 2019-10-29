#!/usr/bin/env bash
# Print the IP adresses that are reachable on the same network
timeout=5

[[ $(ip --brief addr) =~ UP\ *([^\/]*) ]] && ip=${BASH_REMATCH[1]} || exit 1

echo "This computer's IP address: $ip"
echo "Other IPs on the network:"

for i in $(seq -f "${ip%\.*}.%g" 1 254); do
    (ping "$i" -c 1 -w "$timeout" >/dev/null && echo "$i" &)
done
sleep "$timeout"
