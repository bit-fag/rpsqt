rpsqt
=====

Remote rock-paper-scissors written with Qt

This program should be run be two players comminicating via chat.

See https://github.com/bit-fag/rpsqt/releases for Windows EXE file.

Steps:

 * Players choose rock, paper or scissors.
   This is encoded as 1 letter (r, p or s).
 * Salt is generated by the program. Minimal length of salt is 10.
 * Clear text is salt + "-" + choice.
 * Hash is calculated as follows: sha1(cleartext).
 * Players send hashes to each other.
 * Players send cleartexts to each other.
 * Players make sure opponent's hash matches opponent's cleartext.
 * Now both know who wons.


Удаленная версия игры камень-ножницы-бумага, написанная на Qt

Эту программу запускают два игрока, общающиеся через чат.

На странице https://github.com/bit-fag/rpsqt/releases вы найдёте EXE файл
для Windows.

Шаги:

 * Игроки выбирают камень, ножницы или бумагу.
   Это кодируется одним символом (r (камень), p (бумага) или s (ножницы)).
 * Программа создает соль. Минимальная длина соли: 10.
 * Открытый текст это соль + "-" + выбор.
 * Хеш-сумма вычисляется так: sha1(открытый текст).
 * Игроки посылают хеш-суммы друг другу.
 * Игроки посылают открытые тексты друг другу.
 * Игроки убеждаются, что хеш-сумма оппонента соответствует его открытому тексту.
 * Теперь оба знают, кто победил.

![Step 1](http://i.imgur.com/2cVMWX0.png "Start two instances of the game")

![Step 2](http://i.imgur.com/5wYnI6z.png "Select Rock in first instance")

![Step 3](http://i.imgur.com/HBpwvSB.png "Select Scissors in second instance")

![Step 4](http://i.imgur.com/OmdsaL8.png "Paste hash from first instance to second")

![Step 5](http://i.imgur.com/2wnOqUu.png "Paste hash from second instance to first")

![Step 6](http://i.imgur.com/WEHWzd3.png "Paste cleartexr from first instance to second. Get result")

![Step 7](http://i.imgur.com/gH5owZZ.png "Paste cleartexr from second instance to first. Get result")
