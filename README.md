# grid-game

## Design Philosophy

This is to be a text-graphics game run in command line windows, on either linux or windows machines.
The game is essentially a basic rogue-like dungeon crawler, utilizing randomized encounters to populate dungeon floors.
- See the 'rules.pdf' for a pen&paper rulebook for an inspirational version of this game
- To be written in purely object oriented format

No further philosophy at this time, as this is mostly a learning experiment.

I would like to impliment some sort of end-game goal, however.

[CPP Format Guidelines](https://github.com/frawst/grid-game)

## Current Problems

- Display refreshing function (*There likely exists libraries for this, let's try to write our own*)
  - Ability to clear command window of contents and repopulate with desired contents
  - If possible, set the command window to specific 'resolution' (Rows && Collumns)
    - FUTURE: Possibility of resolution scaling with variables, would require some dynamic rendering
    
- Graphics
  - Drawing the map
  - Moving the player
  - Displaying other relevant information, text on screen vs. command access
    - Use different display states for 'windows'?

- Consistency / Object Orientation
  - How can we keep track of player information?
    - Stats
    - Inventory
    - Condition
    - etc.
  - And keeping track of the map/player progress?
    - Location
    - Events @ location

- Handling command input
  - There is a bit of code currently there to handle a command once it's received
  - How to check user string input against available commands?
    - We CANNOT use string comparisons! Find an alternative.

- Handling general functionality
  - When player steps into a room, what happens?
  - When a player uses an item?
  - Misc. functionality, update this as considerations arise

## MISC

Feel free to modify this readme as project progresses.
