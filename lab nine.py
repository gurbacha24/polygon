import numpy as np

#входной массив
arr = np.array([1, 2, 5, 6, 7, 10])

#вычисление разницы междц соседними элементами
diff = np.diff(arr)

#создание булевого массива. будет выдавать True если разница > 0 (числа возрастают), иначе False
increasing = diff > 0

#добавление фиктивное False в конец, чтобы правильно учитывать последний элемент последовательности во входном массиве
extended_increasing = np.append(increasing, False)

#нахождение границ последовательностей (False указывает конец последовательности)
boundaries = np.where(~extended_increasing)[0]

#вычисление длин последовательностей (как разницы индексов границ)
lengths = np.diff(np.append(-1, boundaries))

#нахождение максимальной длины
max_length = lengths.max()

#вывод результата
print(max_length)
