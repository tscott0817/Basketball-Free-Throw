# Free Throw Basketball Game
This program is a small basketball game created using C++, openGL, and freeGLUT. The goal 
is to make as many shots as you can until the time runs out. It also asks the user for their name and keeps track of points in a 
'high-scores' screen. 

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