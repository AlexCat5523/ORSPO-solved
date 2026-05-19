# Task016 — Автотесты 🔍

## Что такое Unity?

`Unity` — это легковесный фреймворк для модульного тестирования на языке `C`. Он предоставляет простые макросы для написания и запуска тестов, проверки утверждений `(assertions)` и формирования отчета о результатах.

## Установка Unity

```bash
# Клонирование репозитория Unity
git clone https://github.com/ThrowTheSwitch/Unity.git
```

## Основные макросы Unity

|Макрос  | Назначение |
| :--- | :--- | 
| `TEST_ASSERT_EQUAL_INT(expected, actual)` | Проверка равенства целых чисел |
| `TEST_ASSERT_EQUAL_STRING(expected, actual)` | Проверка равенства строк |
| `TEST_ASSERT_TRUE(condition)` | 	Проверка, что условие истинно |
| `TEST_ASSERT_FALSE(condition)` | Проверка, что условие ложно  |
| `TEST_ASSERT_NULL(pointer)` | Проверка, что указатель NULL |
| `TEST_ASSERT_NOT_NULL(pointer)` | Проверка, что указатель не NULL |
| `TEST_FAIL())` | Принудительное проваливание теста |

---

## Задание 

* Скачайте Unity и разместите его в папке проекта.

* Запустите сборку и тестирование:
    ```bash
    make
    ```

* Изучите вывод тестов. Какие тесты провалились?

* Исправьте ошибки в `calc.c` так, чтобы все тесты проходили успешно.

* Запустите `make` снова и убедитесь, что все тесты "зеленые".

* Добавьте новый тест для проверки деления на ноль (как должна вести себя функция?).


## Решение
1) Скачиваем
2) Запускаем, в консоли появится:
```bash
    gcc -Wall -Wextra -g -o main.out src/calc.c src/main.c
    gcc -Wall -Wextra -g -o test.out tests/test_calc.c ../Unity/src/unity.c src/calc.c
    ./test.out
    tests/test_calc.c:6:test_sum_array_correct:FAIL: Expected 6 Was 5
    tests/test_calc.c:11:test_divide_logic_error:FAIL: Expected 5 Was 20

    -----------------------
    2 Tests 2 Failures 0 Ignored
    FAIL
    make: *** [Makefile:19: test] Error 2
```

3) Провалились тесты на суммирование и умножение (4 и 5 строчки из консоли соответственно)
4) Исправленный код (полностью скопируйте и вставьте или исправьте сами):
```c
#include "calc.h"
#include <stdio.h>

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {   // <--- тут была ошибка, что i начиналась с 1, т.е. первый элемент массива не учитывался
        sum += arr[i];
    }
    return sum;
}

int divide(int a, int b) {
    return a / b;                   // <--- тут был знак умножения, хотя функция выполняет деление
}
```

5) Запускаем `make`, в 4 и 5 строчках в конце должно быть написать **PASS** после названий тестов
6) Добавляем в файл `tests/test_calc.c`:
```c
void test_division_by_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, divide(10, 0));
}
```
а также в **ТОМ ЖЕ ФАЙЛЕ** в функцию `main` строчку: `RUN_TEST(test_division_by_zero)`.

Теперь в файле `src/calc.c` изменяем функцию `divide`:
```c
int divide(int a, int b) {
    if (b == 0) {
        return 0;       // <--- добавляем проверку, что если b == 0, возвращаем 0.
    }
    return a / b;                   // <--- тут был знак умножения, хотя функция выполняет деление
}
```