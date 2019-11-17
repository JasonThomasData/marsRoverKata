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
    # htmlInterfaceStrategy = HtmlInterface() # potential future extension
    - IO( cliInterfaceStrategy ) # handles all In and Out, tokenising inputs as lists of instructions from OS, formats results from Robot
    - Robot() # receives instructions, returns results
    - Planet() # is available for robot interaction

