#### (Original) domain model

![domain model](MarsRover_DomainModel.png)

- I was tempted to model this as the planet as a POD, with no methods of its own, and for the rover
  to know about the planet. It seems that using Tell Don't Ask means it makes sense for the planet
  to have certain abilities - like, "tell me if there's an obstacle here".

Diagram made with draw.io

### November 18, 2019

This design should be understood as:
- A robot is intelligent, has agency and owns its own attributes, including its position on the planet
- A planet has its own attributes, not including the robot
- The robot can perceive things about the planet, but doing so requires the robot to tell the planet to reveal its attributes. EG. "Tell me, is there an obstacle at x,y"

This implementation is half way between two extremes:
- An intelligent robot perceives the planet, and owns its perceptions, meaning the planet is merely a POD with no responsibilities
- A planet owns the robot that sits upon it, and the robot can be moved like a windup toy. An invisible hand moves the robot

The above concepts belong in the domain of the program, which can be though of as the functional core. Interactions with the OS and users will be contained in a shell, of sorts.

To start with, the program can consist of a terminal interface. The program could be extended to allow for an HTML server. Both implementations require a shell for listing to inputs.

The implementation invisaged is:

- Main()
    - cliInterfaceStrategy = CliInterface() # listens for CLI inputs, returns outputs to OS/human user
    - htmlInterfaceStrategy = HtmlInterface() # potential future extension
    - IO( cliInterfaceStrategy ) # handles all In and Out, tokenising inputs as lists of instructions from OS, formats results from Robot
    - Robot() # receives instructions, returns results
    - Planet() # is available for robot interaction

### January 15, 2020

Today, I made the IO module handle most, but not all logic. There is a small amount of IO stuff in the main file, for catching uncaught errors, and I think this is OK.

I decided that the planet should have a multidimensional array to represent its surface, so that the robot could say "tell me what's at x,y". The alternative is to have the surface dimensions represented as integers, and then have an array of obstacle coordinates. This would make sense for a small array of obstacles, but as the array grows then the complexity of finding coordinates would also grow and that grow at O(n), which is undesirable. If the obstacle coordinates were ordered according to their integer coordinates, you could increase efficiency by putting those in a hashmap, reducing the complexity to O(1). However, finding an element where you know the index in a multidimensional array is still O(1), so there's no reason to not use an array.

### January, 24, 2020

Today I learned it's better to have validation logic inside the constructors of classes/structs, rather than in other modules. It's best to not allow something to be constructed and used elsewhere if it's not valid. I will move as much validation logic into the constructors of objects as possible.
