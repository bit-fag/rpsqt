rpsqt
=====

Remote rock-paper-scissors written with Qt

This program should be run be two players comminicating via chat.

Steps:
1. Players choose rock, paper or scissors.
   This is encoded as 1 letter (r, p or s).
2. Salt is generated by the program. Minimal length of salt is 10.
3. Clear text is salt + "-" + choice.
4. Hash is calculated as follows: sha1(cleartext).
5. Players send hashes to each other.
6. Players send cleartexts to each other.
7. Players make sure opponent's hash matches opponent's cleartext.
8. Now both know who wons.


Удаленная версия игры камень-ножницы-бумага, написанная на Qt

Эту программу запускают два игрка, общающиеся через чат.
Шаги:
1. Игроки выбирают камень, ножницы или бумагу.
   Это кодируется одним символом (r (камень), p (бумага) или s (ножницы)).
2. Программа создает соль. Минимальная длина соли: 10.
3. Открытый текст это соль + "-" + выбор.
4. Хеш-сумма вычисляется так: sha1(открытый текст).
5. Игроки посылают хеш-суммы друг другу.
6. Игроки посылают открытые тексты друг другу.
7. Игроки убеждаются, что хеш-сумма оппонента соответствует его открытому тексту.
8. Теперь оба знают, кто победил.
