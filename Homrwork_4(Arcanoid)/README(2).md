Ссылка награфическую  библиотку [Вот](https://www.sfml-dev.org/download/)

В свойствах проекта необходимо выполнить:

1)Свойства конфигурации - C/C++ - Общиe - Дополнительные каталоги включаемых файлов, надо указать путь к папке include библиотеке (C:\SFML-3.1.0\include) 

2) Компоновщик - Общие - Дополнительные каталоги библиотек, указываем путь к папке lib (C:\SFML-3.1.0\lib)

3) Компоновщик - Ввод - Дополнительные зависимости, указать следующие библиотеки

sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
sfml-network-d.lib

И послнедее действие, скопировать из папки bin библиотеки следующие файлы прямо в папку проекта

sfml-graphics-d-3.dll
sfml-window-d-3.dll
sfml-system-d-3.dll
sfml-audio-d-3.dll
sfml-network-d-3.dll
