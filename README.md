# Railway_station

Чтение исходных данных и запросов происходит их файлов tests/input_data_1.txt и tests/queries_1.txt . В файле expected_output_1.txt приведён ожидаемый результат.

Для визуализации структуры splay-дерева использована библиотека FreeGLUT (https://github.com/dcnieho/FreeGLUT).

После клонирования проекта придётся подтянуть зависимости, сделать это можно с помощью двух команд:
  - git submodule init
  - git submodule update

Для визуализации балансировки дерева разработаны две серии тестов - structure_1_0.txt : structure_1_3.txt и structure_2_0.txt : structure_2_3.txt в директории tests. Формат тестов аналогичен формату файла для чтения исходных данных. Первый тест в обоих сериях представляет пример дерева с линейной глубиной. Последующие тесты отличаются от предыдущего добавлением уже существующей станции - в этом случае insert практически аналогичен обычному поиску.

Первая серия тестов:
  - structure_1_0.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_1_0.png)
  - structure_1_1.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_1_1.png)
  - structure_1_2.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_1_2.png)
  - structure_1_3.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_1_3.png)

Вторая серия тестов:
  - structure_2_0.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_2_0.png)
  - structure_2_1.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_2_1.png)
  - structure_2_2.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_2_2.png)
  - structure_2_3.txt <br />
![image](https://github.com/Vlad-kv/Railway_station/blob/main/structure_examples/s_2_3.png)
