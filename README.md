# rshell
The structure of the project coded here is essentially the composite pattern in full force. The classes are set as follows: We have a class Base that contains a single execute function to inherit, which is followed by 3 derived classes. These classes are named Commands, Andand, and Oror. Alongside these classes is a separate solitary classes named Processes, which is in charge of running over each command input by the user.

Commands contains its inherited execute function that utilizes execvp to run bash commands, a runtime variable that keeps track of whether it failed to properly execute, and a vector of strings for storing its specific command/parameters. Andand and Oror are used as connector classes representing the "&&" and "||" logic inputs. These contain Base pointers in order to determine the proper execution of the next command in line. If Andand's first command runs successfully, then it shall execute its second, whereas if Oror's first command runs successfully, its second command will not run, as per boolean logic.

Processes contains a vector of Base pointers that adds Command and connector objects alike so that it may execute each at a time, all while each objects itself determines how commands will be executed. First, project gets the input from the user and parses it into separate vectors of strings, which are used to create connector and command objects that are linked to one another and added to its vector. After that, it calls its own execute function that that runs over each Base object, which in turn execute themselves. The user may enter any number of commands until they choose to exit the shell with the "exit" command.

List of known bugs:
1.Occassionally if a command fails to execute, the user must enter exit twice to properly exit the shell
2.Any inclusion of connectors inside of double quotes will result in a vector range error
3.If a semicolon is attached to the beginning of a command such as in 
  "echo hello;echo hello"
  The program will throw a vector error
4. Some comment tests will result in vector errors, however the program can generally handle most types of comments
5. It is advised not to end command lines with connectors
