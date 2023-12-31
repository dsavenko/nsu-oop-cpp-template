
# Заготовка репозитория для лабораторных по курсу "ООП (С++)" ФИТ НГУ

## Краткая справка, как работать с Git и GitHub

Некоторые шаги ниже вы, возможно, уже делали раньше.

1. Заводим аккаунт на GitHub.
2. Устанавливаем Git на вашем компьютере (для Windows качаем [отсюда](https://git-scm.com/download/win)).
3. Если у вас Windows, открываем папку, где хотим хранить задачи и выбираем в контекстном меню `Open Git Bash here`.
4. Создаем SSH-ключ и привязываем его к аккаунту на GitHub, следуя инструкциям [отсюда](https://github.com/settings/keys).
5. Нажимаем `Use this template -> Create a new repository` на этой странице, открывается окно создания нового репозитория на основе данного. Вводим имя, **выбираем Private**, жмем `Create repository`.
6. На странице вашего репозитория идём в `Settings -> Collaborators -> Add people`, вводим мой аккаунт (`dsavenko`), нажимаем `Add ...`.
6. В окне Git Bash выполняем команду `git clone <git-ссылка>`. Git-ссылку можно получить на странице вашего репозитория (нажав кнопку `Code`), она имеет вид `git@github.com:dsavenko/nsu-oop-cpp-template.git`. 
7. В папке с названием вашего репозитория теперь лежит его локальная копия, с которой вы можете работать.

Как работать с локальной копией:
1. Создаёте, удаляете, меняете файлы и папки, как вам нужно.
2. Чтобы залить изменения на GitHub, открываете `Git Bash` в папке вашего репозитория и выполняете следующие команды:
    ```
    $ git add .
    $ git commit -m "Краткое описание изменений"
    $ git push
    ```
3. Проверяем, что всё залито успешно, командой `git status`: 
    ```
    $ git status
    On branch master
    Your branch is up to date with 'origin/master'.

    nothing to commit, working tree clean
    ```
    Если вывела такое, то всё ОК.
4. Коммитить и пушить рекомендуется **часто**, как минимум один раз за каждый день, когда вы работали.

**Рекомендуется самостоятельно изучить работу с Git более подробно.**

## Заготовка проекта CMake + GoogleTest

В папке [lab1](./lab1) лежит пример того, как можно настроить свой проект с использованием кроссплатформенной системы сборки [CMake](https://cmake.org/download/) и библиотеки тестирования [GoogleTest](https://github.com/google/googletest).

Содержимое:

1. `main.cpp` - реализация функции `main`. Не рекомендуется добавлять в этот файл что-то еще.
2. `task1/2.h`, `task1/2.cpp` - файлы реализации задачи.
3. `task1/2_test.cpp` - тесты (с использованием GoogleTest).
4. `CMakeLists.txt` - правила сборки для CMake.

Подготовка к сборке:

1. Убедитесь, что в системе установлен компилятор C++. Для Windows проще всего установить Visual Studio (компилятор идёт вместе с ней), но есть и другие варианты (например, mingw/cygwin + gcc). Для других систем (Linux, Mac OS) установите gcc.
2. Установите [CMake](https://cmake.org/download/).

Как собрать проект из командной строки:

1. Cоздайте папку `build` внутри [lab1](./lab1). Перейдите в неё. Все дальнейшие действия нужно выполнять из этой папки.
2. Запустите `cmake ..`. Результатом этой операции будет создание билд-скриптов в текущей папке. Это нужно сделать один раз.
3. Запустите сборку при помощи команды `cmake --build .` (под Linux/MacOS/cygwin/mingw также сработает просто `make`). Это нужно делать каждый раз для пересборки проекта.
4. Проверьте, что собрались и запускаются исполняемые файлы `nsuoop-cpp-template(.exe)` и `test(.exe)`. Под Windows они могут лежать в папке `Debug`.

Можно также воспользоваться CMake GUI.

> Visual Studio поддерживает CMake, поэтому можно просто открыть папку с проектом в ней. В этом случае по умолчанию папкой для сборки будет `out/build`, а не `build`.

Как вносить изменения:

1. При внесении изменений в существующие h/cpp-файлы для пересборки нужно снова сделать `cmake --build .` (или `make`). Если пользуетесь IDE, она будет делать это сама.
2. При создании новых (или удалении старых) cpp-файлов необходимо соответствующим образом изменить `CMakeLists.txt` (см. комментарии в нём). После этого снова сделать `cmake --build .` (или `make`). Это не относится к h-файлам, так как они не порождают новые единицы трансляции. h-файлы можно создавать и удалять, не меняя `CMakeLists.txt`.

> Даже если пользуетесь Visual Studio или другой IDE, `CMakeLists.txt` все равно должен находиться в актуальном состоянии, чтобы проект можно было собрать на любой системе без помощи IDE. 
