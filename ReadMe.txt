T09-G12

GROUP MEMBERS:
Ana Catarina da Silva Oliveira
Marcos William Ferreira Pinto

PROGRAM DEVELOPMENT STATE:

The program opens in the main menu and have 4 options: rules, play, show records and exit.
The main menu and the rules screen have a special screen unsing both a txt file (TITLE.TXT and RULES.TXT). If any of those fail to open it will show instead a simples page using couts.
Like mentioned above we made an option so that the user can see a MAZE_XX_WINNER.TXT file in the game, and as the play it will ask for a maze number, it will verify the maze number and ask for a different number in case MAZE_XX_WINNER.TXT is not found. The user may also choose "0" to go to the main menu.
All the movement for the player is implemented, and if the movement requested by the user is invalid it will ask again.
The robots move after the player and only after all the robots finished moving the maze will be updated.
We added some breaks in the loop that makes the robots move to detect if the player lost or won and after the maze is printed this will be checked again.
If the player lost it will altomatically ask the player if he wants to play again, which sends him to the main menu.
If the player won his time to complete the maze will be displayed in seconds and he will be asked if he wants to save his time in the records (if the answer is no he will be asked if he wants to play again). If the answer is yes he will be asked for his name (or username if he so wishes).
The program will see if a MAZE_XX_WINNER.TXT exists, if not it will create one for the maze. If the maze exist it will update it (if player already has a time it will only
update it and not add a new entry ) and sort it (from lowest to longest time). Also his time will only be updated if it is lower than the previous time.
All the times are displayed in seconds and because of that we added a "s" after each time to clarify this to the user.

-In the main menu the user has the option to type "3" to show the time records.
-In any input if the player insert "control + z" the game will be closed.
-We used vectors (inside a struct) to store the gameplay information and in the start of each game they will be cleared to be able to store the information about the new game.
-Information about the gameplay is passed using a struct which contains 3 vectors: 
1. store the maze
2. store player position
3. store the robots (their position and their condition (if they are alive or destroyed) ).
-The maze display is updated only after a round (the player movement and the robots), we tought it would not be a clean design to have more than one maze display update before the user is asked to move again. (ask player - move robots - print the maze - check maze condition - end game or ask player for movement).
-Time will only be updated if his new time is better than the previous time recorded.

Overall we believe that most if not all features needed to be implemented were implemented and some features we though were a good addition were added. The game is functional.
 
MAIN DIFFICULTIES:

-Figuring out how to organize the game (all the functions that were needed) was difficult at first.
-It was hard to find the position of the robots, or to manage all the robots.
-To think a way to pass the map, player and robots information necessary for the rounds to take place.
-Think of a way for the game to change and keep updated all the information for the game to function properly.
-If the MAZE_XX_WINNER.TXT file already existed we had difficult recording a new time. This includes a new time all together or altering an existing player time, the main difficulty being sorting the times to save it in the right order.
