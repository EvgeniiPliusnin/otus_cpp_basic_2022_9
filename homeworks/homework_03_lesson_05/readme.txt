**************************************************************************************************
                                    GAME GUESS A NUMBER
**************************************************************************************************
Functionality of program:
    - This is a simple CLI game in which you are asked to guess a number.
    - Program calculate your personal score by count attempt quantity.
    - There are 3 levels - max value of a number (set by command in terminal, default is 1)
        and also possible manualy set max value of a number for guessing


**************************************************************************************************
                                            SCORE
**************************************************************************************************
How to calculate score for user:
    high_score = 500 * level_scale / attempt_quantity

    level_scale depends on max_value:
        - 1 -> 0..9
        - 2 -> 10..49
        - 3 -> 50..99
        - if max_value >= 100
            - (3 + k), then k = max_value % 100 / 10


----------------------------------------------------
|           structure of the result table          |     
+----------+-----------+-------------+-------------+
| position | user_name | record_time |  high_score |
----------------------------------------------------

Rules for ordering results in the table.
There are the following priority for position:
    1) high_score
    2) record_time (if the scores are equal)
    *possible only 5 positions


**************************************************************************************************
                                            COMMANDS
**************************************************************************************************
CLI arguments for start program:
    -max [INTEGER]      set max value of number for guess. Don't use this argument with arg -level.
                                by default set 100.

    -level [INTEGER]    can be follows values: 1, 2, 3 (by default set 1) 
                                1 - value range is 0..9
                                2 - value range is 0..49
                                3 - value range is 0..99
                                [Automatically set to 0 - if the value of arg -max is set]

    -table               shows the score table plus settings and exits the program                            
    -reset               resets score table and returns the settings to initial state
    -help                show help message      
    
