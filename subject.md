# Minishell

## 📘 Project Overview

**Minishell** is an advanced C project from the 42 curriculum that challenges you to create your own simple shell. This project provides extensive knowledge about processes, file descriptors, and system programming while recreating the fundamental behaviors of bash.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Mandatory Requirements](#mandatory-requirements)
- [Built-in Commands](#built-in-commands)
- [Parsing Rules](#parsing-rules)
- [Signal Handling](#signal-handling)
- [Bonus Part](#bonus-part)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Understand process creation and management using `fork()`, `execve()`, and `wait()`
- Master file descriptor manipulation and redirection
- Learn signal handling in interactive programs
- Implement command parsing and environment variable expansion
- Build a functional shell that mimics bash behavior

---

## General Requirements

- Written in **C**, following the **42 Norm**
- No memory leaks or undefined behavior
- Must compile with `-Wall -Wextra -Werror`
- Global variables are **forbidden** except for one signal indicator
- Submit only necessary files
- Use `libft` if needed (copy sources into `libft/` folder)

### Allowed Functions

```
readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4,
signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat,
unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty,
ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
tgoto, tputs
```

### Makefile

Must include rules:
- `$(NAME)`, `all`, `clean`, `fclean`, `re`
- Bonus rule if implementing bonus features

---

## Mandatory Requirements

### Core Shell Features

- **Display a prompt** when waiting for new commands
- **Working history** using readline functions
- **Executable search** based on PATH variable or absolute/relative paths
- **One global variable** maximum (only for signal number storage)

### Parsing and Quoting

- **Single quotes (`'`)**: Prevent interpretation of all metacharacters
- **Double quotes (`"`)**: Prevent interpretation except for `$` (dollar sign)
- **No support** for unclosed quotes or special characters like `\` or `;`

### Redirections

- **Input redirection (`<`)**: Redirect input from file
- **Output redirection (`>`)**: Redirect output to file (overwrite)
- **Append redirection (`>>`)**: Redirect output to file (append)
- **Here document (`<<`)**: Read input until delimiter (no history update required)

### Pipes

- **Pipe (`|`)**: Connect output of one command to input of next command
- Support for multiple pipes in a single command line

### Environment Variables

- **Variable expansion (`$VAR`)**: Expand environment variables to their values
- **Exit status (`$?`)**: Expand to exit status of last executed foreground pipeline
- Variables should expand within double quotes but not single quotes

---

## Built-in Commands

Your shell must implement these built-in commands:

- **`echo`** with option `-n`
- **`cd`** with relative or absolute path only
- **`pwd`** with no options
- **`export`** with no options
- **`unset`** with no options
- **`env`** with no options or arguments
- **`exit`** with no options

---

## Parsing Rules

### Quote Handling
```bash
echo 'Hello $USER'     # Prints: Hello $USER
echo "Hello $USER"     # Prints: Hello [username]
echo Hello' '$USER     # Prints: Hello [username]
```

### Variable Expansion
```bash
echo $HOME             # Expands to home directory
echo $?                # Prints last command exit status
echo '$HOME'           # Prints: $HOME (no expansion in single quotes)
```

### Redirection Examples
```bash
ls > output.txt        # Redirect stdout to file
cat < input.txt        # Redirect stdin from file
echo "text" >> log.txt # Append to file
cat << EOF             # Here document until "EOF"
```

---

## Signal Handling

### Interactive Mode Behavior

- **`ctrl-C`**: Display new prompt on new line (do not exit)
- **`ctrl-D`**: Exit the shell cleanly
- **`ctrl-\`**: Do nothing (ignore)

### Implementation Notes

- Use only **one global variable** to store signal numbers
- Signal handler must not access main data structures
- Follow bash behavior exactly for signal handling

---

## Bonus Part

> **Note**: Bonus is only evaluated if mandatory part is perfect

Additional features to implement:

### Logical Operators
- **`&&`**: Execute second command only if first succeeds
- **`||`**: Execute second command only if first fails
- **Parentheses**: For grouping and priority control

### Wildcards
- **`*`**: Expand to matching files in current working directory

### Bonus Examples
```bash
ls && echo "Success"           # Echo only if ls succeeds
false || echo "Failed"         # Echo only if false fails
(echo a && echo b) || echo c   # Grouping with parentheses
ls *.c                         # Wildcard expansion
```

---

## Submission Guidelines

- Submit to assigned Git repository
- Only repository contents will be evaluated
- Evaluation includes peer reviews and automated testing
- Any norm error or runtime error stops evaluation immediately

---

## Testing Strategy

### Recommended Test Cases

1. **Basic Commands**
   ```bash
   /bin/ls
   pwd
   echo "Hello World"
   ```

2. **Built-ins**
   ```bash
   cd /tmp
   export TEST=value
   env | grep TEST
   exit
   ```

3. **Redirections**
   ```bash
   echo "test" > file.txt
   cat < file.txt
   ls >> output.log
   ```

4. **Pipes**
   ```bash
   ls | grep .c
   cat file.txt | head -5 | tail -2
   ```

5. **Variable Expansion**
   ```bash
   echo $HOME
   echo $?
   echo '$HOME'
   echo "$HOME"
   ```

6. **Signal Handling**
   - Test ctrl-C, ctrl-D, ctrl-\ in various scenarios
   - Test with running and non-running commands

---

## Implementation Tips

### Memory Management
- Free all allocated memory, especially from readline
- Handle partial command failures gracefully
- Be careful with pipe and fork cleanup

### Process Management
- Properly wait for child processes
- Handle process groups for signal management
- Clean up file descriptors in child processes

### Error Handling
- Follow bash error messages and exit codes
- Handle system call failures appropriately
- Provide meaningful error messages

---

## Common Pitfalls

- **Signal handling**: Don't access main data structures from signal handlers
- **Memory leaks**: Readline may leak, but your code must not
- **Zombie processes**: Always wait for child processes
- **File descriptor leaks**: Close all opened file descriptors
- **PATH handling**: Handle both absolute/relative paths and PATH search

---

## Final Note

Minishell is one of the most challenging projects in the 42 curriculum. It requires deep understanding of:
- UNIX system calls
- Process management
- File descriptor manipulation
- Signal handling
- String parsing and manipulation

Take bash as your reference for any undefined behavior. When in doubt, test your implementation against bash and ensure identical behavior.

---
