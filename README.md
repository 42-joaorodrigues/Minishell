# Minishell

![42 Badge](https://img.shields.io/badge/42-Project-blue) ![C Badge](https://img.shields.io/badge/Language-C-brightgreen) ![Status Badge](https://img.shields.io/badge/Status-Completed-success) ![Score Badge](https://img.shields.io/badge/Score-100%2F100-success) 

## What I Learned

Through this advanced systems programming project at 42 School, I developed crucial low-level programming skills and system administration knowledge:

- **Process management** - Mastered fork(), execve(), wait() and process lifecycle control
- **File descriptor manipulation** - Implemented complex I/O redirection and pipe operations  
- **Signal handling** - Built robust signal management for interactive shell behavior
- **Command parsing** - Developed sophisticated lexical analysis and token parsing systems
- **Environment variable expansion** - Implemented bash-compatible variable substitution
- **Memory management** - Handled complex memory allocation patterns with zero leaks
- **System call expertise** - Deep understanding of UNIX system calls and their behavior
- **Inter-process communication** - Built pipe chains for command pipeline execution
- **Error handling** - Implemented comprehensive error checking following bash standards
- **Concurrent programming** - Managed multiple processes and proper cleanup procedures

This project significantly enhanced my understanding of operating systems, shell internals, and systems programming fundamentals essential for any backend development role.

## About the Project

**Minishell** (nicknamed "favela_shell" in our implementation) is a simplified shell interpreter that recreates core bash functionality. It demonstrates mastery of process control, file operations, and system programming by implementing:

- Interactive command-line interface with readline support
- Built-in commands (echo, cd, pwd, export, unset, env, exit)
- I/O redirection and pipe operations
- Environment variable expansion and management
- Signal handling for interactive use
- Command parsing with quote handling

## Implementation Details

### Architecture Overview

Our implementation follows a modular design with clear separation of concerns:

```
minishell/
├── src/
│   ├── builtin/     # Built-in command implementations
│   ├── command/     # Command structure and creation
│   ├── env/         # Environment variable management
│   ├── exec/        # Process execution and PATH resolution
│   ├── expand/      # Variable expansion and string processing
│   ├── main/        # Main loop and input handling
│   ├── sig/         # Signal handling
│   ├── status/      # Exit status management
│   └── token/       # Lexical analysis and parsing
└── lib/             # Custom utility library
```

### Core Components

#### Command Parsing Engine
```c
typedef struct s_command
{
    char                *cmd;        // Command name
    char                **args;      // Command arguments
    int                 fd_in;       // Input file descriptor
    int                 fd_out;      // Output file descriptor
    int                 pid;         // Process ID
    int                 exit;        // Exit status
    struct s_command    *next;       // Next command in pipeline
} t_command;
```

#### Token System
Sophisticated lexical analyzer handling:
- **Quote parsing** - Single and double quote processing
- **Redirection operators** - `<`, `>`, `>>`, `<<` 
- **Pipe operators** - `|` for command chaining
- **Variable expansion** - `$VAR` and `$?` substitution

### Built-in Commands

| Command | Functionality | Implementation Notes |
|---------|---------------|---------------------|
| `echo` | Print arguments | Supports `-n` flag |
| `cd` | Change directory | Handles relative/absolute paths |
| `pwd` | Print working directory | No options required |
| `export` | Set environment variables | Variable assignment and display |
| `unset` | Remove environment variables | Multiple variable support |
| `env` | Display environment | No arguments/options |
| `exit` | Exit shell | Numeric exit code support |

### Advanced Features

#### I/O Redirection
- **Input redirection (`<`)** - Read from file
- **Output redirection (`>`)** - Write to file (overwrite)
- **Append redirection (`>>`)** - Write to file (append)
- **Here document (`<<`)** - Multi-line input with delimiter

#### Process Management
```bash
# Pipeline execution
ls -la | grep .c | wc -l

# Signal management
# Ctrl-C: New prompt
# Ctrl-D: Exit shell  
# Ctrl-\: No action
```

#### Environment Variable Expansion
```bash
echo $HOME                    # Expands to home directory
echo $?                       # Shows last command exit status
echo 'Hello $USER'            # No expansion in single quotes
echo "Hello $USER"            # Expansion in double quotes
```

## Usage

### Compilation
```bash
# Build the project
make

# Clean object files
make clean

# Remove all generated files
make fclean

# Rebuild everything
make re
```

### Running the Shell
```bash
# Standard mode
./minishell

# Color mode (enhanced prompt)
./minishell colour
```

### Example Session
```bash
favela_shell > echo "Welcome to favela_shell!"
Welcome to favela_shell!

favela_shell > export MY_VAR="Hello World"
favela_shell > echo $MY_VAR
Hello World

favela_shell > ls -la | grep minishell
-rwxr-xr-x  1 user  staff  12345 Jul 16 10:30 minishell

favela_shell > cat < input.txt > output.txt
favela_shell > echo $?
0

favela_shell > exit
```

## Technical Challenges Overcome

### Memory Management
- **Complex cleanup patterns** - Proper deallocation across process boundaries
- **Readline integration** - Managing readline's internal memory allocation
- **Command structure cleanup** - Recursive freeing of nested command pipelines
- **Environment duplication** - Safe copying and modification of environment arrays

### Process Control
- **Zombie prevention** - Proper wait() implementation for all child processes
- **File descriptor management** - Careful cleanup to prevent descriptor leaks
- **Pipeline execution** - Coordinating multiple processes with proper pipe setup
- **Signal propagation** - Ensuring signals reach appropriate process groups

### Parsing Complexity
- **Quote state management** - Tracking nested quote contexts during tokenization
- **Operator precedence** - Proper handling of redirection vs pipe operators
- **Variable expansion timing** - Correct expansion order within quoted contexts
- **Syntax validation** - Comprehensive error checking for malformed commands

### System Integration
- **PATH resolution** - Efficient executable search across PATH directories
- **Environment inheritance** - Proper propagation of environment to child processes
- **Terminal control** - Managing terminal settings for interactive use
- **Cross-platform compatibility** - Handling system-specific signal behaviors

## Testing Strategy

Our comprehensive testing approach included:

### Unit Testing
- Individual function validation
- Edge case handling verification
- Memory leak detection with valgrind
- Signal behavior validation

### Integration Testing
- Complex command pipeline execution
- Multiple redirection combinations
- Environment variable manipulation
- Built-in command interaction

### Compatibility Testing
- Bash behavior comparison
- POSIX compliance verification
- Error message consistency
- Exit code accuracy

## Performance Optimizations

- **Efficient tokenization** - Single-pass parsing with minimal memory allocation
- **Smart path caching** - Reduced filesystem access for executable lookup
- **Optimized string operations** - Custom string library tuned for shell operations
- **Memory pool management** - Reduced fragmentation in command structure allocation

## Collaboration

This project was completed as part of the 42 School curriculum in collaboration with [Vigmar Gabriel](https://www.linkedin.com/in/vigmar-gabriel-de-oliveira-pinheiro-54590368/). 

We successfully implemented all mandatory requirements without pursuing the bonus features, focusing on creating a robust, well-tested core implementation that perfectly matches bash behavior.

## Architecture Highlights

### Custom Library Integration
Built on top of a comprehensive custom C library featuring:
- **Memory management utilities** - Safe allocation/deallocation patterns
- **String manipulation suite** - Optimized string operations
- **Linked list implementation** - Dynamic data structure support
- **Error handling framework** - Consistent error reporting
- **Character classification** - Enhanced ctype functionality

### Modular Design Benefits
- **Maintainable codebase** - Clear separation of concerns
- **Testable components** - Individual module validation
- **Extensible architecture** - Easy feature addition
- **Reusable utilities** - Library functions across modules

This project demonstrates our proficiency in systems programming, algorithm implementation, and collaborative software development within the demanding 42 curriculum framework.

## License

This project is licensed under the [MIT License](LICENSE).
