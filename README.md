# Cтек на линейном односвязном списке

## Содержание

1. [Введение](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Введение)
2. [Постановка задачи](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Постановка-задачи)(
3. [Руководство пользователя](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Руководство-пользователя)
   1. [Запуск приложения](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Запуск-приложения)
4. [Руководство программиста](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Руководство-программиста)
   1. [Используемые инструменты](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Используемые-инструменты)
   1. [Общая структура проекта](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Общая-структура-проекта)
   1. [Описание структуры проекта](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Описание-структуры-проекта)
   1. [Описание структур данных](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Описание-структур-данных)
   1. [Описание алгоритмов](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Описание-алгоритмов)
5. [Заключение](https://github.com/Yaroslav-Lahtachev/mp2-lab3-lists-stack#Заключение)

## Введение

**Стек** - абстрактный тип данных, представляющий собой список элементов,
организованных по принципу LIFO (last in — first out,«последним пришёл — первым вышел»).
В нашем случае стек реализован на СД список.

Программный вид стека используется для обхода структур данных, например, дерево
или граф. При использовании рекурсивных функций также будет применяться стек,
но аппаратный его вид. Кроме этих назначений, стек используется для организации
стековой машины, реализующей вычисления в обратной инверсной записи.

**Список** - структура данных, состоящая из узлов, каждый из которых содержит
как собственно данные, так и ссылку  на следующий узел списка. Принципиальным
преимуществом перед массивом является структурная гибкость: порядок элементов
связного списка может не совпадать с порядком расположения элементов данных
в памяти компьютера, а порядок обхода списка всегда явно задаётся его внутренними
связями.

**Обратная польская нотация** - форма записи математических выражений, в которой
операнды расположены перед знаками операций. Обратная польская запись имеет ряд
преимуществ перед инфиксной записью при выражении алгебраических формул. Во-первых,
любая формула может быть выражена без скобок. Во-вторых, она удобна для вычисления
формул в машинах со стеками.

## Постановка задачи

1. Разработать статическую библиотеку, реализующую динамическую структуру данных список,
   и основанную на ней динамическую структуру стек. 
1. Реализовать на стеках алгоритм преобразования записей из инфиксной в постфиксную. 
   Создать приложение, демонстрирующее работу алгоритма, с символьными арифметическими
   выражениями и значениями каждого параметра, а результат обратная польская запись
   и численный результат.
1. Реализовать пример использования стека и списка.
1. В процессе выполнения лабораторной работы требуется использовать систему 
   контроля версий Git и фрэймворк для разработки автоматических тестов Google Test.

## Руководство пользователя

### Запуск приложения

Программа создана что бы считывать символьное выражение и переводить его в постфиксную
форму с помощью методов основанных на стеке. Далее для этого выражения считываются значения
переменных. Далее вычисляется значение заданного выражения.

Для запуска программы нужно открыть файл sample_main.exe. Далее необходимо следовать инструкциям.

Пример:

1. Введите инфиксное выражение и нажмите клавишу Enter.

    ![ввод выражения](/img/vvod.PNG)

1. Введите значение переменной нажмите Enter. Повторите этот пункт до ввода всех переменных.

![ввод переменных](/img/vvod2.PNG)

1. Наслаждайтесь результатом.
1. Нажмите любую клавишу для завершения работы приложения.

## Руководство программиста

### Используемые инструменты

В ходе лабораторной работы использовались следующие инструменты:

- Система контроля версий Git.
- Фреймворк для написания автоматических тестов Google Test.
- Среда разработки Microsoft Visual Studio 2010.

### Общая структура проекта

Структура проекта:

- `gtest` — библиотека Google Test.
- `img` — директория с изображениями, используемых в отчете к лабораторной работе.
- `include` — директория для размещения заголовочных файлов.
- `samples` — директория для размещения тестового приложения.
- `sln` — директория с файлами решений и проектов для VS 2010.
- `src` — директория для размещения исходных кодов (cpp-файлы).
- `tests` — директория с модульными тестами и основным тестовым приложением, инициализирующим запуск тестов.
- `README.md` — информация о проекте, которую вы сейчас читаете.
- `img` — директория с изображениями.
- Служебные файлы
  - .gitignore — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.

## Описание структуры проекта

Приложение состоит из 6 проектов:

- `postfix_lib` - статическая библиотека, содержащая реализацию шаблонных классов **`NODE`**, **`List`** и **`Stack`**
    - **`NODE`** - описывает "узел" списка. В узле хранится значение - *`key`* и указатель на следующий узел - *`pNext`*.
    - **`List`** - класс "список", агрегирующий в себе класс **`NODE`**.
    - **`Stack`** - класс "стек", агрегирующий в себе класс **`List`**.

- `sample_list` - приложение с демонстрацией класса **`List`**.
- `sample_stack` -  приложение с демонстрацией работы класса **`Stack`**.

- `sample_postfix` - приложение с двумя функциями и демонстрацией этих функций.

    - `convert` - функция конвертации инфиксной записи в постфиксную. Основана на классе **`Stack`**. Входными данными являются строки.
    - `result` - функция считывания значений переменных и дальнейшего подсчета значения выражения. Входными данными являются строки обработанные функцией `convert`.

- `gtest` - фреймворк Google Test.
- `tests` - приложение, использующее библиотеку Google Test. С помощью этого приложения осуществляется проверка классов **`List`** и **`Stack`**.
    
## Описание структур данных ##
###  `List` ###

Класс *`List`* реализован на шаблонах для использования с разными типами входных данных.

В структуре данных `List` реализованы методы :

- `List()` - конструктор.
- `~List()` - деструктор.
- `List(const List &list)` - конструктор копирования.
- `void print()` - выводит на экран значения элементов списка.
- `NODE<ValType>* find(ValType key)` - метод поиска элемента по ключу. Возвращает указатель на него.
- `NODE<ValType>* findP(ValType key, NODE<ValType> *&elem)` - метод поиска элемента, стоящего перед элементом с заданным ключом.
- `void erase(ValType key)` - метод удаления элемента (с определенным ключом) из списка.
- `void insertF(ValType key)` - метод вставки нового элемента в начало списка.
- `void insertL(ValType key)` - метод вставки нового элемента в конец списка.
- `void insertB(ValType key, NODE<ValType> *elem)` - метод вставки нового элемента, перед указанным элементом.
- `void insertA(ValType key, NODE<ValType> *elem)` - метод вставки нового элемента, после указанного элемента.
- `NODE<ValType>* getFirst()` — метод, возвращающий указатель на первый элемент списка.

### `Stack`

Класс *`Stack`* реализован на шаблонах для использования с разными типами входных данных.

- `Stack()` - конструктор.
- `~Stack()` - деструктор.
- `Stack(const Stack<ValType> &s)` - конструктор копирования.
- `int isEmpty() const` - метод проверяет стек на пустоту.
- `int isFull() const` - метод проверяет полноту стека.
- `void push(ValType key)` - метод добавляет новый элемент в начало стека.
- `ValType pop()` - метод возвращает значение элемента и удаляет его из стека.
- `ValType top()` - метод выводящий на экран первый элемент в стеке.

## Описание алгоритмов ##

Алгоритм перевода в постфиксную запись `convert`

- Создаются 2 стека: под хранение постфиксной записи - `row` и мат. знаков - `sign`.

- Изначально каждому заданному математическому знаку присваивается приоритет. Знаку умножения и деления - 3. Знаку сложения и вычитанию - 2. Скобкам - 1. Знаку равно - 0. 

- Далее из входной строки (`Row`) копируется по одному элементу. Далее происходит проверка скопированного элемента.
    - Если код скопированного элемента принадлежит кодам букв, то этот элемент добавляется в стек `row`
    
    - Если встретился знак(кроме `(` `)`) для которого выставлен приоритет, и его приоритет больше приоритетов знаков уже лежащих в стеке `sign` или `sign` пуст, то этот элемент добавляется в стек. Иначе, если значение приоритета меньше или равно приоритетов из стека, то все знаки , приоритет которых больше нового перекладываются в стек `row`. На их место добавляется новый знак.
    
    - Если встретился знак закрывающейся скобки, тогда все знаки из `sign` перекладываются в `row`, до встречи с открывающейся скобкой. После этого скобка удаляется из стека. 
    
- Если элементы из `Row` закончились, то все элементы из `sign` перекладываются в `row`.

----------

Алгоритм подсчета `result`

- Создается стек для хранения значений переменных `row`.

- Далее из входной строки берется по одному элементу.
    -  Если это переменная, то для нее считывается значение, и оно перебрасывается в стек `row`. 
    
    - Если это операция, то из стека `row` берутся два элемента, и над ними производится указанная  арифметическая операция. Результат возвращается в `row`. 

## Заключение ##

В ходе работы была создана программа, в которой было реализовано 2 класса и структура. Список и стек реализованы на шаблонах для корректной работы алгоритма преобразования и вычисления. Были созданы примеры использования всех алгоритмов для стека и списка. Так же было реализовано 48 тестов, проверяющие всевозможные варианты работы методов. Также был реализован алгоритм преобразования из инфиксной записи в обратную польскую нотацию (постфиксную) и вычисление результата данного выражения. 
