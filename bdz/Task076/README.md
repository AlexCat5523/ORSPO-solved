# Task076 — Выставление n-го бита в ноль 3️⃣

## Описание задания

Реализуйте функцию `unsetbit()`, выставляющий значение n-го бита в ноль

## Решение
// 1U << position creates the mask
// ~ inverted mask turns target bit to 0, all others to 1
// & forces the target bit to 0, preserves all others
Решение в `bin_operations.c`