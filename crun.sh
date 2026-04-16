#!/usr/bin/env bash
# Сборка и запуск: ./crun.sh lab02   или   ./crun.sh lab02.cpp
set -euo pipefail
src="${1:?Укажите файл, например: ./crun.sh lab02.cpp}"
[[ "$src" == *.cpp ]] || src="${src}.cpp"
base=$(basename "$src" .cpp)
out="/tmp/${base}_run"
g++ -std=c++17 -Wall -Wextra -O2 "$src" -o "$out" -lm
exec "$out"
