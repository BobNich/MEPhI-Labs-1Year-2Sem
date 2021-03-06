# Лабораторная работа № 5 «Работа с графами»
## Введение
### Задачи
В процессе выполнения лабораторной работы необходимо cпроектировать и разработать программу, осуществующую интерактивную работу пользователя с графом.
### Дополнительные задачи
1. Реализовать графический вывод графа при помощи локальной внешней утилиты или библиотеки (например, graphviz). При этом, отображение графа в графическом интерфейсе пользователя или генерация файла с изображением должно происходить автоматически, без выполнения действий вручную со стороны пользователя.
2. При помощи реализованной библиотеки, осуществляющей работу с графом, написать программу для поиска кратчайшего (по дистанции или по количеству транспортных узлов) пути между двумя точками на карте любого города, области, страны и т. д. Необходимые данные найти в интернете, например: https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm. При выполнении данного задания допускается, при необходимости, не соблюдать свойство ацикличности графа.
### Основные операции
В программе необходимо предусмотреть возможность проведения следующих операций над графом, особенности реализации которых определяются индивидуальным заданием:
* Поиск пути между двумя вершинами графа;
* Поиск кратчайшего пути между двумя вершинами графа;
* Случайное задание.

Кроме того, должны быть реализованы следующие общие операции над графом:
* Добавление новой вершины;
* Добавление нового ребра между двумя заданными вершинами;
* Удаление заданной вершины;
* Удаление заданного ребра;
* Вывод графа в виде матрицы или списков смежности.

## Примечания
* Каждая вершина графа должна иметь уникальный строковый идентификатор.
* Логически законченные части алгоритма решения задачи должны быть оформлены в виде отдельных функций с параметрами. Использование глобальных переменных не допускается.
* Функции для работы с графом должны быть организованы в виде отдельной библиотеки, которая используется основной программой.
* Функции для работы с графом не должны быть диалоговыми, т. е. они должны принимать все необходимые данные в качестве параметров и возвращать результат работы в виде соответствующих структур данных и кодов ошибок (исключение: функции вывода графа).
* Диалоговые функции должны использовать описанные выше функции, т. е. должен быть реализован принцип Model-View-Controller (MVC).
* Программа должна осуществлять проверку корректности вводимых данных и, в случае ошибок, выдавать соответствующие сообщения, после чего продолжать работу.
* В случае возникновения ошибочных ситуаций при выполнении операций над графом программа должна выводить соответствующие сообщения, после чего продолжать работу.
* Программа должна корректным образом работать с памятью, для проверки необходимо использовать соответствующие программные средства, например: valgrind, санитайзеры, встроенные в IDE средства и т.д.

----
# Вариант №269
## Основные свойства графа
Неориентированный взвешенный граф.

Вершины графа задаются координатами на плоскости.

Веса рёбер графа определяются расстоянием между соответствующими вершинами.
## Способ представления графа
В виде списков смежности.
## Операции, поддерживаемые графом
* Поиск пути между двумя заданными вершинами.

Поиск некоторой заданной вершины из другой заданной вершины методом поиска в глубину (если пути между вершинами нет, необходимо вернуть ошибку).
* Поиск кратчайшего пути между двумя заданными вершинами.

Поиск кратчайшего пути между двумя заданными вершинами графа, использующий алгоритм Беллмана-Форда.
* Особая операция

Для неориентированного графa — поиск минимального остовного дерева; результатом выполнения операции должен являться новый граф.

Для ориентированного графа — поиск кратчайшего пути ко всем вершинам из некоторой заданной вершины; результатом выполнения операции должно являться дерево (представленное новым ациклическим графом), корнем которого является указанная вершина.

----

# Примеры:

![](https://github.com/BobNich/Labs-MEPHI-1Year-2Sem/blob/main/lab5/examples/Graph.png)
