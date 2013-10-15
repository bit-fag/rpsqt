#!/bin/bash
salt=`head /dev/urandom|sha1sum|awk '{print $1;}'`
echo -n 'Enter r, p or s (rock, paper or scissors): '
read choice
if [[ $choice != 'r' && $choice != 'p' && $choice != 's' ]]; then
    echo "Invalid choice!"
    exit
fi
text="$salt-$choice"
echo -n 'Send this first: '
echo -n $text | sha1sum | awk '{print $1;}'
echo 'Now enter what your opponent sent: '
read o_hash
echo 'Send this:' $text
echo 'Now enter what your opponent sent: '
read o_text
o_hash2=`echo -n $o_text|sha1sum|awk '{print $1;}'`
if [[ $o_hash2 == $o_hash ]]; then
    echo 'Opponent hash OK'
    o_choice=`echo -n $o_text|sed 's/-/ /'|awk '{print $2;}'`
    if [[ $o_choice != 'r' && $o_choice != 'p' && $o_choice != 's' ]]; then
        echo "Invalid choice of your opponent! Although he doesn't cheat"
    fi
    if [[ $choice == $o_choice ]]; then
        echo 'Draw'
        exit
    fi
    if [[ $choice == 'r' && $o_choice == 'p' ]]; then
        echo "Opponent won!"
        exit
    fi
    if [[ $choice == 'p' && $o_choice == 's' ]]; then
        echo "Opponent won!"
        exit
    fi
    if [[ $choice == 's' && $o_choice == 'r' ]]; then
        echo "Opponent won!"
        exit
    fi
    echo "You won!"
else
    echo 'Opponent hash FAIL!!! It looks like he cheats'
fi
