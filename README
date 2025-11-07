# ft_printf

This project is a project in the beginning of 42 common core, the objective was to recreate a little printf that will serve in all other project (we are not authorized to use printf).

I try to respect the original printf that have wrappers that call a generic function "ft_vdprintf".

## ⚙️ Usage

### ft_printf

We can call ft_printf and it will work like the original:

```c
ft_printf(char *fmt, ...)
```

### ft_dprintf

We can also call ft_dprintf that work like dprintf, it allow us to print in a specific file descriptor (useful for error):

```c
ft_dprintf(int fd, char *fmr, ...)
```
## ⚠️ Supported formats

Only the most useful formats are implemented:

|Specifier  |Description                |
|-----------|---------------------------|
|%s         |Print a string `(char *)`  |
|%i & %d    |Print an int value         |
|%x & %X    |Print an int value in hexadecimal (lowercase / uppercase)  |
|%p         |Print a pointer address    |
|%c         |Print a char               |

## 🚫 Null implementation
Printf have different implementation on NULL value for %s and %p I chose this one:

|Specifier  |Value  |Null value|
|-----------|-------|----------|
|%s         |NULL   |(null)    |
|%p         |NULL   |(nil)     |

---

## 💭 Learned here

- Variadic functions (`va_start`, `va_arg`, `va_end`)
- How printf work (even if i didn't implement buffering of printf)
- Debugging without printf but with ✨ft_printf