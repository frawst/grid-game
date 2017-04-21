# grid-game

## Design Philosophy

This is to be a text-graphics game run in command line windows, on either linux or windows machines.
The game is essentially a basic rogue-like dungeon crawler, utilizing randomized encounters to populate dungeon floors.
- See the 'rules.pdf' for a pen&paper rulebook for an inspirational version of this game

No further philosophy at this time, as this is mostly a learning experiment.

I would like to impliment some sort of end-game goal, however.

[CPP Format Guidelines](https://github.com/frawst/grid-game)

## Current Problems

- Display refreshing function (*There likely exists libraries for this, let's try to write our own*)
  - Ability to clear command window of contents and repopulate with desired contents
  - If possible, set the command window to specific resolution
    - FUTURE: Possibility of resolution scaling with variables, would require some dynamic rendering

- Consistency / Object Orientation
  - How can we keep track of player information?
    - Stats
    - Inventory
    - Condition
    - etc.
  - And keeping track of the map/player progress?
    - Location
    - Events @ location
