#!/bin/bash

make

#read -p "Enter name of map" map

#map_path="./maps/$map"

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3d maps/test_m.cub

