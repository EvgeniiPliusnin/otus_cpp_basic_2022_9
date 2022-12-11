**************************************************************************************************
                                    GAME GUESS A NUMBER
**************************************************************************************************
Functionality of program:
    This is a simple CLI game in which you are asked to guess a number.

----------------------------------------------------
|           structure of the result table          |     
+----------+-----------+-------------+-------------+
| position | user_name | record_time | total_score |
----------------------------------------------------

Rules for ordering results in the table.
There are the following priority:
    1) total_score
    2) record_time (if the scores are equal)
    *possible only 5 positions


**************************************************************************************************
                                            SCORE
**************************************************************************************************
How to calculate score for user:
    The total_score in the game is calculated from the sum of each score_item.
    a) total_score = sum(item_score_1, ..., item_score_N)
    b) item_score = 1000 * level_scale / attempt_quantity


**************************************************************************************************
                                            COMMANDS
**************************************************************************************************
CLI arguments for start program:
    -max [INTEGER]       set max value of number for guess. Don't use this argument with arg -level.
                                by default set 100.
    -table               shows the score table plus settings and exits the program
    -level [INTEGER]     can be follows values: 1, 2, 3 (by default set 1) 
                                1 - value range is 0..9
                                2 - value range is 0..49
                                3 - value range is 0..99
                                [Automatically set to 0 - if the value of arg -max is set]

    -reset               resets score table and returns the settings to initial state
    -help                show help message      
    
Runtime CLI commands:
    -start      starts the game
    -stop       stops attempt and goes to start menu
    -table      shows the score table and goes to start menu
    -level      sets the value of the game level
    -exit       exits from program
