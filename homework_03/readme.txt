
Functionality of program:
    This is a simple game in which you are asked to guess a number.
    After the attempt, you will see the total score


CLI arguments for start program:
    1) -max [INTEGER]       set max value of number for guess. Don't use with arg -level.
                                by default set 100.
    2) -table               shows only the score table and exits the program
    3) -level [INTEGER]     can be follows values: 1, 2, 3 (by default set 0) 
                                0 - value range is 0..99
                                1 - value range is 0..9
                                2 - value range is 0..49
                                3 - value range is 0..99

    4) -reset               resets score            
    
Runtime commands:
    1) start    starts the game
    2) stop     stops attempt and goes to start menu
    3) level    sets the value of the game level
    4) exit     exits from program in general


------------------------------------------------------
|           structure of the result table            |     
-----------+-----------+-------------+-------+-------+
| position | user_name | record_time | level | score |
------------------------------------------------------

Rules for ordering results in the table.
There are the following priority:
    1) level
    2) score
    3) record_time - uses only if values of level and score are same with other.

    * in one level possible only 5 positions
