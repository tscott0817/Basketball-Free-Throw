# Free Throw Basketball Game
This program is a small basketball game created using only C++, openGL, and GLUT. The goal of the game 
is to make as many shots as you can until the time runs out. I mainly use concepts from modules 2 and 4 
with big ones being I/O streams, has-a relationships, and graphics/event handling as a whole. The 
game asks for a username to be typed in which is then added, along with the player's score, 
to a file and further displayed in a 'high-scores' screen. The main "component" classes (gameObjects, balls, inputs, scores) work in a modular 
fashion with one another to produce specific behaviors and effects in the main program. By effect
of being a game it was needed to include keyboard/mouse inputs, drawing/display of 2d objects, and 
timers.

![Court](https://i.imgur.com/28KJRVC.png)

## How To Play
#### Start Menu
    - Type in your username and presss ENTER.
#### Main Menu
    - PLAY GAME
    - CHANGE LEVEL: Nothing for now.
    - HIGH SCORES: Display of users and scores. Press ESC to leave screen.
    - EXIT
#### Game Screen
    - Hold left mouse button down to charge. Longer hold = stronger throw.
    - Each successful shot is worth 1 point. Score shown in top left corner.
    - Once out of basketballs, left mouse click again to refill holder.
    - Time remaining in the top right corner.
    - After time ends press ENTER to reset or ESC to quit.
## Known Issues/Bugs
    - In inputManager.h under the addScoresToFile method. Some troubles with filepath to .csv, but
      think it's resolved.
    - In the high-scores screen. Only displays correctly once game closed and reopened.
    - If the ball velocity is set too high, it may pass through the hoop without scoring a point. Think
      this is due to interplay with the timer function. 