#!/bin/sh

cat $1 | grep -i "Nicolas\tBauer" | rev | cut -f2 | rev | grep '-'
