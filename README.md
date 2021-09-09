# Timed Mini Shell

The mini shell should be able to read a set of commands, by standard input, execute the command, and when the command execution is finished it should print the time (in seconds) of execution and the return code of the program.

Assignment 1 of Operating System Fundamentals.

## Running the project

- Compiling the program:
```bash
    make comp
```

- Executing the project:
```bash
    make exec
```

- Compiling and executing the program:
```bash
    make run
```

- Executing with file inputs and redirecting the output to a file:
```bash
    make run-file
```

## Examples

### Example 1

** Input: **
```bash
/bin/sleep 1
/bin/sleep 1.1
/bin/eunaoexisto 123
```

** Output: **
```bash
> Demorou 1.0 segundos, retornou 0
> Demorou 1.1 segundos, retornou 0
> Erro: No such file or directory
> Demorou 0.0 segundos, retornou 2
>> O tempo total foi de 2.1 segundos
```

### Example 2

** Input: **
```bash
/bin/sleep 1.5
/bin/true ign
/bin/false 222
/bin/uname -s
/bin/sleep 1
```

** Output: **
```bash
> Demorou 1.5 segundos, retornou 0
> Demorou 0.0 segundos, retornou 0
> Demorou 0.0 segundos, retornou 1
Linux
> Demorou 0.0 segundos, retornou 0
> Demorou 1.0 segundos, retornou 0
>> O tempo total foi de 2.5 segundos
```